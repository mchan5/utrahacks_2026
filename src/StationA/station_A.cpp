/**
 * @file station_A.cpp
 * @brief Implementation of Station A task sequence
 */

#include "Station_A.h"
#include "movements.h"

void runStationA() {
  moveForward(1000);
  turnLeft(500);
}
