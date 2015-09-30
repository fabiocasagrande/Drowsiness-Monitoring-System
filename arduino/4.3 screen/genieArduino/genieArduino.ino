


#include <genieArduino.h>
Genie genie;
#define RESETLINE 4  // Change this if you are not using an Arduino Adaptor Shield Version 2 (see code below)

int num=0;
int x=0;
void setup()
{
  Serial2.begin(115200);  //Connection with Arduino Slave
  Serial3.begin(115200);  //Connection with Arduino Master
  Serial1.begin(200000);  // Serial0 @ 200000 (200K) Baud
  genie.Begin(Serial1);   // Use Serial1 for talking to the Genie Library, and to the 4D Systems display
  
 
}

void loop()
{
  delay(50);
  if (Serial3.available()) {
  x = Serial3.read();          //Get Data from Arduino Master
  }
  if (Serial2.available()) {
  num = Serial2.read();        //Get Data from Arduino Slave
  }
 if(x==49){
 num=49;
 }
 
  if(num==48){
 genie.WriteObject(GENIE_OBJ_FORM,0x00,0);  //Connect to Bluetooth
  num=0;
  }
  else if(num==49){
    genie.WriteObject(GENIE_OBJ_FORM,0x01,0); //Eyes Detected
    num=0;
  }
  else if(num==50){
  genie.WriteObject(GENIE_OBJ_FORM,0x02,0);  //No Eyes Detected
  num=0;
  }
  else if(num==51){
  genie.WriteObject(GENIE_OBJ_FORM,0x03,0);  //Voulme up
  num=0;
}
  else if(num==52){
  genie.WriteObject(GENIE_OBJ_FORM,0x04,0); //Stopping the car
  num=0;
}
  
}


