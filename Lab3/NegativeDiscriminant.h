/**
*	@file NegativeDiscriminant.h
*	@author Zachary Bruennig 
*	@date 9/25/16
*	@brief An exception class used in MathToolsInterface
*/
 
#ifndef NEGATIVEDISCRIMINANT_H
#define NEGATIVEDISCRIMINANT_H

#include <stdexcept>
#include <string>

class NegativeDiscriminant : public std::domain_error
{
public:
    NegativeDiscriminant(const std::string& m = "") : std::domain_error(m.c_str()) {}
};

#endif
