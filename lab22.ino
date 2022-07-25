#include<Wire.h>
int val,delaytime;
void setup() {
  
Wire.begin(8); // begin with address 8
Serial.begin(9600);
Wire.onReceive(receiveevent);//request for the data and get it into receive event
for (int LED_Pin = 13; LED_Pin >= 2; LED_Pin--) 
  {

    pinMode(LED_Pin, OUTPUT);

  }
 

}
void receiveevent(int x){
  
  val=Wire.read();// reading from incoming data  master
  
}

void loop() {
  delay(50);

for (int LED_Pin = 13; LED_Pin > 2; LED_Pin--) 
  
  { 
    // map the value to delay time
    delaytime=map(val,1,255,1000,1);
    digitalWrite(LED_Pin, HIGH);
    delay(delaytime);
    digitalWrite(LED_Pin, LOW);

  }



  for (int LED_Pin = 2; LED_Pin <= 12; LED_Pin++) 
  {
   
     
    delaytime=map(val,1,255,1000,1);
    digitalWrite(LED_Pin, HIGH);
    delay(delaytime);
    digitalWrite(LED_Pin, LOW);


}
    
}

