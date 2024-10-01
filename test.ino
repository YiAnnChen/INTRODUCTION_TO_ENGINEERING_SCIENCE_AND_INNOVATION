#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12); // RX | TX
char val, temp;
const char* out;
const int Green_ledpin = 13, Blue_ledpin = 3, Red_ledpin = 4;
void setup() {
  Serial.begin(38400);
  pinMode(Green_ledpin, OUTPUT);
  pinMode(Blue_ledpin, OUTPUT);
  pinMode(Red_ledpin, OUTPUT);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400); // HC-05 default speed in AT command more
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
  }
  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (val == 'G' || val == 'g' || val == 'B' || val == 'b' || val == 'R' || val == 'r' || val == 'A' || val == 'a')
  {
    temp = val ;
  }
  if (temp == 'G' || temp == 'g')
  {
    digitalWrite(Green_ledpin, HIGH);
    delay(1000);
    digitalWrite(Green_ledpin, LOW);
    delay(1000);
  }

  Serial.println(temp);
}
