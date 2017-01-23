/**
*	@file EmptyPriorityQueue.h
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief Header file for a user defined exception. This one is used in PriorityQueue
*/

#ifndef EMPTY_PRIORITY_QUEUE
#define EMPTY_PRIORITY_QUEUE

#include <stdexcept>
#include <string>

class EmptyPriorityQueue : public std::logic_error
{
public:
    EmptyPriorityQueue(const std::string& message = "");
};
#endif
