#ifndef TRAIN_H
#define TRAIN_H

#include <string>

class Train {
private:
    std::string trainId;
    int currentSectionId;

public:
    Train(const std::string& trainId, int currentSectionId);

    std::string getTrainId() const;
    int getCurrentSectionId() const;

    void moveToSection(int sectionId);
};

#endif