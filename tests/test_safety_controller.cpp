#include <gtest/gtest.h>
#include "../include/Signal.h"
#include "../include/TrackSection.h"
#include "../include/Train.h"
#include "../include/SafetyController.h"

TEST(SafetyControllerTest, TrainCanEnterFreeSectionWithGreenSignal) {
    Signal signal;
    TrackSection section(1);
    SafetyController controller;

    signal.setGreen();

    EXPECT_TRUE(controller.canTrainEnterSection(signal, section));
}

TEST(SafetyControllerTest, TrainCannotEnterOccupiedSection) {
    Signal signal;
    TrackSection section(1);
    SafetyController controller;

    signal.setGreen();
    section.occupy();

    EXPECT_FALSE(controller.canTrainEnterSection(signal, section));
}

TEST(SafetyControllerTest, TrainCannotEnterWithRedSignal) {
    Signal signal;
    TrackSection section(1);
    SafetyController controller;

    signal.setRed();

    EXPECT_FALSE(controller.canTrainEnterSection(signal, section));
}

TEST(SafetyControllerTest, ConflictDetectedWhenSectionOccupied) {
    TrackSection section(1);
    SafetyController controller;

    section.occupy();

    EXPECT_TRUE(controller.detectConflict(section));
}

TEST(SafetyControllerTest, NoConflictWhenSectionIsFree) {
    TrackSection section(1);
    SafetyController controller;

    EXPECT_FALSE(controller.detectConflict(section));
}

TEST(SafetyControllerTest, EmergencyStopRequiredForRedSignal) {
    Signal signal;
    TrackSection section(1);
    Train train("ICE-101", 0);
    SafetyController controller;

    signal.setRed();

    EXPECT_TRUE(controller.emergencyStopRequired(signal, train, section));
}

TEST(SafetyControllerTest, EmergencyStopRequiredForOccupiedTargetSection) {
    Signal signal;
    TrackSection section(1);
    Train train("ICE-101", 0);
    SafetyController controller;

    signal.setGreen();
    section.occupy();

    EXPECT_TRUE(controller.emergencyStopRequired(signal, train, section));
}

TEST(SafetyControllerTest, NoEmergencyStopForGreenSignalAndFreeSection) {
    Signal signal;
    TrackSection section(1);
    Train train("ICE-101", 0);
    SafetyController controller;

    signal.setGreen();

    EXPECT_FALSE(controller.emergencyStopRequired(signal, train, section));
}