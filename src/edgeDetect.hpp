#ifndef EDGEDETECTION_H
#define EDGEDETECTION_H

#include <Arduino.h>

template <typename T>

class EdgeDetection
{
public:
    // Constructor
    EdgeDetection() : mPrevSignal() {}

    enum class type
    {
        RISING_EDGE,
        FALLING_EDGE
    };

    template <typename T1, typename T2>
    auto edgeDetection(T1 TinputSignal, EdgeDetection::type _type, T2 Ttrigger) -> bool
    {
        // RISING EDGE detection
        switch (_type)
        {
        case EdgeDetection::type::RISING_EDGE:
            if (TinputSignal >= Ttrigger && mPrevSignal < Ttrigger)
            {
                mPrevSignal = TinputSignal;
                return true;
            }
            // Resetting the signal if Ttrigger was reached
            else if ((TinputSignal >= Ttrigger && mPrevSignal >= Ttrigger) || (TinputSignal < Ttrigger && mPrevSignal >= Ttrigger))
            {
                mPrevSignal = TinputSignal;
                return false;
            }
            else
                return false;
            break;

        case EdgeDetection::type::FALLING_EDGE:
            if (TinputSignal <= Ttrigger && mPrevSignal > Ttrigger)
            {
                mPrevSignal = TinputSignal;
                return true;
            }
            else if ((TinputSignal <= Ttrigger && mPrevSignal <= Ttrigger) || (TinputSignal > Ttrigger && mPrevSignal <= Ttrigger))
            {
                mPrevSignal = TinputSignal;
                return false;
            }
            else
                return false;
            break;

        default:
            Serial.println("Error: No edge type defined");
            break;
        }
    }

private:
    T mPrevSignal;
};

#endif // EDGEDETECTION_H