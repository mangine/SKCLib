#ifndef SENSORMANAGER_H_
#define SENSORMANAGER_H_

#include <vector>
#include <boost/lockfree/queue.hpp>
#include <boost/thread/thread.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/atomic.hpp>

#include "IHaltable.h"
#include "IRestRequest.h"
#include "SensorBehavior.h"
#include "RESTQueue.h"

using namespace std;

namespace skc{


enum SensorStatus : int{
	undefined = 0, Busy = 1, Starting = 2, Updating = 4, Stoping = 8, Reseting = 64, Ready = 128
};

struct Sensor{
	boost::posix_time::ptime _unresponsiveTime; //first unresponsive time
	boost::posix_time::ptime _lastRun; //time since last start/update
	SensorStatus _status = SensorStatus::undefined;
	SensorBehavior * _gs;
};
typedef struct Sensor Sensor;

class SensorManager{
private:
//    boost::atomic<int> _active_sensors;

	//boost::lockfree::queue<IRestRequest> * _queue = NULL;
	RESTQueue * _queue = NULL;

    boost::posix_time::ptime _next_sensor;
	boost::thread_group _threadpool;
	boost::asio::io_service _io_service;
	boost::asio::io_service::work * _work = NULL;
	//vector<Sensor> _sensors;
	vector<Sensor> _sensors;
	bool _run = false;
	bool _enabled = false;
	bool _timeCriticalRunning = false; //if timecritical sensor is running, will halt others
	boost::thread * thManager = NULL;

	//checks sensors, is a thread
	void _Run();
	inline void startASensor(Sensor * s);
	void SensorThread(Sensor * s);
public:

	bool Start();
	void Stop();
	void SetEnabled(bool enable);
	bool GetEnabled();

    //implementado aqui pq o compilador precisa ver
    template<class T>
T * AddSensor(){
    BOOST_STATIC_ASSERT_MSG(
        (boost::is_base_of<SensorBehavior, T>::value),
        "T must be a descendant of SensorBehavior"
    );

    T * ptr = (T*)malloc(sizeof(T));
    if(ptr==NULL) return NULL;

    Sensor s;
	s._gs = ptr;
	s._lastRun = boost::posix_time::neg_infin;
	s._unresponsiveTime = boost::posix_time::pos_infin;
	s._status = SensorStatus::undefined;

    _sensors.push_back(s);
    return ptr;
}

	void RemoveSensor(string id);

	SensorManager(RESTQueue * queue);
	~SensorManager();
};

};

#endif
