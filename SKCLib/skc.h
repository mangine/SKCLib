/*
 * skc.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Matheus
 */

#ifndef SKC_H_
#define SKC_H_


#ifndef NULL
#define NULL   ((void *) 0)
#endif
#define REST_SERVER "http://teste-nodered-futurecu.mybluemix.net/red/"
#define REST_SERVER_GET "http://teste-nodered-futurecu.mybluemix.net/red/get/"
#define REST_SERVER_POST "http://teste-nodered-futurecu.mybluemix.net/red/post/"
#define REST_SERVER_PUT "http://teste-nodered-futurecu.mybluemix.net/red/put/"
#define REST_SERVER_DELETE "http://teste-nodered-futurecu.mybluemix.net/red/delete/"

namespace skc{

    namespace RESTRequest{}; //premade rest requests
    namespace Behavior{}; //premade sensors

};


#endif /* SKC_H_ */
