/**
*	@file main.cpp
*	@author Zachary Bruennig
*	@date 9/26/16
*	@brief Creates an instance of Executive and immediately passes all control over to it.
*/
#include "Executive.h"

int main()
{
    Executive* exec = new Executive();
    exec->run();
    delete exec;
    return 0;
}
