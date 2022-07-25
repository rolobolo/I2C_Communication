#include<Wire.h>
#define KNOB A0
void setup() {
Wire.begin(8);
pinMode(KNOB,INPUT);
Serial.begin(9600);

}

void loop() {
 int valuex=analogRead(KNOB);//reading the pot value
 int valuey=map(valuex,0,1023,1,255);// mapping the values between 1 to 255
 Wire.beginTransmission(8);// starting communication with slave address 8
 Wire.write(valuey);// sending the data to slave
 Wire.endTransmission();//ending the transmission
 delay(50);
}