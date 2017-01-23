/**
*	@file Executive.cpp
*	@author Zachary Bruennig 
*	@date 11/21/16
*	@brief Implemented according to specifications. Constructor calls runSimulation,
*       which will loop and read in the entire file and output accordingly.
*/

#include "Executive.h"

Executive::Executive(const char* fileName)
{
    inFile.open(fileName);
    if(inFile.is_open())
        m_fileExists = true;
    
    std::string firstLine;
    std::getline(inFile, firstLine);
    parameter = std::stoi(firstLine);
    pq = new PriorityQueue<Patient>(parameter);
    
    runSimulation();
    
    inFile.close();
}

void Executive::preview(PriorityQueue<Patient> pq2)
{
    std::cout << "\n=== Assuming no new arrivals, the current set of patients will be processed as follows ===\n";
    while(!pq.isEmpty())
    {
        Patient next = pq.peekFront();
        std::cout << next.getName() << " with priority " << next.getPriority() << '\n';
        pq.dequeue();
    }
    std::cout << "===================================== End of Preview =====================================\n\n";
}

void Executive::runSimulation()
{
    if(m_fileExists)
    {
        std::string line;
        while(std::getline(inFile, line))
        {
            if(line=="serve")
            {
                try
                {
                    Patient curr = pq->peekFront();
                    std::cout << "Patient " << curr.getName() << " with priority " << curr.getPriority()
                              << " is now being served.\n";
                              
                    pq->dequeue();
                }
                catch(EmptyPriorityQueue e)
                {
                    std::cout << "Priority queue is empty, moving to the next line.\n";
                }
            }
            else if(line=="preview")
            {
                preview(*pq);
            }
            else if(line.substr(0,7) == "arrival")
            {
                std::string name;
                int priority;
                line = line.substr(8,line.length());
                name = line.substr(0,line.find(' '));
                line = line.substr(line.find(' '), line.length());
                priority = std::stoi(line);
                
                Patient curr(name,priority);
                
                std::cout << "Patient " << curr.getName() << " with priority " << curr.getPriority()
                          << " has arrived.\n";
                
                pq->enqueue(curr);
            }
            // Otherwise the line isn't formatted correctly, so we should just skip it
            
        }
    }
    else
    {
        std::cout << "Error: File could not be read.\n";
    }
    
    delete pq;
}
