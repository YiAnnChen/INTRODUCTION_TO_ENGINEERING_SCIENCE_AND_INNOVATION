#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12);
const int motorIn1 = 4;
const int motorIn2 = 5;
const int motorIn3 = 6;
const int motorIn4 = 7;
const int EnableA = 2;
const int EnableB = 3;
const int ledA = 8;
const int ledB = 9;
char F, B, S, L, R;
char charreceived;
void setup()
{
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);
  pinMode(EnableA, OUTPUT);
  pinMode(EnableB, OUTPUT);
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);

  Serial.begin(38400);
  BTSerial.begin(9600);
  Serial.println("Enter AT commands:");
}



void loop()
{

  if (BTSerial.available()) {
    charreceived = BTSerial.read();
  }
  while (BTSerial.available()) {
    BTSerial.read();
  }

  //
  if (charreceived == 'B') {

    Serial.println("Back");
    analogWrite(EnableA, 150);
    analogWrite(EnableB, 230);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    delay(200);
    charreceived = 'S';
  }

  //
  else if (charreceived == 'R') {

    Serial.println("Right");
    analogWrite(EnableA, 180);
    analogWrite(EnableB, 150);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    delay(150);
    charreceived = 'S';
  }

  //
  else if (charreceived == 'L') {

    Serial.println("Left");
    analogWrite(EnableA, 160);
    analogWrite(EnableB, 210);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    delay(150);
    charreceived = 'S';
    Serial.println(charreceived);
  }

  //
  else if (charreceived == 'F') {

    Serial.println("Forward");
    analogWrite(EnableA, 150);
    analogWrite(EnableB, 250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    delay(200);
    charreceived = 'S';
  }

  //
   else if (charreceived == 'S') {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }

}
