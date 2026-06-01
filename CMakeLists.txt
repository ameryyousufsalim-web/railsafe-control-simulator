cmake_minimum_required(VERSION 3.14)

project(RailSafeControlSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(railsafe_lib
    src/Signal.cpp
    src/TrackSection.cpp
    src/Train.cpp
    src/SafetyController.cpp
)

target_include_directories(railsafe_lib PUBLIC include)

add_executable(railsafe_simulator
    src/main.cpp
)

target_link_libraries(railsafe_simulator railsafe_lib)

enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(railsafe_tests
    tests/test_safety_controller.cpp
)

target_link_libraries(railsafe_tests
    railsafe_lib
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(railsafe_tests)