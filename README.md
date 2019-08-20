# iRacing Wind Simulator

---

The following provides plans for how you can make a very low cost simple Wind Simulator for iRacing.
I designed this to use only easy to get parts with minimal coding and soldering needed.

This design uses PWM Controlled PC cooling Fans. It only needs a low cost Arduino to drive it. No moto Shield or Monster moto driver
is required because of the use of PWM controlled fans.

To use this design you need to adjust the wind output to be directional in order for the effect to be felt.
I used a design from Thingiverse that I 3D printed

---
#### You need the following items to build this project

1. Arduino Uno https://www.amazon.com/HiLetgo-ATmega328P-Development-Compatible-Microcontroller/dp/B01AR7YJ3O
2. 12v Power Supply of at least 1.5 amps. You can use an old PC power supply but its overkill. https://www.amazon.com/100v-240v-Transformers-Interface-5-5x2-5mm-Suitable/dp/B0793SDTJK
3. 2x 120mm PWM 4 Pin PC Cooling fans https://www.amazon.com/Bgears-120mm-High-Performance-Technology/dp/B00GX3MAGU/
4. A terminal block https://www.amazon.com/Morris-22052-20A-Terminal-Block/dp/B005BGC3S0
5. Some connecting wire https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78

##### Nice to have

1. Voltmeter
2. Soldering Iron
3. 3D Printer

##### The 3D printed parts are as follows:

- [ ] Fan Shroud: https://www.thingiverse.com/thing:2884277 or http://www.thingiverse.com/thing:3495351 or 
http://www.thingiverse.com/thing:408156
- [ ] Arduino Uno Large Case https://www.thingiverse.com/thing:1097607
- [ ] GoPro Mounts for mounting to rig https://www.thingiverse.com/thing:1779794

---

#### Instructions

##### Arduino sketch upload instructions

1. Run the arduino integrated development environment software (Download it here https://www.arduino.cc/en/main/software)
2. Plug in your arduino uno usb cable into your PC
3. Download the Fast PWM library, written by Sam Knight here https://github.com/RCS101/PWM
4. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library. At the top of the drop down list, select the option to "Add .ZIP Library''. You will be prompted to select the library you would like to add. Navigate to the .zip file file you downloaded in step 3 above. (You can read more about doing this here https://www.arduino.cc/en/guide/libraries
3. Download the sketch file in the Arduino Sketch Code folder in this git project here: 
5. Open the sketch file in the Arduino IDE.
6. Compile the sketch by pressing the tick in the circle button at the top.
7. Upload the sketch to your arduino my pressing the right arrow in the circle button 
8. You Arduino should now have the software it needs to drive the PWM PC Fans
9. On the bottom right of the IDE software will tell you the COM port your arduino is connected to. It will say something like COM4. Take a note of this. You will need it later.
10. Unplug the Arduino and get ready for wiring

##### Arduino and fan wiring instructions

![Wiring Digram](https://github.com/Crypto69/Wind-Simulator-Project/blob/master/Images/Wiring.png)

0. Ensure Arduino and your 12v Power supply are not plugged in at this stage
1. Detach plug from your 12vDC Power supply. Plug it in and use a voltmeter to find out which end is positive. Be sure not to touch the ends of the exposed wire risking shock or shorting the power supply (Sometimes they have a wire with a white stripe that is 
usually the positive wire)
2. Connect the negative end of the DC power supply to the arduino ground pin. (as per wiring diagram step 2)
3. Connect the positive wire from the power supply to the terminal block. (as per wiring diagram step 3)
4. Connect the Arduino ground pin next to the power supply negative you just wired to the terminal block (as per wiring diagram step 4)
5. Connect a wire from pin 3 on the Arduino Uno to the terminal block (as per wiring diagram step 5)
6. Remove the PWM signal wire (usually blue if colored) from one of the fans and connect it to the other side of the terminal block where pin 3 from the arduino is connected (as per wiring diagram  step 6)
7. Remove the negative wire or ground wire (usually black if colored) on the PWM PC Fan connector and connect this into the terminal black on the opposite side of where you connected the ground/negative from the arduino into the terminal block ((as per wiring diagram  step 7)
8. Remove the positive wire (usually red if colored) on the PWM PC Fan connector and connect this into the terminal black on the opposite side of where you connected the positive from the 12v power supply into the terminal block ((as per wiring diagram  step 8)

##### iRacing Wind Simulator software
1. Download the Wind Simulator software setup file from here:
2. This is a .Net application that connects to the iRacing Telemetry output. All this app does is read the speed many times a second and pass a value between 0 and 255 to the arduino. 255 being top speed and 0 being stopped. The software self learns the top speed as your drive the car. So initially the fans may spin quickly for the first lap but will adjust once it works out your speed range.
3. Install the application by running setup.exe
4. Run the application. You will be required to select the com port your arduino is running on. You can find this when your run the arduino ide application. On the bottom right it tells you your comm port. You wont need to do this again unless you change the COM port.
5. Click the start button and minimise the app. you wont need it again. You can leave it up and it will show the speed of the car and the value being sent to the arduino.
6. Start iRacing and drive. Your fans will spin up learn your top speed self adjust and then settle down.

If you got this far then well done !
You may want to make your solution look more professional. You can 3D print the laminar flow files, cases and gopro mounts.
![3D  Printed Parts](https://github.com/Crypto69/Wind-Simulator-Project/blob/master/Images/3DPrinted.png)

The links to the STL files for 3D printing were listed above.

