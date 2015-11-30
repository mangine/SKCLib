#ifndef ORIONUNSUBSCRIBECONTEXTREQUEST_H_INCLUDED
#define ORIONUNSUBSCRIBECONTEXTREQUEST_H_INCLUDED

#include <stdarg.h>
#include "IRestRequest.h"
#include "CyberPhysicalDescriptor.h"


namespace skc{
namespace RESTRequest{

class OrionUnsubscribeContextRequest : public IRestRequest{

private:
    web::json::value _data;

public:

    utility::string_t ToString(){
        return _data.serialize();
    }

    web::json::value GetJSON(){
        return _data;
    }

    OrionUnsubscribeContextRequest(string host, string subID) : IRestRequest(host){
        SetPath("/v1/unsubscribeContext/");
        SetMethod(web::http::methods::POST);
        _data["subscriptionId"] = web::json::string(subID);
    }

};
}}


#endif // ORIONUNSUBSCRIBECONTEXTREQUEST_H_INCLUDED
