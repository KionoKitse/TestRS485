//https://create.arduino.cc/projecthub/maurizfa-13216008-arthur-jogy-13216037-agha-maretha-13216095/modbus-rs-485-using-arduino-c055b5
//Reciever
//09 = Servo
//RX = RO
//GND = RE
//GND = DE

#include <Servo.h> 
 
Servo myservo;  
 
void setup() 
{ 
  Serial.begin(9600);  
  //myservo.attach(3);  
  //myservo.write(90);
} 
 
void loop() 
{ 
  if (Serial.available()) {
    byte angle = Serial.read();
    Serial.println(angle);
    //if(angle<=180) 
    //{
      //myservo.write(angle);
    //}
  }
}  
