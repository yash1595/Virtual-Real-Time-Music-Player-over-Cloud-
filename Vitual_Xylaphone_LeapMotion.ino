/*
@File: photon_leapMotion.ino

@Description: This code is to be run on the particle photon device which reads the leap motion sensor
			  data from the serial terminal and publishes it for another device to subscribe to it.

*/

#include <stdio.h>

String serialData;

void setup() {
    pinMode(D2, OUTPUT);
    Serial.begin(115200);
}

void loop() {
  
  if(Serial.available() >0){
    serialData = Serial.readString();
    char buffer[10];
    sprintf(buffer,"%s\n",serialData);
    Particle.publish("leap_command",serialData);
  }

  /*if(serialData == '1'){
      digitalWrite(D2, HIGH);}
    else if(serialData == '0'){
      digitalWrite(D2, LOW);}*/
}