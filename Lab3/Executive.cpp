/**
*	@file Executive.cpp
*	@author Zachary Bruennig
*	@date 9/26/16
*	@brief Handles all user i/o and all calls to Math. This class is used for getting user inputs for the functions that Math does,
*              as well as printing out the results in a sensible way.
*/
#include "Executive.h"

Executive::Executive()
{
    //this doesn't need to do anything
}

double Executive::getDoubleFromUser()
{
    double d;
    std::cin >> d;
    while(std::cin.fail())
    { //guarantees valid input
        std::cin.clear();
        std::cin.ignore();
        std::cin >> d;
    }
    return d;
}

void Executive::getAndRunQuadratic()
{
    double A;
    double B;
    double C;
    double roots[2];
    std::cout << "Enter A: ";
    A = getDoubleFromUser();
    std::cout << "Enter B: ";
    B = getDoubleFromUser();
    std::cout << "Enter C: ";
    C = getDoubleFromUser();
    
    int numRoots = math.solveQuadratic(A, B, C, roots);
    if(numRoots == 1)
    {
        std::cout << "The root is: " << roots[0] << "\n\n";
    }
    else //numRoots == 2
    {
        std::cout << "The roots are: " << roots[0] << ", " << roots[1] << "\n\n";
    }
}

void Executive::getAndRunBallroom()
{
    double Area;
    double Extra;
    double minRequiredLength;
    double width;
    double length;
    std::cout << "Enter Area: ";
    Area = getDoubleFromUser();
    std::cout << "Enter Extra: ";
    Extra = getDoubleFromUser();
    std::cout << "Enter minRequiredLength: ";
    minRequiredLength = getDoubleFromUser();
    
    math.roomDimensions(Area, Extra, minRequiredLength, width, length);
    std::cout << "Length: " << length << '\n';
    std::cout << "Width: " << width << "\n\n";
}

void Executive::getAndRunUnitCircle()
{
    double d;
    double e;
    double f;
    std::cout << "Enter d: ";
    d = getDoubleFromUser();
    std::cout << "Enter e: ";
    e = getDoubleFromUser();
    std::cout << "Enter f: ";
    f = getDoubleFromUser();
    
    double xy[2][2]; 
    
    int numRoots = math.intersectLineUnitCircle(d, e, f, xy);
    
    if(numRoots==1)
    {
        std::cout << "Line intersects unit circle at (" << xy[0][0] << ", " << xy[1][0] << ")\n\n"; 
    }
    else //numRoots == 2
    {
        std::cout << "Line intersects unit circle at (" << xy[0][0] << ", " << xy[1][0] << ") and "
                  << "(" << xy[0][1] << ", " << xy[1][1] << ")\n\n";
    }
    
}

void Executive::run()
{
    while(true)
    {    
        std::cout << "1. Enter A, B, C for a quadratic equation to be solved\n";
        std::cout << "2. Enter the d, e, f parameters for a line to be interescted with a unit circle\n";
        std::cout << "3. Enter Area, Extra, and minRequiredLength for a ballroom\n";
        std::cout << "4. Quit\n";
        char choice = ' ';
        
        while(choice != '1' && choice != '2' && choice != '3' && choice != '4')
            std::cin >> choice;
        
        try
        {
            if(choice == '1')
            {
                getAndRunQuadratic();
            }
            else if(choice == '2')
            {
                getAndRunUnitCircle();
            }
            else if(choice == '3')
            {
                getAndRunBallroom();
            }
            else if(choice == '4')
            {
                break;
            }
        }
        catch(NegativeDiscriminant e)
        {   //My error messages are descriptive enough that hopefully this will be fine
            std::cout << e.what() << "\n\n";
        }
        catch(NoIntersection e)
        {
            std::cout << e.what() << "\n\n"; 
        }
        catch(CannotDetermineRoomDimensions e)
        {
            std::cout << e.what() << "\n\n";
        }
        
        
    }
}
