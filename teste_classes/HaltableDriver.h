#ifndef HALTABLEDRIVER_H_INCLUDED
#define HALTABLEDRIVER_H_INCLUDED

#include <iostream>

#include "IHaltable.h"

using namespace std;

class HaltableDriver : public IHaltable{
public:
    void PowerUp(){
        cout << "Power Up" << endl;
    }
    void PowerDown(){
        cout << "Power Down" << endl;
    }
};


#endif // HALTABLEDRIVER_H_INCLUDED
