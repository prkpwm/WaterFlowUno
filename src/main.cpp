#include <Arduino.h>

const int RELAY_PIN = 7;
const int SOIL_MOISTURE_PIN = 6;
const int WORKING_TIME_THRESHOLD = 6000;

long lastStartTime = 0;
int lastSoilMoisture = 0;

// Function declarations
void relayHandler(int relayPin, int relayState);

void setup()
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  Serial.begin(9600);
  relayHandler(RELAY_PIN, HIGH);
}

void loop()
{

  long currentTime = millis();
  int soilMoisture = digitalRead(SOIL_MOISTURE_PIN);
  Serial.println(soilMoisture);

  if (soilMoisture == LOW && lastSoilMoisture == LOW)
  {
    relayHandler(RELAY_PIN, LOW);
    lastStartTime = millis();
  }
  else if ((millis() - lastStartTime) < WORKING_TIME_THRESHOLD)
  {
    Serial.println(millis() - lastStartTime);
    // Do nothing while waiting
  }
  else
  {
    relayHandler(RELAY_PIN, HIGH);
    
  }

  lastSoilMoisture = soilMoisture;

  delay(1000);
}

void relayHandler(int relayPin, int relayState)
{

  digitalWrite(relayPin, relayState);
}
