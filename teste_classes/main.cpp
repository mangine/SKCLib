#include <iostream>

#include "SensorTeste.h"

using namespace std;


int main()
{
    TesteBehavior * ts = new TesteBehavior();
    ts->PowerUp();
    delete ts;

    cout << "Hello world!" << endl;
    return 0;
}
