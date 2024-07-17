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
        bool ret = false;
        // RISING EDGE detection
        switch (_type)
        {
        case EdgeDetection::type::RISING_EDGE:
            if (TinputSignal >= Ttrigger && mPrevSignal < Ttrigger)
            {
                mPrevSignal = TinputSignal;
                ret = true;
            }
            // Resetting the signal if Ttrigger was reached
            else if ((TinputSignal >= Ttrigger && mPrevSignal >= Ttrigger) || (TinputSignal < Ttrigger && mPrevSignal >= Ttrigger))
            {
                mPrevSignal = TinputSignal;
                ret = false;
            }
            else
                ret = false;
            break;

        case EdgeDetection::type::FALLING_EDGE:
            if (TinputSignal <= Ttrigger && mPrevSignal > Ttrigger)
            {
                mPrevSignal = TinputSignal;
                ret = true;
            }
            else if ((TinputSignal <= Ttrigger && mPrevSignal <= Ttrigger) || (TinputSignal > Ttrigger && mPrevSignal <= Ttrigger))
            {
                mPrevSignal = TinputSignal;
                ret = false;
            }
            else
                ret = false;
            break;

        default:
            break;
        }
        return ret;
    }

private:
    T mPrevSignal;
};

#endif // EDGEDETECTION_H