#include <iostream>
#include "../include/Signal.h"
#include "../include/TrackSection.h"
#include "../include/Train.h"
#include "../include/SafetyController.h"

int main() {
    Signal signal;
    TrackSection section1(1);
    Train train("ICE-101", 0);
    SafetyController controller;

    signal.setGreen();

    if (controller.canTrainEnterSection(signal, section1)) {
        section1.occupy();
        train.moveToSection(section1.getId());

        std::cout << "Train " << train.getTrainId()
                  << " entered section " << train.getCurrentSectionId()
                  << " safely." << std::endl;
    } else {
        std::cout << "Movement blocked by safety controller." << std::endl;
    }

    return 0;
}