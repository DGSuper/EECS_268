/**
*	@file Math.cpp
*	@author Zachary Bruennig
*	@date 9/26/16
*	@brief Implementation of MathToolsInterface, which solves various problems based around the quadratic formula
*/

#include "Math.h"

int Math::solveQuadratic(double a, double b, double c, double roots[]) throw (NegativeDiscriminant)
{
    double discriminant = b*b - (4*a*c);
    if(discriminant < 0)
        throw NegativeDiscriminant("Error: discriminant is negative");
    if(a==0.0)
    {
        // bx + c = 0 -> bx = -c -> x = (-c)/(b)
        double x = (-1*c)/b;
        roots[0] = x;
        roots[1] = x;
        return 1;
    }
    if(discriminant == 0)
    {
        double x = (-1*b)/(2*a);
        roots[0] = x;
        roots[1] = x;
        return 1;
    }
    else
    {
        double x1 = ((-1*b) + sqrt(discriminant))/(2*a);
        double x2 = ((-1*b) - sqrt(discriminant))/(2*a);
        roots[0] = x1;
        roots[1] = x2;
        return 2;
    }
    
}

int Math::intersectLineUnitCircle(double d, double e, double f, double xy[][2]) throw (NoIntersection)
{
    double a = d*d + e*e;
    double b = 2*e*f;
    double c = f*f - d*d;
    int numRoots;
    try
    {
        numRoots = solveQuadratic(a, b, c, xy[1]);
        //dx + ey + f = 0 -> dx = -f - ey -> x = (-f -ey)/d
        //doesn't matter how many roots we have because solveQuadratic
        //already returns the same value twice 
        xy[0][0] = (f*-1 - e*xy[1][0]) / d;
        xy[0][1] = (f*-1 - e*xy[1][1]) / d;
    }
    catch(NegativeDiscriminant n)
    {
        throw NoIntersection("Error: line does not intersect the unit circle");
    }
    return numRoots;
}

void Math::roomDimensions(double Area, double Extra, double minRequiredLength, double& width, double& length) throw (CannotDetermineRoomDimensions)
{
        double results[2];
        try
        {
            int numSolutions = solveQuadratic(1, Extra, Area*-1, results);
            if(results[0] < minRequiredLength && results[1] < minRequiredLength)
                throw CannotDetermineRoomDimensions("Error: minimum required length cannot be satisfied");
            if(numSolutions==1)
            {
                length = results[0];
                width = results[0] + Extra;
            }
            else if(results[0] >= minRequiredLength)
            {
                length = results[0];
                width = results[0] + Extra;
            }
            else //this must work otherwise an error would have been thrown
            {
                length = results[1];
                width = results[1] + Extra;
            }
        }
        catch(NegativeDiscriminant n)
        {
            throw CannotDetermineRoomDimensions("Error: room size must be positive");
        }
}
