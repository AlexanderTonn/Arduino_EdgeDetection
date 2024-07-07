#include "edgeDetect.hpp"

/**
 * @brief Detecting the rising or falling edge of a boolean or analog signals (e.g. button, switch, potentiometer)
 * @param TinputSignal is the signal that is checked for a rising edge
 * @param TpreviousSignal is the "old value" of inputSignal, have to be a separate variable
 * @param Type is the edge type, can be atUtilities::edgeType::RISING_EDGE or FALLING_EDGE
 * @param Ttrigger For Boolean: HIGH or LOW | For Analog: any analog value, can be any datatype
 * @return true
 * @return false
 */
template <typename T>
template <typename T1, typename T2>
auto EdgeDetection<T>::edgeDetection(T1 TinputSignal, EdgeDetection::type _type, T2 Ttrigger) -> bool
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
