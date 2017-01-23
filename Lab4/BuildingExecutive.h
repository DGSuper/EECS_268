/**
*	@file BuildingExecutive.h
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief An exception class to be used with Stack.h and Queue.h
*/
#ifndef BUILDING_EXECUTIVE_H
#define BUILDING_EXECUTIVE_H

#include "Queue.h"
#include "Stack.h"
#include <string>
#include <fstream>
#include <iostream>

class BuildingExecutive
{
private:
    std::ifstream inFile;
    Queue<std::string> m_elevatorQueue;
    Stack<std::string> m_elevator;
    bool m_fileExists = false;
    const int elevatorCapacity = 7;
    
    /** @post The status of the elevator and elevator queue will be printed to the console
     */
    void inspection() const;
    
    /** @post m_elevator will be filled to capacity, or m_elevatorQueue will be empty, whichever happens first
     */
    void pickUp();
    
    /** @post the first n names will be removed from m_elevator. If there are less than n names, an exception will
     *        be thrown by the stack.
     */
    void dropOff(int n);
    
    /** @post name will be added to the back of the queue.
     */
    void wait(std::string name);
public:
    /** @post the file is open and m_fileExists is set to true, if the fileName is valid
     *  m_elevator and m_elevatorQueue are allocated memory if the fileName is valid
     */
    BuildingExecutive(std::string fileName);
    
    /** @post m_elevator and m_elevatorQueue will be deleted if they were initialized
     */
    ~BuildingExecutive();
    
    /** @pre m_fileExists is true and is in a valid format
     *  @post the file will be read and will call other methods based on its contents
     */
    void run();
    
};
#endif
