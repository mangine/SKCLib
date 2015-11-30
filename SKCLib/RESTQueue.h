/*
 * RESTQueue.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Matheus
 */

#ifndef RESTQUEUE_H_
#define RESTQUEUE_H_

#include <boost/function.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/static_assert.hpp>

#include "IRestRequest.h"

namespace skc{

class RESTQueue{
private:
	boost::lockfree::queue<IRestRequest*,boost::lockfree::capacity<3000>> _queue;
    int _size = 0;

	void Init(int len){
		//_queue = boost::lockfree::queue<IRestRequest*>();
		//if(len>0) _queue.reserve(len);
	}
public:
	RESTQueue(){
		//Init(-1);
	}

	RESTQueue(int capacity){
		//Init(capacity);
	}

	template<class T>
	inline void emplace(T restrequest){
		//BOOST_STATIC_ASSERT(boost::is_base_of<IRestRequest, T>);
        BOOST_STATIC_ASSERT_MSG(
            (boost::is_base_of<IRestRequest, T>::value),
            "T must be a descendant of IRestRequest"
        );

		IRestRequest * newit = malloc(sizeof(T));
		memcpy((void*)newit,&restrequest,sizeof(T));
		_queue.push(newit);
        _size++;
	}

	inline void add(IRestRequest * restrequest){
		_queue.push(restrequest);
		_size++;
	}

	inline void consume(boost::function<pplx::task<void>(IRestRequest * t)> f){
        //_queue.consume_one(f);
        _size--;
		IRestRequest * to_pop;
		_queue.pop(to_pop);
		f(to_pop);
		delete to_pop;
	}

	inline void consume_preserve(boost::function<pplx::task<void>(IRestRequest * t)> f){
        //_queue.consume_one(f);
        _size--;
		IRestRequest * to_pop;
		_queue.pop(to_pop);
		f(to_pop);
	}

	inline bool empty(){
		return _queue.empty();
	}

	inline int size(){
        return _size;
	}
};

};
#endif /* RESTQUEUE_H_ */
