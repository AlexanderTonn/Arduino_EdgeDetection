# Arduino_EdgeDetection
Arduino Library for detecting rising of falling edges of signals
# Usage 
```cpp

#include "edgeDetection.hpp"

EdgeDetection<bool> _trig

void setup(){
    Serial.begin(9600);
}

void loop(){
    bool exampleSignal = true;

    // This will return true only once in the first loop (because exampleSignal is never changing)
    auto booleanSignal = _trig.edgeDetection(timer, EdgeDetection<bool>::type::RISING_EDGE, true)
    if(booleanSignal){
        Serial.println("Rising edge detected");
    }
}



```
