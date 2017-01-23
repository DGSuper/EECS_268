/**
*	@file MazeCreationException.h
*	@author Zachary Bruennig
*	@date 10/22/16
*	@brief A programmer-defined exception. Extends std::runtime_error
*/

#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H

#include <stdexcept>
#include <string>

class MazeCreationException : public std::runtime_error
{
public:
    /**
    * @post Creates an exception with the message
    */
    MazeCreationException(const std::string message);
};
#endif
