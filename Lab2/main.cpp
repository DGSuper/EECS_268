/**
*	@file main.cpp
*	@author Zachary Bruennig 
*	@date 9/19/16
*	@brief main method for this Lab. Verifies command line input then creates an instance of MedicalExecutive
*              and gives it control of everything else
*/

#include "MedicalExecutive.h"
#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
    if(argc>=2)
    {
        std::string fileName = argv[1];
	MedicalExecutive exec(fileName);
	exec.run();
	return 0;
    }
    else
    {
        std::cout << "Error: invalid number of arguments. One required.\n";
        return 0;
    }
}

