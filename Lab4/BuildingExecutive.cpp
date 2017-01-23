/**
*	@file BuildingExecutive.cpp
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief Manages the elevator and elevator queue for some building.
*/

#include "BuildingExecutive.h"
#include <string>
#include <sstream>

BuildingExecutive::BuildingExecutive(std::string fileName)
{
    inFile.open(fileName);
    if(!inFile.is_open())
        m_fileExists = false;
    else
    {
        m_fileExists = true;
    }
}

BuildingExecutive::~BuildingExecutive()
{
    /*if(m_fileExists)
    {
        delete m_elevatorQueue;
        delete m_elevator;
    }*/
}

void BuildingExecutive::inspection() const //shouldn't ever throw an exception
{
    std::cout << "Elevator status:\n";
    
    if(m_elevator.isEmpty())
    {
        std::cout << "The elevator is empty\n";
        std::cout << "No one is in the elevator.\n";
    }
    else //elevator isn't empty
    {
        std::cout << "The elevator is not empty\n";
        
        //won't throw an error because this will never be called if empty
        std::string front = m_elevator.peek();
        std::cout << front << " will be the next person to leave the elevator.\n";
    }
    
    if(m_elevatorQueue.isEmpty())
    {
        std::cout << "No one is waiting for the elevator\n\n";
    }
    else //line isn't empty
    {
        std::string front = m_elevatorQueue.peekFront();
        std::cout << front << " will be the next person to get on the elevator.\n\n";
    }    
}

void BuildingExecutive::pickUp() //shouldn't ever throw an exception
{
    int spaceInElevator = elevatorCapacity - m_elevator.getLength();
    int numberToFill;
    
    //figure out how many more people can/will go into the elevator
    if(spaceInElevator > m_elevatorQueue.getLength())
        numberToFill = m_elevatorQueue.getLength();
    else
        numberToFill = spaceInElevator;
    
    for(int i=0; i<numberToFill; i++) //move one person from the queue to the elevator
    {
        std::string name = m_elevatorQueue.peekFront();
        m_elevatorQueue.dequeue();
        m_elevator.push(name);
    }
}

void BuildingExecutive::dropOff(int n) //should throw an exception if n>people in elevator
{
    for(int i=0; i<n; i++)
    {
        m_elevator.pop();
        //an exception will be thrown if elevator is empty, and will be caught in run()
    }
}

void BuildingExecutive::wait(std::string name) //shouldn't ever throw an exception
{
    m_elevatorQueue.enqueue(name);
}


void BuildingExecutive::run()
{
    if(m_fileExists)
    {
        std::string line;
        while(std::getline(inFile, line))
        {
            if(line=="INSPECTION")
            {
                inspection();
            }
            else if(line=="PICK_UP")
            {
                pickUp();
            }
            else if(line.substr(0,8)=="DROP_OFF")
            {
                int num = std::stoi(line.substr(9, line.length()));
                try
                {
                    dropOff(num);
                }
                catch (PreconditionViolatedException e)
                {
                    //the exception will only be thrown if the elevator is empty, so all passengers
                    //will have already been unloaded
                    std::cout << "Error trying to unload more passengers than the elevator has.\n";
                    std::cout << "Unloading all passengers and moving on.\n\n";
                }
            }
            else if(line.substr(0,4)=="WAIT")
            {
                std::string name = line.substr(5, line.length());
                wait(name);
            }
        }
        inFile.close();
    }
}
