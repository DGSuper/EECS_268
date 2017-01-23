/**
*	@file main.cpp
*	@author Zachary Bruennig 
*	@date 11/12/16
*	@brief main method for this Lab. Verifies command line input then creates an instance of Executive
*              and gives it control of everything else
*/

#include <iostream>
#include <string>
#include "Executive.h"

int main(int argc, char* argv[])
{
	if(argc>=2)
        {
            std::string fileName = argv[1];
            Executive exec(fileName);
            exec.run();
            return 0;
        }
        else
        {
            std::cout << "Error: invalid number of arguments. One required.\n";
            return 0;
        }
}
