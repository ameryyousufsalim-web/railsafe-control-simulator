#ifndef SAFETYCONTROLLER_H
#define SAFETYCONTROLLER_H

#include "Signal.h"
#include "TrackSection.h"
#include "Train.h"

class SafetyController {
public:
    bool canTrainEnterSection(const Signal& signal, const TrackSection& section) const;
    bool detectConflict(const TrackSection& section) const;
    bool emergencyStopRequired(const Signal& signal, const Train& train, const TrackSection& targetSection) const;
};

#endif