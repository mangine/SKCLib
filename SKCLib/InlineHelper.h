#ifndef INLINEHELPER_H_
#define INLINEHELPER_H_

#include <boost/date_time.hpp>

namespace InlineHelper{

	inline boost::posix_time::ptime GetTime(){
		return boost::posix_time::microsec_clock::local_time();
	}

	inline boost::date_time::time_resolution_traits_adapted64_impl::int_type GetMillisecondsSince(boost::posix_time::ptime * time){
		return (boost::posix_time::microsec_clock::local_time()-(*time)).total_milliseconds();
	}

	inline boost::date_time::time_resolution_traits_adapted64_impl::int_type GetMillisecondsSinceEpoch(){
		return (boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1)) - boost::posix_time::microsec_clock::local_time()).total_milliseconds();
	}



}

#endif
