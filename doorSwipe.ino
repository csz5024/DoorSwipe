/*
 *  doorSwipe 2018
 *  Electric Strike activated by RFID
 *  
 *  Written by: Casey Zduniak
 */

#include <AddicoreRFID.h>
#include <RH_ASK.h>
#include <SPI.h>

#define uchar unsigned char
#define uint unsigned int

AddicoreRFID doorSwipe; //new RFID object

const int enable = 10;
const int reset = 5;

const int red = 4;
const int green = 3;
const int blue = 2;

const int latch = 6;

#define MAX_LEN 16

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  //if(!driver.init())
  //  Serial.println("init failed");

  SPI.begin();

  pinMode(enable, OUTPUT);
  digitalWrite(enable, LOW);
  pinMode(reset, OUTPUT);
  digitalWrite(reset, HIGH);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(blue, HIGH);

  pinMode(latch, OUTPUT);

  doorSwipe.AddicoreRFID_Init();

}

void loop() {
  
  uchar checksum1;
  uchar status;
  uchar str[MAX_LEN];
  String mytag = "";
  boolean check = false;

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);

  str[1] = 0x4400;

  //stores the brand of the tag in mytag
  status = doorSwipe.AddicoreRFID_Request(PICC_REQIDL, str);
  if (status == MI_OK) {

    uint tagType = str[0] << 8;
    tagType = tagType + str[1];

    switch (tagType) {
      case 0x4400:
        mytag = "Mifare UltraLight";
        break;
      case 0x400:
        //actual brand of the registered tag
        mytag = "Mifare One (S50)";
        break;
      case 0x200:
        mytag = "Mifare One (S70)";
        break;
      case 0x800:
        mytag = "Mifare Pro (X)";
        break;
      case 0x4403:
        mytag = "Mifare DESFire";
        break;
      default:
        mytag = "Unknown";
        break;
    }
  }

  //Anti-collision, return tag serial number 4 bytes
  status = doorSwipe.AddicoreRFID_Anticoll(str);
  if (status == MI_OK)
  {
    //position 0, 1, 2, 3 are the tags numbers
    //position 4 is the tag's read checksum
    //calculate checksum for potential loss or error in data
    checksum1 = str[0] ^ str[1] ^ str[2] ^ str[3];
    if (str[4] == checksum1) {
      check = true;
    }

    // Checks every bit of data contained on the tag (given correct frequency)
    if (str[0] == 225 && str[1] == 121 && str[2] == 55 && str[3] == 64 && check == true && mytag == "Mifare One (S50)")                     //You can change this to the first byte of your tag by finding the card's ID through the Serial Monitor
    {
      digitalWrite(blue, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(latch, HIGH);

      //old code from v1.1
      //driver.send((uint8_t *)msg, strlen(msg));
      //driver.waitPacketSent();

      //tweak the time that it is held open
      //might add an event listener here in the future
      //based on a door stopper or something
      delay(5000);

      digitalWrite(blue, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(latch, LOW);
    }
    else {
      digitalWrite(blue, LOW);
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
      delay(500);
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
      delay(500);
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
      delay(500);
      digitalWrite(blue, HIGH);
    }

    delay(1000);
  }
  doorSwipe.AddicoreRFID_Halt();      //Command tag into hibernation
}
