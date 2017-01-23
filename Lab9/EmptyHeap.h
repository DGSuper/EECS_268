/**
*	@file EmptyHeap.cpp
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief Header file for a user defined exception. This one is used in Heap
*/
#ifndef EMPTY_HEAP
#define EMPTY_HEAP

#include <stdexcept>
#include <string>

class EmptyHeap : public std::logic_error
{
public:
    EmptyHeap(const std::string& message = "");
};
#endif
