# DoorSwipe
Repo for Arduino based IoT project version 1.3.

Apply 12VDC power supply of >6W. I used an old 40W laptop charger.


## File Directory
 - Gerber_doorswipepcb_20190104145725.zip
   - Contains Gerber files for custom printed PCB
     - C1 is implemented as an SMD package capacitor, but ceramic disk will fit just fine as well
 
 - Prototype.jpg
   - Image of working prototype. Heatsinks are just pieces of scrap metal I found, stays warm to the touch. Voltage regulator is shown to      the right of the MOSFET. .1uF Ceramic Disk Capacitor used to compensate for power ripples.
   
 - Prototype.mp4
   - Video of prototype in action. Default code sets unlock period to 5 seconds.
   
 - doorSwipe.ino
   - Source code for Arduino Nano. Comments included as seen fit.
   
 - doorSwipe_v1.2.jpg
   - Screenshot of v1.2 schematic implemented with a Relay instead of F630 MOSFET.
   
 - doorSwipe_v1.3.pdf
   - PDF of v1.3 schematic


## Notes
**Power Consumption:**
 - The status LED, RFID reader, and Nano add up to about 0.186W on standby
 - About 4.2-4.5W under full load, mostly due to Electric Strike
 - due to it only being under full load for 5 seconds only a couple times per day, I estimated a net of .3W power consumption.
 **Cost:** 7.2Wh -> $0.37 to run per year (based on my cost of electricity)


## Future Updates
 - Plan to add 
