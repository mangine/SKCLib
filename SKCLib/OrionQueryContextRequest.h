#ifndef ORIONQUERYCONTEXTREQUEST_H_INCLUDED
#define ORIONQUERYCONTEXTREQUEST_H_INCLUDED

#include "IRestRequest.h"
#include "CyberPhysicalDescriptor.h"


namespace skc{
namespace RESTRequest{

class OrionQueyContextRequest : public IRestRequest{
private:
    web::json::value _data;
    int _entities_index = -1;
    int _attributes_index = -1;

public:

    /*
    operacoes possiveis:idem a update mas sem valor
    */

    OrionQueyContextRequest(string host) : IRestRequest(host){
        SetPath("/v1/queryContext/");
        SetMethod(web::http::methods::POST);
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


};

}}

#endif // ORIONQUERYCONTEXTREQUEST_H_INCLUDED
