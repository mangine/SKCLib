/*
 * OrionRestRequest.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: Matheus
 */



#define ORION_REST_SERVER "http://teste-nodered-futurecu.mybluemix.net/red/"
#define ORION_REST_SERVER_GET "http://tcc-rest.mybluemix.net/get/"
#define ORION_REST_SERVER_POST "http://teste-nodered-futurecu.mybluemix.net/red/post/"
#define ORION_REST_SERVER_PUT "http://teste-nodered-futurecu.mybluemix.net/red/put/"
#define ORION_REST_SERVER_DELETE "http://teste-nodered-futurecu.mybluemix.net/red/delete/"

#include "OrionRestRequest.h"

//using namespace skc;
//using namespace skc::RESTRequest;

namespace RESTRequest{

    CyberPhysicalDescriptor OrionRestRequest::_cpd = CyberPhysicalDescriptor();

	OrionRestRequest::OrionRestRequest(string host) : IRestRequest(host){
			_data_index = 0;
			_data = web::json::value();
			//start with blanks if cpd is null, else fill with data
			_data["contextElements"] = web::json::value::array();
			_data["contextElements"][0]["attributes"] = web::json::value::array();
			_data["UpdateAction"] = web::json::value::string(utility::string_t());

			ApplyCyberPhysicalDescriptor(_cpd);


	}

	OrionRestRequest::OrionRestRequest(string host, CyberPhysicalDescriptor cpd) : IRestRequest(host){
			_data_index = 0;
			_data = web::json::value();

			//start with blanks if cpd is null, else fill with data
			_data["contextElements"] = web::json::value::array();
			_data["contextElements"][0]["attributes"] = web::json::value::array();
			_data["UpdateAction"] = web::json::value::string(utility::string_t());


			ApplyCyberPhysicalDescriptor(cpd);


		}

	void OrionRestRequest::ApplyCyberPhysicalDescriptor(CyberPhysicalDescriptor cpd){
		_data["contextElements"][0]["type"] = web::json::value::string(cpd.type);
		_data["contextElements"][0]["isPattern"] = web::json::value::boolean(cpd.isPattern);
		_data["contextElements"][0]["id"] = web::json::value::string(cpd.id);
	}

	void OrionRestRequest::SetAction(RestAction action){
		_action = action;
		_data["UpdateAction"] = web::json::value::string(REST_ACTIONS[action]);
	}
	RestAction OrionRestRequest::GetAction(){ return _action;}

	void OrionRestRequest::SetCyberPhysicalDescriptor(CyberPhysicalDescriptor cpd){_cpd=cpd;}
	CyberPhysicalDescriptor OrionRestRequest::GetCyberPhysicalDescriptor(){return _cpd;}


	void OrionRestRequest::AddData(const char * name, const char * value){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("string"));
		ret["value"] = web::json::value::string(U(value));
		_data["contextElements"][0]["attributes"][_data_index] = ret;
		_data_index++;
	}

	void OrionRestRequest::AddData(const char * name, utility::string_t value){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("string"));
		ret["value"] = web::json::value::string(value);
		_data["contextElements"][0]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void OrionRestRequest::AddData(const char * name, float value){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("float"));
		ret["value"] = web::json::value::number(value);
		_data["contextElements"][0]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void OrionRestRequest::AddData(const char * name, double value){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("double"));
		ret["value"] = web::json::value::number(value);
		_data["contextElements"][0]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void OrionRestRequest::AddData(const char * name, int value){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("int"));
		ret["value"] = web::json::value::number(value);
		_data["contextElements"][0]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void OrionRestRequest::AddData(const char * name, long value){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("long"));
		ret["value"] = web::json::value::number((long int)value);
		_data["contextElements"][0]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void OrionRestRequest::AddData(const char * name, long long value){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("long long"));
		ret["value"] = web::json::value::number((int64_t)value);
		_data["contextElements"][0]["attributes"][_data_index] = ret;
		_data_index++;
	}
	utility::string_t OrionRestRequest::ToString(){
		return _data.serialize();
	}
    web::json::value OrionRestRequest::GetJSON(){
        return _data;
    }
    void OrionRestRequest::SetMethod(web::http::method method){
        IRestRequest::SetMethod(method);
    }
    void OrionRestRequest::SetPath(string path){
        IRestRequest::SetPath(path);
    }
/*
     <host:port>/v1/updateContext
    <host:port>/v1/queryContext
    <host:port>/v1/subscribeContext
    <host:port>/v1/updateContextSubscription
    <host:port>/v1/unsubscribeContext
*/

}
