#include "../include/TrackSection.h"

TrackSection::TrackSection(int id) : id(id), occupied(false) {}

int TrackSection::getId() const {
    return id;
}

bool TrackSection::isOccupied() const {
    return occupied;
}

void TrackSection::occupy() {
    occupied = true;
}

void TrackSection::release() {
    occupied = false;
}