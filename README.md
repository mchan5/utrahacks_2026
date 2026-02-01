# UTRA Robot Control System

Code for controlling a robot that can move around, detect obstacles, and complete different tasks at various stations.

## What Is This?

This is the brain of the robot - the code that tells it what to do. The robot can:
- Drive forward, turn left, and turn right
- Detect objects using an ultrasonic sensor (like how bats use echolocation)
- Pick up and drop objects using a servo arm
- Detect colors using a color sensor
- Run different programs for different tasks (we call these "stations")

## What You Need (Hardware)

Think of these as the robot's body parts:
- **Arduino UNO R4 Minima**: The robot's brain (a small computer)
- **L298N Motor Driver**: Controls the motors (like a power manager)
- **Ultrasonic Sensor (HC-SR04)**: Detects how far away objects are (the robot's eyes)
- **Color Sensor (TCS3200)**: Tells what color things are (optional)
- **Servo Motor**: Moves an arm up and down to grab things
- **DC Motors**: Two motors that spin the wheels to make the robot move

## How to Wire Everything (Pin Connections)

**Don't worry if this looks confusing! This is just reference information - the robot should already be wired up.**

### Motors (L298N Motor Driver)
These control the wheels:
- Pin 9, 2, 3 → Control left motor
- Pin 10, 4, 5 → Control right motor

### Distance Sensor (Ultrasonic)
These let the robot "see" obstacles:
- Pin 11 → Sends signal (TRIG)
- Pin 12 → Receives signal (ECHO)

## What's in This Project (File Organization)

```
UTRA-main/
├── src/
│   ├── main.cpp              # The main program - START HERE
│   ├── movements.cpp/h       # Code for moving the robot
│   ├── robot_mode.h          # List of different modes/tasks
│   ├── ultrasonic.h          # Code for distance sensor
│   ├── StationA/             # Code for Station A task
│   ├── StationB/             # Code for Station B task
│   ├── StationC/             # Code for Station C task
│   └── StationTest/          # Code for testing things out
├── lib/                      # Color sensor code
├── include/
│   └── constants.hpp         # Pin numbers stored here
└── platformio.ini            # Settings file
```

**WRequired Libraries (Don't Worry, They Install Automatically!)

These are pre-written code packages that make things easier:
- **L298N** - Makes controlling motors simple
- **Servo** - Makes controlling the arm simple
- **NewPing** - Makes using the distance sensor simple

**You don't need to download these!** PlatformIO downloads them automatically when you build the code.
- `Servo` (v1.1.8) - Servo motor control
- `Getting Started: How to Upload Code to the Robot

### Step 1: Install Software
You need two things on your computer:
1. **VS Code** - A code editor (free at [code.visualstudio.com](https://code.visualstudio.com))
2. **PlatformIO** - An extension for VS Code that talks to Arduino
   - Open VS Code
   - Click the Extensions icon (looks like building blocks) on the left
   - Search for "PlatformIO IDE"
   - Click Install

### Step 2: Open This Project
1. Open VS Code
2. Click `File` → `Open Folder`
3. Select the `UTRA-main` folder
4. Wait a few seconds for PlatformIO to load

### Step 3: Connect the Robot
1. Plug the Arduino into your computer using a USB cable
2. The Arduino should light up
How to Use: Choosing What the Robot Does

The robot can run different programs (we call them "stations"). You choose which one by changing a single line of code.

### Changing the Station

1. In VS Code, open the file `src/main.cpp`
2. Look for this line near the top (around line 65):
   ```cpp
   constexpr RobotMode START_MODE = RobotMode::STATION_A;
   ```
3. Change `STATION_A` to whichever station you want:
   - `STATION_A` - Runs the Station A program
   - `STATION_B` - Runs the Station B program
   - `STATION_C` - Runs the Station C program
   - `TEST` - Runs test code (good for trying things out)
   - `IDLE` - Robot does nothing (sits still)
4. Save the file (Ctrl+S or Cmd+S)
5. Upload to the robot (click the → arrow at bottom)

**That's it!** You don't need to change anything else
1. Open `src/main.cpp`
2. Modify the `START_MODE` constant:
   `Writing Your Own Station Code

Let's say you want to program Station A. Here's how:

1. Open `src/StationA/station_A.cpp`
2. Find the `runStationA()` function
3. Add commands inside it:

```cpp
void runStationA() {
  moveForward(1000);  // Drive forward for 1 second
  turnLeft(500);      // Turn left for 0.5 seconds
  moveForward(2000);  // Drive forward for 2 seconds
  // Add more commands here!
}
```

**Tips:**
- The number in `moveForward(1000)` is milliseconds (1000 = 1 second)
- Stack commands one after another - the robot does them in order
- Test often! Upload after each change to see what happensExample: StationA/Station_A.h
#pragma once
void runStationA();

// Example: StationA/station_A.cpp
#include "Station_A.h"
#include "movements.h"

void runStationA() {
  moveForward(1000);
  turnLeft(500);
  // Add your station logic here
}Robot Commands You Can Use

Here are the basic commands to control the robot:

| Command | What It Does | Example |
|---------|-------------|---------|
| `moveForward(1000)` | Drive forward for 1000 milliseconds (1 second) | `moveForward(2000)` = go forward 2 seconds |
| `turnLeft(500)` | Turn left for 500 milliseconds | `turnLeft(1000)` = longer turn (more degrees) |
| `turnRight(500)` | Turn right for 500 milliseconds | `turnRight(300)` = quick turn |
| `elevateBox(servo)` | Raise the servo arm up | Good for picking things up |
| `lowerBox(servo)` | Lower the servo arm down | Good for dropping things |
| `How This Code is Organized (For the Curious)

This project is built to be easy to modify:
- **One place to choose the task**: Just change the mode in `main.cpp`
- **Each station is separate**: StationA code doesn't mess with StationB code
- **Runs once, then stops**: The robot does its task once, not forever in a loop
- **Pin numbers in one file**: All wire connections listed in `constants.hpp` for easy reference
moveForward(1000);   // Go forward
turCommon Questions

### Q: The robot doesn't move when I upload code. What's wrong?
- Make sure the Arduino is powered on (you should see lights)
- Check that the battery is charged (motors need more power than USB provides)
- Try opening the Serial Monitor to see if the code is running

### Q: How do I know what duration to use for turns?
- Start with 500 milliseconds and test it
- If it turns too much, use a smaller number (like 300)
- If it doesn't turn enough, use a bigger number (like 700)
- Every robot is slightly different - experiment!

### Q: The robot turns but doesn't go straight. Why?
- The motors might not be exactly the same speed
- Try adjusting the speed values in `movements.cpp` (look for the 1000 values)
- Make one motor slightly faster/slower to compensate

###Need Help?

- **First time coding?** That's okay! Start by just changing the numbers in existing commands and see what happens
- **Robot behaving weirdly?** Check the Serial Monitor for error messages
- **Want to add new features?** Look at how existing code works and copy the pattern
- **Stuck?** Ask someone on the UTRA team!

## About This Project

This project is part of **UTRA** (University of Toronto Robotics Association) activities. It's designed to be easy for beginners to learn from and modify.

Have fun building and experimenting! 🤖
### Adding a New Station

1. Create a new directory: `src/StationD/`
2. Add header file: `Station_D.h` with function declaration
3. Add implementation: `station_D.cpp` with logic
4. Add enum value to `robot_mode.h`: `STATION_D`
5. Update switch statement in `main.cpp`

### Debugging

The robot waits 2 seconds after `setup()` begins, allowing time for:
- Serial connection establishment
- Physical placement and preparation

Monitor serial output at 115200 baud for debugging information.

## License

This project is part of UTRA (University of Toronto Robotics Association) activities.

## Contributing

When contributing, please:
- Add Doxygen-style documentation comments to all new functions
- Follow existing code structure and naming conventions
- Test thoroughly before committing
