/**
*	@file MazeCreationException.cpp
*	@author Zachary Bruennig
*	@date 10/22/16
*	@brief A programmer-defined exception. Extends std::runtime_error
*/

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const std::string message): 
std::runtime_error("Maze Creation Exception: " + message)
{
}  //end constructor
