#include "SensorBehavior.h"
#include "IRestRequest.h"
#include "OrionRestRequest.h"
#include "OrionUpdateContextRequest.h"
#include "CyberPhysicalDescriptor.h"

using namespace skc;
using namespace skc::RESTRequest;

class test_behavior : public skc::SensorBehavior{
public:

    test_behavior(string id, int delay, int repeat) : SensorBehavior("test_behavior",id){
        cout << "[" << GetName() << "::" << GetID() <<  "] Constructing..." << endl;
        SetSensorUpdateDelay(repeat);
        SetSensorSetupDelay(delay);
        SetEnabled(true);
    }

    vector<IRestRequest*> Start(){
        vector<IRestRequest*> ret = vector<IRestRequest*>();
        cout << "[" << GetName() << "::" << GetID() << "] Starting..." << endl;


        skc::CyberPhysicalDescriptor cpd;
        OrionUpdateContextRequest * urs = new OrionUpdateContextRequest("",cpd);
        urs->AddData("valorfloat",10.5f);
        urs->SetCallback(boost::bind(&test_behavior::teste_callback,this,_1));
        ret.push_back((IRestRequest*)urs);

        /*OrionRestRequest * ors = new OrionRestRequest("");
        ors->SetMethod(web::http::methods::GET);
        ors->AddData("valorfloat",10.5f);
        ors->SetCallback(boost::bind(&test_behavior::teste_callback,this,_1));
        ret.push_back((IRestRequest*)ors);
        */
//        ors->SetCallback([](web::http::http_response r){cout << "Resposta de request: " << r.status_code() << endl;});
 //       ors->SetCallback(boost::bind(&test_behavior::teste_callback,this,_1));

//        ors->SetCallback(boost::function<void(web::http::http_response)>(teste_callback));


        return ret;

    } //call right after turning device on

	vector<IRestRequest*> Stop(){
        cout << "[" << GetName() << "::" << GetID() <<  "] Stopping..." << endl;
        return vector<IRestRequest*>();
    }; //call right before turning device off

	vector<IRestRequest*> Update(){
        cout << "[" << GetName() << "::" << GetID() <<  "] Updating..." << endl;
        return vector<IRestRequest*>();
	}; //call to gather data

	vector<IRestRequest*> Reset(){
        cout << "[" << GetName() << "::" << GetID() <<  "] Reseting..." << endl;
        return vector<IRestRequest*>();
    }; //reset device (THIS DOESNT POWER OFF THE DEVICE)

    void teste_callback(web::http::http_response r){
        cout << "Resposta de request: " << r.status_code() << endl;
        cout << "-Body: " << r.to_string();
    }

};
