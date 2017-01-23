/**
*	@file CannotDetermineRoomDimensions.h
*	@author Zachary Bruennig 
*	@date 9/25/16
*	@brief An exception class used in MathToolsInterface
*/
 
#ifndef CANNOTDETERMINEROOMDIMENSIONS_H
#define CANNOTDETERMINEROOMDIMENSIONS_H

#include <stdexcept>
#include <string>

class CannotDetermineRoomDimensions : public std::domain_error
{
public:
    CannotDetermineRoomDimensions(const std::string& m = "") : std::domain_error(m.c_str()) {}
};

#endif
