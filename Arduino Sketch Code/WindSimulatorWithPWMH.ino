/*
25Khz PWM for PC Case PWM Fan control by iRacing Wind Simulator
uses PWM.h Library found here
https://code.google.com/archive/p/arduino-pwm-frequency-library/downloads or here https://github.com/RCS101/PWM
Copyright (c) 2019 Chris Venter
*/

#include <PWM.h>

int PWMSignalPin = 3;
int32_t frequency = 25000; // desired frequency in Hertz.most PWN PC fans run at 25Khz
int currVal = 1;
void setup() {
  Serial.begin(115200); // initialize serialport
  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe(); 
  bool success = SetPinFrequencySafe(PWMSignalPin, frequency);
  //if the pin frequency was set successfully, turn pin 13 on (The UNO LED)
  if(success) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    pwmWrite(PWMSignalPin, 0);
  }
}

void loop()
{
  while (Serial.available() > 0) { // if there's any serial available, read it: 
    int PWMVal = Serial.parseInt(); // look for the next valid integer in the serial stream 
    if (Serial.read() == '\n') { // look for the newline. That's the end of the character stream 
      PWMVal = constrain(PWMVal, 0, 255); // ensure the values stay between t0 - 255       
      pwmWrite(PWMSignalPin, PWMVal);
    } 
  }
}
