/**
 * @file main.cpp
 * @brief High-level behavior dispatcher for the robot.
 *
 * @details
 * This file serves as the software control hub of the robot. Said simply, it is our primary program which calls upon others to perform specific tasks. Since we have multiple stations and modes to run, this file selects which one to execute based on a compile-time constant called RobotMode.

 *
 * ## Usage
 * To change which station or mode the robot executes:
 *
 * 1. Modify the `START_MODE` constant below.
 * 2. Re-upload the code to the robot.
 *
 * No other changes are required.
 *
 * This design emphasizes **software-driven configuration** and
 * clean separation of concerns.
 */

#include <Arduino.h>

#include <L298NX2.h>
#include <Servo.h>

#include "constants.hpp"
#include "movements.h"
#include "ultrasonic.h"

#include "StationA/Station_A.h"
#include "StationB/Station_B.h"
#include "StationC/Station_C.h"
#include "StationTest/Station_Test.h"
#include "robot_mode.h"

/**
 * @brief Compile-time configuration for robot behavior.
 *
 * @details
 * This constant determines which station or operational mode
 * the robot will execute upon startup.
 *
 * Changing this value and re-uploading the firmware allows
 * rapid switching between behaviors without modifying
 * any station logic or hardware wiring.
 */




/**
 * @brief Arduino setup function.
 *
 * @details
 * Initializes serial communication and dispatches execution
 * to the selected station based on `START_MODE`.
 *
 * All station behaviors are expected to be **self-contained**
 * and blocking (i.e., they run to completion).
 */


/* UPDATE THIS AT EACH RE-UPLOAD STATION. */
constexpr RobotMode START_MODE = RobotMode::STATION_A;
void setup() {
  Serial.begin(115200);

  // Allow time for serial connection and physical placement
  delay(2000);

  // Dispatch to selected station
  switch (START_MODE) {
    case RobotMode::STATION_A:
      runStationA();
      break;

    case RobotMode::STATION_B:
      runStationB();
      break;


    case RobotMode::STATION_C:
      runStationC();
      break;
    case RobotMode::TEST:
      runStationTest();
      break;
  }
}

/**
 * @brief Arduino loop function.
 *
 * @details
 * Intentionally left empty.
 *
 * All robot behavior is executed during `setup()` to ensure
 * deterministic, single-run execution appropriate for
 * competition-style tasks.
 */
void loop() {}
