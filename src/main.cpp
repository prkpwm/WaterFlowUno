#include <Arduino.h>
// borad: Arduino Uno

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int relayPin = 7; // the number of the relay pin
// built-in LED
const int ledPin = LED_BUILTIN; // the number of the LED pin


void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello World");
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(analogInPin);
  Serial.println(sensorValue);
  if (sensorValue > 500) {
    digitalWrite(relayPin, LOW);
    digitalWrite(ledPin, HIGH);

  } else {
    digitalWrite(relayPin, HIGH);
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
}
a