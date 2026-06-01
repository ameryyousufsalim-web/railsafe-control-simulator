#ifndef TRACKSECTION_H
#define TRACKSECTION_H

class TrackSection {
private:
    int id;
    bool occupied;

public:
    explicit TrackSection(int id);

    int getId() const;

    bool isOccupied() const;
    void occupy();
    void release();
};

#endif