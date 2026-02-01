#include <Arduino.h>

// Pin Definitions
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Variables to store frequency
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  Serial.begin(115200);
  Serial.println("TCS3200 Color Sensor Initialized...");
}

void loop() {
  // 1. Read Red Photodiodes
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  
  // 2. Read Green Photodiodes
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // 3. Read Blue Photodiodes
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  // Print results to Serial Monitor
  Serial.print(" R= ");
  Serial.print(redFrequency);
  Serial.print(" G= ");
  Serial.print(greenFrequency);
  Serial.print(" B= ");
  Serial.println(blueFrequency);

  delay(500);
}