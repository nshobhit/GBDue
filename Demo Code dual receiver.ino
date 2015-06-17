/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */
#include <CppList.h>
#include <IRremote2.h>
//#define DEBUG


long counter=0;
int LED_PIN1 = 7;

IRrecv irrecv(11,12);

decode_results results1,results2;

void setup()
{
  Serial.begin(9600);
  
  
  delay(100);
  irrecv.enableIRIn(); // Start the receiver
  Serial.print("moving out of setup");
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  
}

void loop() {
  
  if (irrecv.decode(&results1,&results2)) {
    Serial.print(results1.value, HEX);Serial.print("  First  ");Serial.print(counter,DEC);Serial.println(" ");
  // Serial.println(results1.decode_type, HEX);
   Serial.print(results2.value, HEX);Serial.print(" Second ");Serial.print(counter,DEC);Serial.println(" ");
   //Serial.println(results2.decode_type, HEX);
    
    if(results1.decode_type){digitalWrite(6,HIGH);irrecv.resume0();counter++;}
    if(results2.decode_type){digitalWrite(7,HIGH);irrecv.resume1();counter++;}
    delay(1);
     // Receive the next value
    
    results1.value=0;
    results2.value=0;
    results1.decode_type=0;
    results2.decode_type=0;
    //irrecv.enableIRIn();
  }
  //delay(100);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
