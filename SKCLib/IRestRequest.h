/*
 * IRestRequest.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Matheus
 */

#ifndef IRESTREQUEST_H_
#define IRESTREQUEST_H_

#include <string.h>
#include <cpprest/http_client.h>
#include <boost/function.hpp>

#include "skc.h"

namespace skc{

using namespace std;

class IRestRequest{
private:
    string _host;
	string _path;
	web::http::method _method;
	boost::function<void(web::http::http_response r)> _responce_callback=NULL;


protected:
    inline void SetPath(string path){ _path=path;}
    void SetMethod(web::http::method method){_method = method;}


public:
    web::http::method GetMethod(){ return _method;}
	void SetCallback(boost::function<void(web::http::http_response r)> f){ _responce_callback = f;}
	inline void InvokeCallback(web::http::http_response r){ if(_responce_callback!=NULL) _responce_callback(r); }
	bool hasCallback(){	return (_responce_callback != NULL);}

    string GetUrl(){
        return _host;
    }
    string GetPath(){
        return _path;
    }
    string GetHost(){
        return _host;
    }

	virtual ~IRestRequest() {}
	IRestRequest(string host) {
		_host = host;
	}

	//abstracts
	virtual utility::string_t ToString() = 0;
    virtual web::json::value GetJSON() = 0;
};

}

#endif /* IRESTREQUEST_H_ */

