#ifndef EDGEDETECTION_H
#define EDGEDETECTION_H

#include <Arduino.h>

template <typename T>

class EdgeDetection
{
public: 
    // Constructor  
    EdgeDetection() : mPrevSignal() {} 
    
    enum class type { RISING_EDGE, FALLING_EDGE };

    template <typename T1, typename T2>
    auto edgeDetection(T1, type, T2) -> bool;

private:
    T mPrevSignal;

};

#endif // EDGEDETECTION_H