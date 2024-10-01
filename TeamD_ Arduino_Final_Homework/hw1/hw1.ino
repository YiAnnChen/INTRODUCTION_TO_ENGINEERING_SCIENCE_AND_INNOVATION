#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12); // RX | TX
char val, temp;
const char* out;
const int Green_ledpin = 13, Blue_ledpin = 3, Red_ledpin = 4;
boolean index = 0;
void setup() {
  Serial.begin(9600);
  pinMode(Green_ledpin, OUTPUT);
  pinMode(Blue_ledpin, OUTPUT);
  pinMode(Red_ledpin, OUTPUT);
  Serial.begin(38400);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400); // HC-05 default speed in AT command more
}

void loop() {
  //  if (Serial.available() == 0) {
  //    Serial.println("Please input your command");
  //    delay(5000);
  //  }
  if (Serial.available()) {
    val = Serial.read();
    while (Serial.available()) {
       Serial.read();
    }
    index = 1;

  }
  // Keep reading from Arduino Serial Monitor and send to HC-05

  if (val == 'G' || val == 'g' || val == 'B' || val == 'b' || val == 'R' || val == 'r' || val == 'A' || val == 'a' || val == 's' || val == 'S')
  {
    temp = val ;
  }
  if (temp == 'G' || temp == 'g')
  {
    digitalWrite(Green_ledpin, HIGH);
    delay(1000);
    digitalWrite(Green_ledpin, LOW);
    delay(1000);
    out = "GREEN_LED ON";
  }
  else if (temp == 'B' || temp == 'b')
  {
    digitalWrite(Blue_ledpin, HIGH);
    delay(1000);
    digitalWrite(Blue_ledpin, LOW);
    delay(1000);
    out = "BLUE_LED ON";
  }
  else if (temp == 'R' || temp == 'r')
  {
    digitalWrite(Red_ledpin, HIGH);
    delay(1000);
    digitalWrite(Red_ledpin, LOW);
    delay(1000);
    out = "RED_LED ON";
  }
  else if (temp == 'A' || temp == 'a')
  {
    digitalWrite(Red_ledpin, HIGH);
    digitalWrite(Green_ledpin, HIGH);
    digitalWrite(Blue_ledpin, HIGH);
    delay(1000);
    digitalWrite(Red_ledpin, LOW);
    digitalWrite(Green_ledpin, LOW);
    digitalWrite(Blue_ledpin, LOW);
    delay(1000);
    out = "LED ON";
  }
  else if (temp == 'S' || temp == 's') {
    digitalWrite(Red_ledpin, LOW);
    digitalWrite(Green_ledpin, LOW);
    digitalWrite(Blue_ledpin, LOW);
    out = "LED OFF";

  }


  if (Serial.available() > 0) {
    BTSerial.write(temp);
  }
  if (index == 1) {
    Serial.write(out);
    index = 0;

  }


}
