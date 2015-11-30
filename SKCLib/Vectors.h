#ifndef VECTORS_H_
#define VECTORS_H_

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#include <vector>

#include "skc.h"


////more vectors options (http://stackoverflow.com/questions/3177241/best-way-to-concatenate-two-vectors) by aloisdg
template <typename T>
std::vector<T> operator+(const std::vector<T> &A, const std::vector<T> &B)
{
	if (B.size()==0) return A;
	std::vector<T> AB;
	AB.reserve(A.size() + B.size());                // preallocate memory
	AB.insert(AB.end(), A.begin(), A.end());        // add A;
	AB.insert(AB.end(), B.begin(), B.end());        // add B;
	return AB;
}

template <typename T>
std::vector<T> &operator+=(std::vector<T> &A, const std::vector<T> &B)
{
	if (B.size()==0) return A;
	A.reserve(A.size() + B.size());                // preallocate memory without erase original data
	A.insert(A.end(), B.begin(), B.end());         // add B;
	return A;                                        // here A could be named AB
}
////end of vector options

#endif
