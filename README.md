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


## Future Updates
