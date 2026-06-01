#include "../include/Signal.h"

Signal::Signal() {
    state = SignalState::RED;
}

void Signal::setRed() {
    state = SignalState::RED;
}

void Signal::setGreen() {
    state = SignalState::GREEN;
}

SignalState Signal::getState() const {
    return state;
}

bool Signal::isGreen() const {
    return state == SignalState::GREEN;
}