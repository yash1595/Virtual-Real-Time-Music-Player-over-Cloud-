/*------------------------------------------------------------------------------
  @brief : Photon code for the Server implementation
  ----------------------------------------------------------------------------*/

  int led = D0;
  int boardLed = D7;

void setup() {
 
  pinMode(led,OUTPUT);                                                          // LED pin is output (lighting up the LED)
  pinMode(boardLed,OUTPUT);                                                     // On-board LED is output as well

  Particle.subscribe("leap_command", Leap_Handler);                             // Subscribe handler for the leap control
  Particle.subscribe("note", NotesHandler_1);                                   // Subscribe handler for the Notes command

  digitalWrite(boardLed,HIGH);
  delay(2000);

                                                                                // Then, the D7 LED will go off and the LED will turn on.
  digitalWrite(boardLed,LOW);
  digitalWrite(led,HIGH);
  delay(500);

  digitalWrite(boardLed,LOW);                                                   // The D7 LED will turn off...

  digitalWrite(boardLed,HIGH);                                                  // Now flash the D7 LED on and off three times to let us know that we're ready to go!

  Serial.begin(115200);                                                         // Setting the baud at 115200
  Serial.print("Subscribed_event\n");

}

void loop() {}

/*------------------------------------------------------------------------------
  @brief : Event handler for the incoming capacitive touch
  ----------------------------------------------------------------------------*/
void NotesHandler_1(const char *event, const char *data)                        
{
    Serial.print(event);
    if(data)Serial.print(data);
}
/*------------------------------------------------------------------------------
  @brief : Event handler for the incoming leap-motion
  ----------------------------------------------------------------------------*/
void Leap_Handler(const char *event, const char *data)                          
{
     Serial.print(event);
     if(data)Serial.print(data);
}


