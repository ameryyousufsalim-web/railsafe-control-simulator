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
- Python 3
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
├── scripts/
│   └── simulate_route.py
├── CMakeLists.txt
└── README.md
```

## Safety Rules

The simulator implements basic safety rules inspired by railway automation systems:

1. A train may only enter a track section if the signal is green.
2. A train may only enter a track section if the section is not occupied.
3. A conflict is detected when a target section is already occupied.
4. An emergency stop is required if the signal is red or the target section is occupied.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run C++ Simulator

```bash
./build/railsafe_simulator
```

## Run Unit Tests

```bash
ctest --test-dir build --output-on-failure
```

## Run Python Route Simulation

```bash
python3 scripts/simulate_route.py
```

## Example Output

```text
Train ICE-101 entered section 1 safely.
```

## Purpose

This project was created as a compact software engineering project focused on safety-relevant control logic, automated testing and CI/CD workflows. It demonstrates basic concepts relevant to railway technology, automation systems and embedded software development.
