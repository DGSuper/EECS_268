/**
*	@file NoIntersection.h
*	@author Zachary Bruennig 
*	@date 9/25/16
*	@brief An exception class used in MathToolsInterface
*/
 
#ifndef NOINTERSECTION_H
#define NOINTERSECTION_H

#include <stdexcept>
#include <string>

class NoIntersection : public std::domain_error
{
public:
    NoIntersection(const std::string& m = "") : std::domain_error(m.c_str()) {}
};

#endif
