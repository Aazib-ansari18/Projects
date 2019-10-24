#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad kpd = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
int motorplus=10;
int motorminus=11;
void setup(){
   pinMode(motorplus,OUTPUT);
   pinMode(motorminus,OUTPUT);
   Serial.begin(9600);
}
  
void loop(){
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '1':
      //Clockwise
        digitalWrite(motorplus, LOW);
        digitalWrite(motorminus, HIGH);
        break;
      //Stop
              case '0':
        digitalWrite(motorplus, LOW);
        digitalWrite(motorminus, LOW);
        break;
              case '2':
       //Anticlockwise
        digitalWrite(motorplus, HIGH);
        digitalWrite(motorminus, LOW);
        break;
              case '3':
        //3Task Perform
        digitalWrite(motorplus, HIGH);
        digitalWrite(motorminus, LOW);
        delay(4000);
        digitalWrite(motorplus, LOW);
        digitalWrite(motorminus, LOW);
        delay(4000);
        digitalWrite(motorplus, LOW);
        digitalWrite(motorminus, HIGH);
        delay(4000);
        break;
        default:
      Serial.println(key);
    }
  }
}
