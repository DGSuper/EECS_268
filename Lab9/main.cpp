/**
*	@file main.cpp
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief main method for this Lab. Verifies command line input then creates an instance of Executive
*              and gives it control of everything else
*/

#include "Executive.h"
#include <iostream>

int main(int argc, char* argv[])
{
    if(argc>=2)
    {
        Executive exec(argv[1]);
        return 0;
    }
    else
    {
        std::cout << "Error: invalid number of arguments. One required.\n";
        return 0;
    }
}
