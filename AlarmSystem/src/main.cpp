// COMP-10184 – Mohawk College 
// PIR Sensor Test Application 
// Turn on the blue LED with motion is detected. 

/// I , Alexei Ougriniouk, Student number 000776331, certify this is my own work 
/// STAGE REACHED = 3
 
#include <Arduino.h> 
 
// digital input pin definitions 
#define PIN_PIR D5 
#define PIN_BUTTON D6 

int  sevensecdelay = 7500;

int quartersec = 250;

 
 
// ************************************************************* 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure the LED output 
  pinMode(LED_BUILTIN, OUTPUT); 
 
  // PIR sensor is an INPUT 
  pinMode(PIN_PIR, INPUT); 
 
  // Button is an INPUT 
  pinMode(PIN_BUTTON, INPUT_PULLUP); 
} 
 
// ************************************************************* 
void loop() { 
  bool bPIR; 
 
  // read PIR sensor (true = Motion detected!).  As long as there 
  // is motion, this signal will be true.  About 2.5 seconds after  
  // motion stops, the PIR signal will become false. 
  bPIR = digitalRead(PIN_PIR); 

  /// STAGE 2 : Light turns either on or off every quarter second 
  digitalWrite(LED_BUILTIN, bPIR); 
  // wait quarter second 
  delay(quartersec); 
 
  // turn the LED OFF 
  digitalWrite(LED_BUILTIN, !bPIR); 
  // wait quarter second
  delay(quartersec); 

  digitalWrite(LED_BUILTIN, bPIR); 
  // wait quarter second 
  delay(quartersec); 
 
  // turn the LED OFF 
  digitalWrite(LED_BUILTIN, !bPIR); 
  // wait quarter second
  delay(quartersec); 
  digitalWrite(LED_BUILTIN, bPIR); 

  ///this is stage 1  7500 ms = 7.5s , 7.5 + 2.5s = 10s 
  delay(sevensecdelay);
  
 
  // send the PIR signal directly to the LED 
  // but invert it because true = LED off! 
  digitalWrite(LED_BUILTIN, !bPIR); 
  /// Stage 3 , this is an endless loop , in theory it should 
  while(1)                    
  {
    digitalWrite(LED_BUILTIN, bPIR);
  }
} 