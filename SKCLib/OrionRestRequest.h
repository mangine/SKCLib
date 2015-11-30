#ifndef RESTREQUEST_H_
#define RESTREQUEST_H_

#include <string.h>
#include <vector>

#include <cpprest/http_client.h>
#include <cpprest/json.h>

#include "skc.h"
#include "CyberPhysicalDescriptor.h"
#include "IRestRequest.h"
/*
queries:

     <host:port>/v1/updateContext
    <host:port>/v1/queryContext
    <host:port>/v1/subscribeContext
    <host:port>/v1/updateContextSubscription
    <host:port>/v1/unsubscribeContext

*/

using namespace skc;

namespace RESTRequest{


const utility::string_t REST_ACTIONS[] = {utility::string_t("APPEND"), utility::string_t("UPDATE")};
enum RestAction: int{APPEND = 0, UPDATE = 1};

class OrionRestRequest : public IRestRequest{
	friend class SensorManager;
private:
	static CyberPhysicalDescriptor _cpd;

	web::json::value _data;
	RestAction _action;

	int _data_index = 0;

	void SetAction(RestAction action);
public:

	OrionRestRequest(std::string host);
	OrionRestRequest(std::string host, CyberPhysicalDescriptor cpd);

	void ApplyCyberPhysicalDescriptor(CyberPhysicalDescriptor cpd);
	void SetCyberPhysicalDescriptor(CyberPhysicalDescriptor cpd);
	CyberPhysicalDescriptor GetCyberPhysicalDescriptor();

	RestAction GetAction();

	void AddData(const char * name, const char * value);
	void AddData(const char * name, utility::string_t value);
	void AddData(const char * name, float value);
	void AddData(const char * name, double value);
	void AddData(const char * name, int value);
	void AddData(const char * name, long value);
	void AddData(const char * name, long long value);
	utility::string_t ToString();
    web::json::value GetJSON();
    void SetMethod(web::http::method);
    void SetPath(std::string);
};

}
#endif
