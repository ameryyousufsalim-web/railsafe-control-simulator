#include "../include/SafetyController.h"

bool SafetyController::canTrainEnterSection(const Signal& signal, const TrackSection& section) const {
    return signal.isGreen() && !section.isOccupied();
}

bool SafetyController::detectConflict(const TrackSection& section) const {
    return section.isOccupied();
}

bool SafetyController::emergencyStopRequired(
    const Signal& signal,
    const Train& train,
    const TrackSection& targetSection
) const {
    return !signal.isGreen() || targetSection.isOccupied();
}