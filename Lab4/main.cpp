/**
*	@file main.cpp
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief This class verifies the correct number of command line arguments, then creates a BuildingExecutive
*              object and lets BuildingExecutive take over.
*/

#include "BuildingExecutive.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if(argc>=2)
    { 
        std::string fileName = argv[1];
        BuildingExecutive exec(fileName);
        exec.run();
        return 0;
    }
    else
    {
        std::cout << "Error: invalid number of arguments. One required.\n";
        return 0;
    }
}
