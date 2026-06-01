#ifndef SIGNAL_H
#define SIGNAL_H

enum class SignalState {
    RED,
    GREEN
};

class Signal {
private:
    SignalState state;

public:
    Signal();

    void setRed();
    void setGreen();

    SignalState getState() const;
    bool isGreen() const;
};

#endif