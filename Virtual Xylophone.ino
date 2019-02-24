/**************************************************************************
 * File        : Xylophone.ino
 * Description : This file has eight touch sensors interfaced with Photon board.
 *               As there are just 7 digital pins with interupts, one pin is chosen as analog input.
 *               Interupts are used to detect the occurance of any note being touch.
 *               The notes detected are transfered to the remote python script with the photon board over the cloud.
 *               Based on the note touched, the corresponding note is played on the speaker using python scripting
 * Date        : 02/23/2019
 * **********************************************************************/

/***********************************************************************
 *                      Includes
 * ********************************************************************/
// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
 *                      Globals
 * ********************************************************************/
//for note 1
int interrupt_note1_ISR = A1;
int Touch_note1_detected = 0;                                                                                                                

//for note2
int interrupt_note2_ISR = D1;
int Touch_note2_detected = 0;

//for note 3
int interrupt_note3_ISR = D2;
int Touch_note3_detected = 0;

//for note 4
int interrupt_note4_ISR = D3;
int Touch_note4_detected = 0;

//for note 5
int interrupt_note5_ISR = D4;
int Touch_note5_detected = 0;

//for note 6
int interrupt_note6_ISR = D5;
int Touch_note6_detected = 0;

//for note 7
int interrupt_note7_ISR = D6;
int Touch_note7_detected = 0;

//for note 8
int interrupt_note8_ISR = D7;
int Touch_note8_detected = 0;

void setup()
{
    //setting up the baud rate for serial print on the console
    Serial.begin(9600);
    
    //Setting up the interrupts
	pinMode(interrupt_note1_ISR, INPUT);

	pinMode(interrupt_note2_ISR, INPUT);
	attachInterrupt(interrupt_note2_ISR,PIR_note2,RISING);
	
	pinMode(interrupt_note3_ISR, INPUT);    
	attachInterrupt(interrupt_note3_ISR,PIR_note3,RISING);
	
	pinMode(interrupt_note4_ISR, INPUT);
	attachInterrupt(interrupt_note4_ISR,PIR_note4,RISING);
	
	pinMode(interrupt_note5_ISR, INPUT);
	attachInterrupt(interrupt_note5_ISR,PIR_note5,RISING);
	
	pinMode(interrupt_note6_ISR, INPUT);
	attachInterrupt(interrupt_note6_ISR,PIR_note6,RISING);
	
	pinMode(interrupt_note7_ISR, INPUT);
	attachInterrupt(interrupt_note7_ISR,PIR_note7,RISING);
	
	pinMode(interrupt_note8_ISR, INPUT);
	attachInterrupt(interrupt_note8_ISR,PIR_note8,RISING);
	
}

void loop() 
{
    //Publishes the touch to the remote system if a touch on note 1 is detected
    //note 1 alone is set as analog with a threshold value due to shortage of digital pins with interrupts
    if(analogRead(interrupt_note1_ISR) > 1180)
    {

        Serial.println("touched note1");
        interrupt_note1_ISR = 0;
        
        char buffer[4];
        sprintf(buffer,"%d\n",1);
        
        //Publishes
        Particle.publish("note", buffer);
    }
    
     //Publishes the touch to the remote system if a touch on note 2 is detected
     if(Touch_note2_detected == 1)
    {
        Serial.println("touched note2");
        Touch_note2_detected = 0;
        
        char buffer[4];
        sprintf(buffer,"%d\n",2);
        Particle.publish("note", buffer);
    }
    
    //Publishes the touch to the remote system if a touch on note 3 is detected
     if(Touch_note3_detected == 1)
    {
        Serial.println("touched note3");
        Touch_note3_detected = 0;
        
        char buffer[4];
        sprintf(buffer,"%d\n",3);
        Particle.publish("note", buffer);

    }
    
    //Publishes the touch to the remote system if a touch on note 4 is detected
     if(Touch_note4_detected == 1)
    {
        Serial.println("touched note4");
        Touch_note4_detected = 0;
        
        char buffer[4];
        sprintf(buffer,"%d\n",4);
        Particle.publish("note", buffer);

    }
    
    //Publishes the touch to the remote system if a touch on note 5 is detected
     if(Touch_note5_detected == 1)
    {
        Serial.println("touched note5");
        Touch_note5_detected = 0;
        
        char buffer[4];
        sprintf(buffer,"%d\n",5);
        Particle.publish("note", buffer);

    }
    
    //Publishes the touch to the remote system if a touch on note 6 is detected
     if(Touch_note6_detected == 1)
    {
        Serial.println("touched note6");
        Touch_note6_detected = 0;
        
        char buffer[4];
        sprintf(buffer,"%d\n",6);
        Particle.publish("note", buffer);

    }
    
    //Publishes the touch to the remote system if a touch on note 7 is detected
     if(Touch_note7_detected == 1)
    {
        Serial.println("touched note7");
        Touch_note7_detected = 0;
        
        char buffer[4];
        sprintf(buffer,"%d\n",7);
        Particle.publish("note", buffer);

    }
    
    //Publishes the touch to the remote system if a touch on note 8 is detected
     if(Touch_note8_detected == 1)
    {
        Serial.println("touched note8");
        Touch_note8_detected = 0;
        
        char buffer[4];
        sprintf(buffer,"%d\n",8);
        Particle.publish("note", buffer);

    }

}

//Interrupt handler for each note

void PIR_note2()
{
    Touch_note2_detected = 1;
}

void PIR_note3()
{
    Touch_note3_detected = 1;
}


void PIR_note4()
{
    Touch_note4_detected = 1;
}


void PIR_note5()
{
    Touch_note5_detected = 1;
}


void PIR_note6()
{
    Touch_note6_detected = 1;
}


void PIR_note7()
{
    Touch_note7_detected = 1;
}

void PIR_note8()
{
    Touch_note8_detected = 1;
}

