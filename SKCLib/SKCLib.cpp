#include <iostream>
#include <string>

#include "OrionRestRequest.h"
#include "RESTQueue.h"
#include "RESTClient.h"
#include "SensorManager.h"

#include "TestBehavior.h"

using namespace std;

int main() {
  /* Setup your example here, code that should run once
   */
    cout <<"Tudo ok!!" << endl;


    cout << "1";
    skc::RESTQueue rq(16);
    cout << "2";
    skc::SensorManager sm(&rq);
    cout << "3";
    skc::RESTClient rc(&rq);
    cout << "4";

//  test_behavior * t = new (sm.AddSensor<test_behavior>())test_behavior("id1",1000,20000);

    test_behavior * t = sm.AddSensor<test_behavior>();
    t = new (t)test_behavior("id1",1000,20000);

    //t = sm.AddSensor<test_behavior>();
    //t = new (t)test_behavior("id2",1000,3000);

    cout << "5";
    sm.Start();
    cout << "6";
    rc.Start();
  /* Code in this loop will run repeatedly
   */

  for (;;) {

  }

  return 0;
}
