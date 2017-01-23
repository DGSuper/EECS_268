/**
*	@file Stack.h
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief An exception class to be used with Stack.h and Queue.h
*/

#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolatedException.h" //maybe I need this, maybe I don't

template<typename T>
class Stack : public StackInterface<T>
{
public:
    /**
     * @post m_front is initialized to nullptr, m_length is set to 0
     */
    Stack();
    
    //deletes all nodes, makes sure all memory is deallocated properly
    ~Stack();
    
    /**
     * @return the number of items in the Stack
     */
    int getLength() const;
    
    //these methods are commented in StackInterface.h
    bool isEmpty() const;
    void push(const T& newEntry) throw (PreconditionViolatedException);
    void pop() throw (PreconditionViolatedException);
    T peek() const throw (PreconditionViolatedException);
    
private:
    Node<T>* m_front;
    int m_length; //initialized to 0 in constructor
};

#include "Stack.hpp"

#endif
