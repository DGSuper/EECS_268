/**
*	@file PreconditionViolatedException.h
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief An exception class to be used with Stack.h and Queue.h
*/
#ifndef PRECONDITION_VIOLATED_EXCEPTION
#define PRECONDITION_VIOLATED_EXCEPTION

#include <stdexcept>
#include <string>

class PreconditionViolatedException : public std::runtime_error
{
public:
   PreconditionViolatedException(const std::string& message = "");
}; 
#endif 
 
