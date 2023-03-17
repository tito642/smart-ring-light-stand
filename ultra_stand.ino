// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------
#define atrigPin 4          //sensor B
#define aechoPin 5  

#define btrigPin 6          //sensor B
#define bechoPin 7  

#define ctrigPin 8          //sensor B
#define cechoPin 9  

#include <Servo.h>

Servo myservo;


const int Pin = 3
; // 
char Text;

String Spilt;

String angle;

int pos = 0;    // variable to store the servo position

int k1;

void setup() {
   Serial.begin(9600);

   
 
  pinMode(atrigPin, OUTPUT);
  pinMode(aechoPin, INPUT);
  pinMode(btrigPin, OUTPUT);
  pinMode(bechoPin, INPUT);
  pinMode(ctrigPin, OUTPUT);
  pinMode(cechoPin, INPUT);

pinMode (Pin, OUTPUT); 


myservo.attach(Pin);

//myservo.write(90);

// Open serial monitor at 115200 baud to see ping results.
}

void loop() { 
 
int aduration, adistance;
  digitalWrite(atrigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(atrigPin, LOW);
  aduration = pulseIn(aechoPin, HIGH);
  adistance = (aduration/2) / 29.1;
  
  int bduration, bdistance;
  digitalWrite(btrigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(btrigPin, LOW);
  bduration = pulseIn(bechoPin, HIGH);
  bdistance = (bduration/2) / 29.1;

  int cduration, cdistance;
  digitalWrite(ctrigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(ctrigPin, LOW);
  cduration = pulseIn(cechoPin, HIGH);
  cdistance = (cduration/2) / 29.1;
     
Serial.println(adistance);
Serial.println(bdistance);
Serial.println(cdistance);


   if( (adistance < bdistance )&(adistance< cdistance ))
  {
    myservo.write(0);              // tell servo to go to position in variable 'pos'
                         // waits 15 ms for the servo to reach the position
  }
   if ((bdistance< adistance )&(bdistance< cdistance ))
  {
    myservo.write(90);              // tell servo to go to position in variable 'pos'
                         // waits 15 ms for the servo to reach the position
  } 
  if ((cdistance< bdistance)&(cdistance< adistance))
  {
    myservo.write(180);              // tell servo to go to position in variable 'pos'
                         // waits 15 ms for the servo to reach the position
  }
  
  
  
  
  if(Serial.available())

  {

    Text = Serial.read();  

    Spilt = Spilt + Text; 


if (Text == '*') {

      Serial.println(Spilt);

      Spilt = Spilt.substring(0, Spilt.length() - 1); // Delete last char *

      k1 = Spilt.indexOf('*');

      angle = Spilt.substring(0, k1);

      myservo.write(angle.toInt());

      delay(15);  

  

      Spilt = "";   

  }

      }

}
