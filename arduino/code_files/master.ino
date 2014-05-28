int incomingByte;
boolean state;
const int reset=8;          //Reset
const int radioOff=11;      //Radio Off 

void setup() {
  Serial.begin(9600);       //Communication with Bluetooth Module 
  Serial1.begin(115200);    //Communication with Arduino Slave
  Serial2.begin(115200);    //Communication with 4D Systems LCD
  digitalWrite(reset,HIGH); 
  pinMode(reset,OUTPUT);   
  pinMode(radioOff,OUTPUT);   
}

boolean flag=false;

void loop()
{
if (Serial.available() > 0) {   //Read Data 
  incomingByte = Serial.read(); //from Bluetooth Module
  Serial.println(incomingByte); //
}

  if (incomingByte == 97) {      //If Eyes are not Detected   
    flag=false;                  //
    digitalWrite(radioOff,LOW);  //
    delay(10);                   //
    Serial1.println(0);           //Start the Alert Cycle on Arduino Slave
 }

 if(incomingByte == 98 && flag==false) {   // If Eyes Detected
   delay(10);                              //    
   Serial2.println(1);                     //Show on LCD State_1
   flag=true;                              //
   digitalWrite(reset,LOW);                //Reset Alert Cycle
   delay(50);                              //on the Arduino Slave
    digitalWrite(reset,HIGH);              //and turn the 
  digitalWrite(radioOff,HIGH);             //Radio Volume Down 
  }
  
  
delay(100);
}

