/* -----------------------------------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Zachary Bruennig | zkb@ku.edu
 * Assignment:   EECS-268 Lab 1
 * Description:  Main method for this project. Simply verifies the input has enough arguments
 * and then immediately creates and calls an instance of Executive, passing the filename as a parameter.
 * Date: 8/31/2016
 *
 ---------------------------------------------------------------------------- */

#include "Executive.h"
#include <iostream>
#include <string>

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
