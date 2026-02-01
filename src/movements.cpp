/**
 * @file movements.cpp
 * @brief Implementation of robot movement functions
 */

#include "movements.h"
#include "constants.hpp"
#include "Arduino.h"

/// Motor controller for robot wheels. Speed range: 0-1023.
L298NX2 drivetrain(
  dt::EN_A, dt::IN1_A, dt::IN2_A,
  dt::EN_B, dt::IN1_B, dt::IN2_B
);

/**
 * @brief Drive the robot forward
 * @param duration Time to drive in milliseconds
 */
void moveForward(int duration)
{
    drivetrain.setSpeedA(1000);
    drivetrain.setSpeedB(1000);
    drivetrain.forwardFor(duration);
}

/**
 * @brief Rotate the robot left in place
 * @param duration Time to turn in milliseconds
 */
void turnLeft(int duration)
{
    drivetrain.setSpeedA(-1000);
    drivetrain.setSpeedB(1000);
    drivetrain.forwardFor(duration);

}

/**
 * @brief Rotate the robot right in place
 * @param duration Time to turn in milliseconds
 */
void turnRight(int duration)
{
    drivetrain.setSpeedA(1000);
    drivetrain.setSpeedB(-1000);
    drivetrain.forwardFor(duration);
}

/**
 * @brief Raise the servo arm from 0° to 40°
 * @param myServo Servo motor to control
 */
void elevateBox(Servo &myServo)
{
  for (int pos = 0; pos <= 40; pos++)
  {
    myServo.write(pos);
    delay(15);
  }
}

/**
 * @brief Lower the servo arm from 40° to 0°
 * @param myServo Servo motor to control
 */
void lowerBox(Servo &myServo)
{
  for (int pos = 40; pos >= 0; pos--)
  {
    myServo.write(pos);
    delay(15);
  }
}
