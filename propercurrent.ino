//gives values of current consumed
#include "ACS712.h"
ACS712  ACS(A0, 5.0, 1023, 100);
unsigned long last_time =0;
unsigned long current_time =0;
float bill_amount=0;
float Wh =0 ;  
void setup() {
  Serial.begin(115200);
}
void loop() {
  float V= 220;
  float I = ACS.mA_AC();
  float P= 220*(0.001* I);
  last_time = current_time;
  current_time = millis();   
  Wh = Wh+  P *(( current_time -last_time) /3600000.0) ; 
  bill_amount = (Wh/1000)*9;
  Serial.print("mA: ");
  Serial.println(I);
  Serial.println(bill_amount);
  delay(1000);
      
}
  
