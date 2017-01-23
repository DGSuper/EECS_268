/**
*	@file PreconditionViolatedException.cpp
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief An exception class to be used with Stack.h and Queue.h
*/
#include "PreconditionViolatedException.h"  

PreconditionViolatedException::PreconditionViolatedException(const std::string& message): std::runtime_error("Precondition Violated Exception: " + message)
{
}  // end constructor

