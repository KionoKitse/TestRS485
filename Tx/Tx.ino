//https://create.arduino.cc/projecthub/maurizfa-13216008-arthur-jogy-13216037-agha-maretha-13216095/modbus-rs-485-using-arduino-c055b5
//https://thewanderingengineer.com/2013/05/05/software-serial-on-the-attiny85/
//Transmitter
//A1 = Pot
//TX = DI
//5V = RE
//5V = DE


#include <SoftwareSerial.h>
#include <Bounce2.h>
SoftwareSerial mySerial(0,4);  //rx, tx
Bounce bounce = Bounce();
#define Tack 3
byte angle;

void setup() 
{ 
  bounce.attach(Tack, INPUT);
  bounce.interval(5);
  pinMode(A1, INPUT);
  mySerial.begin(9600); //Serial.begin(9600);
  angle = 0;
} 
 
void loop() 
{ 
  bounce.update();
  if(bounce.fell()){
    angle = angle + 1;
  }
  //int data= analogRead(A1); 
  //byte angle= map(data, 0, 1023, 0, 180);   
  mySerial.write(angle); 
  delay(50);                           
} 
