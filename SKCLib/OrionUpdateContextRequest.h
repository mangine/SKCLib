#ifndef ORIONUPDATECONTEXTREQUEST_H_INCLUDED
#define ORIONUPDATECONTEXTREQUEST_H_INCLUDED

#include "IRestRequest.h"
#include "CyberPhysicalDescriptor.h"

namespace skc{
namespace RESTRequest{

class OrionUpdateContextRequest : public IRestRequest{
private:
    web::json::value _data;
    int _context_count = 0, _data_index = 0;

public:

    utility::string_t ToString(){
        return _data.serialize();
    }

    web::json::value GetJSON(){
        return _data;
    }

    OrionUpdateContextRequest(string host, CyberPhysicalDescriptor cpd) : IRestRequest(host){
        SetPath("/v1/updateContext/");
        SetMethod(web::http::methods::POST);

        _data["contextElements"] = web::json::value::array();
        _data["UpdateAction"] = web::json::value::string(U("UPDATE")); //ou append, mas na versao atual no orion nao importa
        AddContext(cpd);
    }

    int AddContext(CyberPhysicalDescriptor cpd){
        _data["contextElements"][_context_count]["type"] = web::json::value::string(cpd.type);
		_data["contextElements"][_context_count]["isPattern"] = web::json::value::boolean(cpd.isPattern);
		_data["contextElements"][_context_count]["id"] = web::json::value::string(cpd.id);
        return _context_count++;
    }

    void AddData(const char * name, const char * value, uint8_t context=0){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("string"));
		ret["value"] = web::json::value::string(U(value));
		_data["contextElements"][context]["attributes"][_data_index] = ret;
		_data_index++;
	}

	void AddData(const char * name, utility::string_t value, uint8_t context=0){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("string"));
		ret["value"] = web::json::value::string(value);
		_data["contextElements"][context]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void AddData(const char * name, float value, uint8_t context=0){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("float"));
		ret["value"] = web::json::value::number(value);
		_data["contextElements"][context]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void AddData(const char * name, double value, uint8_t context=0){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("double"));
		ret["value"] = web::json::value::number(value);
		_data["contextElements"][context]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void AddData(const char * name, int value, uint8_t context=0){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("int"));
		ret["value"] = web::json::value::number(value);
		_data["contextElements"][context]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void AddData(const char * name, long value, uint8_t context=0){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("long"));
		ret["value"] = web::json::value::number((long int)value);
		_data["contextElements"][context]["attributes"][_data_index] = ret;
		_data_index++;
	}
	void AddData(const char * name, long long value, uint8_t context=0){
		web::json::value ret;
		ret["name"] = web::json::value::string(U(name));
		ret["type"] = web::json::value::string(U("long long"));
		ret["value"] = web::json::value::number((int64_t)value);
		_data["contextElements"][context]["attributes"][_data_index] = ret;
		_data_index++;
	}

};

}}
#endif // ORIONUPDATECONTEXTREQUEST_H_INCLUDED
