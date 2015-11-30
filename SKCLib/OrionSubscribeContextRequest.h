#ifndef ORIONSUBSCRIBECONTEXTREQUEST_H_INCLUDED
#define ORIONSUBSCRIBECONTEXTREQUEST_H_INCLUDED

#include <stdarg.h>
#include "IRestRequest.h"
#include "CyberPhysicalDescriptor.h"


namespace skc{
namespace RESTRequest{

class OrionSubscribeContextRequest : public IRestRequest{

private:
    web::json::value _data;
    int _notify_index = 0;

public:

    /*
    operacoes possiveis:idem a update mas sem valor
    */
    enum NotifyConditionType{OnTimeInterval, OnChange};

    utility::string_t ToString(){
        return _data.serialize();
    }

    web::json::value GetJSON(){
        return _data;
    }

    string Get_ISO8601_duration(int years, int months, int weeks, int days, int hours, int minutes, int seconds){
        stringstream ss("P");
        if(years != 0) ss << "Y" << years;
        if(months != 0) ss << "M" << months;
        if(weeks != 0) ss << "W" << weeks;
        if(days != 0) ss << "D" << days;

        if(hours != 0 || seconds != 0 || minutes != 0) ss << "T";

        if(hours != 0) ss << "H" << hours;
        if(minutes != 0) ss << "M" << minutes;
        if(seconds != 0) ss << "S" << seconds;

        return ss.str();
    }

    OrionSubscribeContextRequest(string host, string refer) : IRestRequest(host){
        SetPath("/v1/subscribeContext/");
        SetReference(refer);
        SetMethod(web::http::methods::POST);
        _data["notifyConditions"] = web::json::array();
    }

    void AddNotifyCondition(NotifyConditionType type, char * condition, ...){
        if(type==OnTimeInterval){ //so um parametro
            _data["notifyConditions"][_notify_index]["type"] = "ONTIMEINTERVAL";
            _data["notifyConditions"][_notify_index]["condValues"] = web::json::array();
            _data["notifyConditions"][_notify_index]["condValues"][0] = web::json::string(U(condition));
        }else if(type==OnChange){ //array de parametros
            _data["notifyConditions"][_notify_index]["type"] = "ONTIMEINTERVAL";
            _data["notifyConditions"][_notify_index]["condValues"] = web::json::array();

            int index = 0;
            char * curArg = condition;
            va_list vl;

            va_start(vl,condition);
            while(curArg!=NULL){
                _data["notifyConditions"][_notify_index]["condValues"][index] = web::json::string(U(condition);
                curArg = va_arg(vl,char*);
                index++;
            }
            va_end(vl);

        }
        _notify_index++;
    }

    void AddContext(CyberPhysicalDescriptor cpd){
        if(_entities_index==-1) _data["entities"] = web::json::value::array();
        _entities_index++;

        _data["entities"][_entities_index] = web::json::value();
        _data["entities"][_entities_index]["type"] = web::json::value::string(cpd.type);
		_data["entities"][_entities_index]["isPattern"] = web::json::value::boolean(cpd.isPattern);
		_data["entities"][_entities_index]["id"] = web::json::value::string(cpd.id);
    }

    void AddAtribute(const char * attribute){
		if(_attributes_index==-1) _data["attributes"] = web::json::value::array();
        _attributes_index++;
		_data["attributes"][_attributes_index] = web::json::value::string(U(attribute));
	}

    void SetReference(const char * refer){
        _data["reference"] = web::json::value::string(U(refer));
    }


    void SetDuration(int years, int months, int weeks, int days, int hours, int minutes, int seconds){
        _data["duration"] = web::json::value::string(U(Get_ISO8601_duration(years, months, weeks, days, hours, minutes, seconds)));
    }
    void SetDuration(string ISO_8601_interval){
        _data["duration"] = web::json::value::string(U(ISO_8601_interval));
    }


};


}}

#endif // ORIONSUBSCRIBECONTEXTREQUEST_H_INCLUDED
