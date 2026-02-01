#include "movements.h"
#include "constants.hpp"

// define drivetrain ONCE
L298NX2 drivetrain(
  dt::EN_A, dt::IN1_A, dt::IN2_A,
  dt::EN_B, dt::IN1_B, dt::IN2_B
);

void moveForward(int duration)
{
  drivetrain.setSpeedA(255);
  drivetrain.setSpeedB(255);
  drivetrain.forwardFor(duration);
Serial.println("T)");


}

void turnLeft(int duration)
{
  drivetrain.setSpeedA(150);
  drivetrain.setSpeedB(150);
  drivetrain.backwardForA(duration);
  drivetrain.forwardForB(duration);
}

void turnRight(int duration)
{
  drivetrain.setSpeedA(150);
  drivetrain.setSpeedB(150);
  drivetrain.forwardForA(duration);
  drivetrain.backwardForB(duration);
}

void elevateBox(Servo &myServo)
{
  for (int pos = 0; pos <= 40; pos++)
  {
    myServo.write(pos);
    delay(15);
  }
}

void lowerBox(Servo &myServo)
{
  for (int pos = 40; pos >= 0; pos--)
  {
    myServo.write(pos);
    delay(15);
  }
}
