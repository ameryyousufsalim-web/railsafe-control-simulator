# RailSafe Control Simulator

RailSafe Control Simulator is a small C++ project that models basic safety logic for railway and automation systems.

The project focuses on signal states, track occupancy detection and safety checks for train movement. It also includes automated unit tests with GoogleTest and a GitHub Actions CI pipeline.

## Features

- Signal control with red and green states
- Track section occupancy detection
- Train movement simulation
- Safety controller for movement permission
- Conflict detection for occupied track sections
- Emergency stop logic
- Unit tests with GoogleTest
- CMake build system
- Automated CI pipeline with GitHub Actions

## Technologies

- C++17
- CMake
- GoogleTest
- GitHub Actions
- Git

## Project Structure

```text
railsafe-control-simulator/
├── .github/
│   └── workflows/
│       └── ci.yml
├── include/
│   ├── Signal.h
│   ├── TrackSection.h
│   ├── Train.h
│   └── SafetyController.h
├── src/
│   ├── Signal.cpp
│   ├── TrackSection.cpp
│   ├── Train.cpp
│   ├── SafetyController.cpp
│   └── main.cpp
├── tests/
│   └── test_safety_controller.cpp
├── CMakeLists.txt
└── README.md