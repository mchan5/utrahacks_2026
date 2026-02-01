#include <Arduino.h>
#include <L298NX2.h>
#include "constants.hpp"
#include <Servo.h>
#include "movements.h"
#include <ultrasonic.h>

// Servo myServo;
// constexpr int SERVO_PIN = 6;
int pos = 0; // servo pos


void setup()
{
  Serial.begin(9600);

  unsigned long start = millis();
  while (!Serial && millis() - start < 2000) {}

  Serial.println("Testing (pls work)");
  
  
}

void loop()
{
  // put your main code here, to run repeatedly:

  Serial.println(checkDistance());

  // drivetrain.runA(L298N::FORWARD);
  // drivetrain.runB(L298N::FORWARD);

  // elevateBox(myServo);
  delay(1000);
  // lowerBox(myServo);
  delay(1000);


  moveForward(1000);
  delay(500);
  turnLeft(500);
  delay(500);
  turnRight(500);
  delay(500);
  moveForward(1000);
  delay(500);
  Serial.println("DONE");
}
