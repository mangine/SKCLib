#ifndef SENSORTESTE_H_INCLUDED
#define SENSORTESTE_H_INCLUDED

#include "HaltableDriver.h"
#include "SensorBehavior.h"

class TesteBehavior : public HaltableDriver, SensorBehavior{
public:
    void HaltFor(long ms){

    }
    void HaltUntil(){

    }

};

#endif // SENSORTESTE_H_INCLUDED
