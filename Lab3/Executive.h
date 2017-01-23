/**
*	@file Executive.h
*	@author Zachary Bruennig 
*	@date 9/26/16
*	@brief Handles all user i/o and all calls to Math. This class is used for getting user inputs for the functions that Math does, as well as printing out the results in a sensible way.
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Math.h"
#include <iostream>

class Executive
{
private:
    Math math; //an instance of the Math class, which does the actual computation
    
    /** @pre None.
    *   @post None.
    *   @return a user inputted double.
    *   This method guarantees a valid input for any double, no matter what the user enters.
    *   Since doubles are used frequently in Math, this method will be called for almost all user input
    */
    double getDoubleFromUser();
    
    /** @pre None.
    *   @post None.
    *   Takes inputs A, B, and C from the user, calls the quadratic method in Math, then prints the output
    */
    void getAndRunQuadratic();
    /** @pre None.
    *   @post None.
    *   Takes inputs Area, Extra, and minRequiredLength from user, calls the ballroom method in Math, and prints the output
    */
    void getAndRunBallroom();
    
    /** @pre None.
    *   @post None.
    *   Takes inputs, d, e, and f from the user, calls the unit circle method in Math, then prints the output
    */
    void getAndRunUnitCircle();
public:
    //default constructor. This has no code in it.
    Executive();
    
    /** @pre None.
    *   @post None.
    *   Prints out the options menu, then calls another method or terminates based on user input. Also handles all exceptions.
    */
    void run();
};

#endif
