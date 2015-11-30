#ifndef SENSORBEHAVIOR_H_
#define SENSORBEHAVIOR_H_

#include <vector>
#include <boost/thread/thread.hpp>
#include <boost/atomic.hpp>

#include "skc.h"
#include "IRestRequest.h"
#include "IHaltable.h"

using namespace std;

namespace skc{

enum SensorMode : int{
	none = 0, ReadOnly = 1, WriteOnly = 2, ReadAndWrite = 3
};


class SensorBehavior{
	friend class SensorManager; //manager has access to everything
private:
	SensorMode _mode = SensorMode::none;
	bool _enabled = false;
	bool _startOnRequest = false; //if subscriber requests data, will it turn on and gather?
	long _startDelay = -1; //ms between starts/updates
	long _startToUpdateDelay = 1000; //ms between start function and update function
	bool _timeCritical = false; // uses thread to process sensor, good for blocking or long proessing sensors
	bool _instantStart = false; //set true to start a new thread and NOT wait for other threads to finish, shouldn`t be a problem if there are less than 4 sensors online at the same time
	bool _alwaysOn = false; //never turns off the device
	const string _name = ""; //name of the sensor
	string _id = "";
	//vector<Pin> _ports; //list of ports to be used
    //bool _running = false;
    boost::atomic<bool> _running;

public:

	//gets and sets
	bool GetEnabled(){ return _enabled; }
	void SetEnabled(bool enable){ _enabled = enable; }
	bool GetAlwaysOn(){ return _alwaysOn; }
	void SetAlwaysOn(bool alwayson){ _alwaysOn = alwayson; }
	bool GetTimeCritical(){ return _timeCritical; }
	void SetTimeCritical(bool timeCritical){ _timeCritical = timeCritical; }
	bool GetInstantStart(){ return _instantStart; }
	void SetInstantStart(bool instantStart){ _instantStart = instantStart; }
	bool GetCanBeInvoked(){ return _startOnRequest; }
	void SetCanBeInvoked(bool startOnRequest){ _startOnRequest = startOnRequest; }
	long GetSensorUpdateDelay(){ return _startDelay; }
	void SetSensorUpdateDelay(long delay){ _startDelay = delay; }
	long GetSensorSetupDelay(){ return _startToUpdateDelay; }
	void SetSensorSetupDelay(long delay){ _startToUpdateDelay = delay; }
	void SetMode(SensorMode mode){ _mode = mode; }
	string GetName(){ return _name; }
	string GetID(){ return _id; }
	SensorMode GetMode(){ return _mode; }

	SensorBehavior(string name, string id) : _name(name){
		_id = id;
		_running = false;
	}

	virtual ~SensorBehavior(){}

	//all behavior may return a list of requests for the restClient to perform
	virtual vector<IRestRequest*> Start(){ cout << "[" << GetName() << "] Start not implemented." << endl; return vector<IRestRequest*>();}; //call right after turning device on
	virtual vector<IRestRequest*> Stop(){ cout << "[" << GetName() << "] Stop not implemented." << endl; return vector<IRestRequest*>();}; //call right before turning device off
	virtual vector<IRestRequest*> Update(){ cout << "[" << GetName() << "] Update not implemented." << endl; return vector<IRestRequest*>();}; //call to gather data
	virtual vector<IRestRequest*> Reset(){ cout << "[" << GetName() << "] Reset not implemented." << endl; return vector<IRestRequest*>();}; //reset device (THIS DOESNT POWER OFF THE DEVICE)
    virtual void PowerUp(){}
    virtual void PowerDown(){}
};

};

#endif
