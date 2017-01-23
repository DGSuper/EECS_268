/**
*	@file EmptyPriorityQueue.cpp
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief This is a VERY complicated file. It defines an exception, but in a VERY complicated way.
*/

#include "EmptyPriorityQueue.h"

EmptyPriorityQueue::EmptyPriorityQueue(const std::string& message)
        : logic_error("Empty Priority Queue: " + message) {}
