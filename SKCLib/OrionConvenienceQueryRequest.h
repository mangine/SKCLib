#ifndef ORIONCONVENIENCEQUERYREQUEST_H_INCLUDED
#define ORIONCONVENIENCEQUERYREQUEST_H_INCLUDED


#include "IRestRequest.h"
#include "CyberPhysicalDescriptor.h"
/*

using namespace skc;

namespace RESTResquest{

class OrionQueyContextRequest : public IRestRequest{
private:
    web::json::value _data;
    int _entities_index = -1;
    int _attributes_index = -1;

public:

    void ContextGet(const wchar_t * entityID);
    void ContextUpdate(const wchar_t * entityID, web::json::value atributes);
    void ContextAppend(const wchar_t * entityID, web::json::value atributes); //array de attributes
    void ContextDelete(const wchar_t * entityID);

    void ContextGetAttribute(const wchar_t * entityID, const wchar_t * attribute);
    void ContextUpdateAttribute(const wchar_t * entityID, const wchar_t * attribute, web::json::value value);
    void ContextAppendAttribute(const wchar_t * entityID, const wchar_t * attribute, web::json::value value);
    void ContextDeleteAttribute(const wchar_t * entityID, const wchar_t * attribute);

    void ContextGetAttributeValue(const wchar_t * entityID, const wchar_t * attribute, const wchar_t * valueID);
    void ContextUpdateAttribute(const wchar_t * entityID, const wchar_t * attribute, const wchar_t * valueID, web::json::value value);
    void ContextDeleteAttribute(const wchar_t * entityID, const wchar_t * attribute, const wchar_t * valueID);

    void ContextGetAttributesInDomain(const wchar_t * entityID, const wchar_t * attributeDomain);

    void GetContextsByType(const wchar_t * typeName);
    void GetContextsAttributeValuesByType(const wchar_t * typeName, const wchar_t * attributeName);
    void GetContextAttributesByDomain(const wchar_t * typeName, const wchar_t * domainName);

    void CreateSubscription(CyberPhysicalDescriptor cpd, string[] attributes);

    /*
    operacoes possiveis:
        GET    /v1/contextEntities/{EntityID*}
        PUT    /v1/contextEntities/{EntityID*}
        POST   /v1/contextEntities/{EntityID*}
        DELETE /v1/contextEntities/{EntityID*}

        GET    /v1/contextEntities/{EntityID*}/attributes/{attributeName}
        POST   /v1/contextEntities/{EntityID*}/attributes/{attributeName}
        PUT   /v1/contextEntities/{EntityID*}/attributes/{attributeName}
        DELETE /v1/contextEntities/{EntityID*}/attributes/{attributeName}

        GET    /v1/contextEntities/{EntityID*}/attributes/{attributeName}/{valueID}
        PUT    /v1/contextEntities/{EntityID*}/attributes/{attributeName}/{valueID}
        DELETE /v1/contextEntities/{EntityID*}/attributes/{attributeName}/{valueID}

        GET    /v1/contextEntities/{EntityID*}/attributeDomains/{attributeDomainName}

        GET    /v1/contextEntityTypes/{typeName}
        GET    /v1/contextEntityTypes/{typeName}/attributes/{attributeName}
        GET    /v1/contextEntityTypes/{typeName}/attributeDomains/{attributeDomainName}

        POST   /v1/contextSubscriptions

        PUT    /v1/contextSubscriptions/{subscriptionID}
        DELETE /v1/contextSubscriptions/{subscriptionID}

        GET /v1/contextEntities
        POST /v1/contextEntities
        GET /v1/contextSubscriptions
        GET /v1/contextSubscriptions/{subscriptionID}

        GET /v1/contextTypes
        GET /v1/contextTypes/{entityType}
    */
/*
    OrionQueyContextRequest(string host) : IRestRequest(hostr){

    }

    SetQueryType(OrionQueryType type, const wchar_t * param, ...){
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

}
*/



#endif // ORIONCONVENIENCEQUERYREQUEST_H_INCLUDED
