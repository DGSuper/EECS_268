/**
*	@file Math.h
*	@author Zachary Bruennig 
*	@date 9/25/16
*	@brief Header file for Math.cpp, which does various calculations based on the quadratic formula
*              Implements MathToolsInterface.
*/

#ifndef MATH_H
#define MATH_H

#include "MathToolsInterface.h"
#include <math.h>

class Math : public MathToolsInterface
{
public:
    //the default constructor is good enough
    int intersectLineUnitCircle(double d, double e, double f, double xy[][2]) throw (NoIntersection);
    void roomDimensions(double Area, double Extra, double minRequiredLength, double& width, double& length) throw (CannotDetermineRoomDimensions);
    int solveQuadratic(double a, double b, double c, double roots[]) throw (NegativeDiscriminant);
    
};

#endif

