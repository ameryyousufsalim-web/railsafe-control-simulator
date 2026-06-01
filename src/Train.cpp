#include "../include/Train.h"

Train::Train(const std::string& trainId, int currentSectionId)
    : trainId(trainId), currentSectionId(currentSectionId) {}

std::string Train::getTrainId() const {
    return trainId;
}

int Train::getCurrentSectionId() const {
    return currentSectionId;
}

void Train::moveToSection(int sectionId) {
    currentSectionId = sectionId;
}