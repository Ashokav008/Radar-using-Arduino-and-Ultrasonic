#include<Servo.h> // including servo motor library.
const int TRIG=11; // defining ultrasonic pin on arduino board.
const int ECHO=12;
Servo myservo;//servo variable.

long  duration; // variable for holding duration and distance
int distance;


void setup() {
  
  pinMode(TRIG,OUTPUT);// input and output pin 
  pinMode(ECHO,INPUT);
  Serial.begin(9600);//initilizing serail communicatio.
  myservo.attach(10); // attch servo motor to pin no.10(pwm)
}

void loop()
{
  // loop for running servo in forward direction..
  for (int i=0;i<180;i++)
  {
    myservo.write(i);
    delay(30); // delay for 30 microseconds...
    distance=calcDistance(); // calling the function calcDistance().
  }
  // loop to rotate servo in reverse direction...
  for (int i=180;i>=0;i++)
  {
    myservo.write(i);
    delay(30);
    distance=calcDistance();//calling the function calcDistance().
    
  }
  
}
// definig the function to calculate distance ..
  int calcDistance()
  { 
    digitalWrite(TRIG,LOW);
delayMicroseconds(2);
    digitalWrite(TRIG,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG,LOW);
    duration=pulseIn(ECHO,HIGH);
    distance=duration*0.034/2;
    return distance;
  }
  
  
