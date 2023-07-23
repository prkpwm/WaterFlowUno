#include <Arduino.h>

const int RELAY_PIN = 7;
const int SOIL_MOISTURE_PIN = 6;
const int WORKING_TIME_THRESHOLD = 60000;

unsigned long workingStartTime = 0;

// Function declarations
void relayHandler(int relayPin, int relayState);

void setup()
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  Serial.begin(115200);
  relayHandler(RELAY_PIN, HIGH);
}

void loop()
{

  int soilMoisture = digitalRead(SOIL_MOISTURE_PIN);

  if (soilMoisture == LOW)
  {
    relayHandler(RELAY_PIN, LOW);
    workingStartTime = millis();
  }
  else if (millis() - workingStartTime < WORKING_TIME_THRESHOLD)
  {
    // Do nothing while waiting
  }
  else
  {
    relayHandler(RELAY_PIN, HIGH);
  }

  delay(200);
}
