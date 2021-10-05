//https://create.arduino.cc/projecthub/maurizfa-13216008-arthur-jogy-13216037-agha-maretha-13216095/modbus-rs-485-using-arduino-c055b5
//Reciever
//09 = Servo
//RX = RO
//GND = RE
//GND = DE

#include <Servo.h> 
Servo myservo;  

#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9, 8);  // D0=13, D1=11, CS=10, DC=9, Reset=8
 
void setup() 
{ 
  Serial.begin(9600);  
  myservo.attach(3);  
  u8g.firstPage();  
  do {
    u8g.setFont(u8g_font_helvB10);  
    u8g.drawStr(30, 10, "Hello Moto"); 
  } while( u8g.nextPage() );
  delay(5000);  
} 
 
void loop() 
{ 
  if (Serial.available()) {
    byte angle = Serial.read();
    if(angle<=180) 
    {
      myservo.write(angle);
      u8g.firstPage();  
      do {
        u8g.setFont(u8g_font_helvR12);  
        u8g.drawStr(0, 15, "Angle:");  
        u8g.setPrintPos(75, 15);
        u8g.print(angle, 0);
      } while( u8g.nextPage() );
    }
  }
}  
