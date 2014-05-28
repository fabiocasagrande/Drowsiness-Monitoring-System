const int radioOn=12;  //RadiOn Led
const int blinks=2;    //Hazard Lights Leds
const int ledPin = 11; //Alert Led
        
//RadioShack 7-Segment LED Digital Display Configuration.        
int segA = 31;     //Display pin 14
int segB = 33;     //Display pin 16
int segC = 35;     //Display pin 13
int segD = 37;     //Display pin 3
int segE = 39;     //Display pin 5
int segF = 41;     //Display pin 11
int segG = 4;      //Display pin 15
int segA1 = 30;    //Display pin 14
int segB2 = 32;    //Display pin 16
int segC3 = 34;    //Display pin 13
int segD4 = 36;    //Display pin 3
int segE5 = 38;    //Display pin 5
int segF6 = 40;    //Display pin 11
int segG7 = 3;     //Display pin 15
//////////////////////////////////////////////////////////////


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(radioOn, OUTPUT);    
  pinMode(blinks, OUTPUT);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segA1, OUTPUT);
  pinMode(segB2, OUTPUT);
  pinMode(segC3, OUTPUT);
  pinMode(segD4, OUTPUT);
  pinMode(segE5, OUTPUT);
  pinMode(segF6, OUTPUT);
  pinMode(segG7, OUTPUT);

  Serial2.begin(115200);  // Communication with Arduino Master
  Serial1.begin(115200);  // Communication with 4D Systems LCD 
  Serial.begin(9600); 
 
   
}

int x=0;
void loop()
{
  lightNumber(5);  // initial speed of 
  lightNumber1(0); // 50 miles per hours
  
 if (Serial2.available()) {
      x= Serial2.read();    //get data from Arduino Master  
      }
  
  
 if(x==48){                        // Cycle Starts
   Serial1.println(2);             // Display on 4D Systems LCD state_2:   
   digitalWrite(ledPin, HIGH);     // Alert On
   delay(1500);                    // Wait 1.5 seconds
   Serial1.println(3);             // Display on 4D Systems LCD state_3:
   digitalWrite(radioOn, HIGH);    //Volume Up
   delay(1500);                    // Wait 1.5 Seconds
   Serial1.println(4);             // Display on 4D Systems LCD state_4:
   four();                         // Hazard Lights On
   countdown();                    //Decrease the speed of the car
   zero();                         //until it Stops.
 }

  
}
  
 void four(){
  digitalWrite(blinks, HIGH);
  delay(50);
  digitalWrite(blinks, LOW);
  delay(50);
  digitalWrite(blinks, HIGH);
  delay(50);
  digitalWrite(blinks, LOW);
}


int countdown(){
  int digit=4;
  for(digit=4;digit>-1;digit--){
     lightNumber(digit);
     for(int digit2=9;digit2>=-1;digit2--){
         lightNumber1(digit2);
         delay(75);
          } 
      }
}



void zero(){  //infinite Loop that display 00 until 
int i=0;      //the arduino slave is reset from the
loopr:        //arduino master
lightNumber(i);
lightNumber1(i);
goto loopr;
}



void lightNumber(int numberToDisplay) {

  switch (numberToDisplay){

  case 0:                    //Display Zero
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, LOW);
    break;

  case 1:                    //Display One
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;

  case 2:                    //Display Two
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, LOW);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;

  case 3:                  //Display Three
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;

  case 4:                  //Display Four
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 5:                  //Display Five
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 6:                  //Display Six
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 7:                  //Display Seven
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;

  case 8:                  //Display Eight
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 9:                  //Display Nine
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 10:                 //Display Nothing
    digitalWrite(segA, LOW);
    digitalWrite(segB, LOW);
    digitalWrite(segC, LOW);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;
  }
}
void lightNumber1(int numberToDisplay) {

  switch (numberToDisplay){

  case 0:
    digitalWrite(segA1, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, HIGH);
    digitalWrite(segE5, HIGH);
    digitalWrite(segF6, HIGH);
    digitalWrite(segG7, LOW);
    break;

  case 1:
    digitalWrite(segA1, LOW);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, LOW);
    digitalWrite(segE5, LOW);
    digitalWrite(segF6, LOW);
    digitalWrite(segG7, LOW);
    break;

  case 2:
    digitalWrite(segA1, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC3, LOW);
    digitalWrite(segD4, HIGH);
    digitalWrite(segE5, HIGH);
    digitalWrite(segF6, LOW);
    digitalWrite(segG7, HIGH);
    break;

  case 3:
    digitalWrite(segA1, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, HIGH);
    digitalWrite(segE5, LOW);
    digitalWrite(segF6, LOW);
    digitalWrite(segG7, HIGH);
    break;

  case 4:
    digitalWrite(segA1, LOW);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, LOW);
    digitalWrite(segE5, LOW);
    digitalWrite(segF6, HIGH);
    digitalWrite(segG7, HIGH);
    break;

  case 5:
    digitalWrite(segA1, HIGH);
    digitalWrite(segB2, LOW);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, HIGH);
    digitalWrite(segE5, LOW);
    digitalWrite(segF6, HIGH);
    digitalWrite(segG7, HIGH);
    break;

  case 6:
    digitalWrite(segA1, HIGH);
    digitalWrite(segB2, LOW);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, HIGH);
    digitalWrite(segE5, HIGH);
    digitalWrite(segF6, HIGH);
    digitalWrite(segG7, HIGH);
    break;

  case 7:
    digitalWrite(segA1, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, LOW);
    digitalWrite(segE5, LOW);
    digitalWrite(segF6, LOW);
    digitalWrite(segG7, LOW);
    break;

  case 8:
    digitalWrite(segA1, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, HIGH);
    digitalWrite(segE5, HIGH);
    digitalWrite(segF6, HIGH);
    digitalWrite(segG7, HIGH);
    break;

  case 9:
    digitalWrite(segA1, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC3, HIGH);
    digitalWrite(segD4, HIGH);
    digitalWrite(segE5, LOW);
    digitalWrite(segF6, HIGH);
    digitalWrite(segG7, HIGH);
    break;

  case 10:
    digitalWrite(segA1, LOW);
    digitalWrite(segB2, LOW);
    digitalWrite(segC3, LOW);
    digitalWrite(segD4, LOW);
    digitalWrite(segE5, LOW);
    digitalWrite(segF6, LOW);
    digitalWrite(segG7, LOW);
    break;
  }
}



