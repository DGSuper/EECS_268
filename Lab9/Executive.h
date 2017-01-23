/**
*	@file Executive.h
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief Implemented according to specifications. Constructor calls runSimulation,
*       which will loop and read in the entire file and output accordingly.
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "PriorityQueue.h"
#include "Patient.h"
#include <fstream>
#include <iostream>

class Executive
{
private:
    std::ifstream inFile;
    bool m_fileExists = false;
    int parameter;
    PriorityQueue<Patient>* pq;
    
    //Reads each line of the file until end of file, and does the appropriate action with each line.
    void runSimulation();
    
    //Prints out what would happen if we served everyone in the PriorityQueue.
    void preview(PriorityQueue<Patient> pq); //NOTE: The Priority Queue is passed by value!!!
public:
    //Constructor. Reads in a file name, opens it, and calls runSimulation to do the rest of the program.
    Executive(const char* fileName); //constructor; it opens the indicated file and calls runSimulation.
    
};
#endif
