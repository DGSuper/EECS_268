/**
*	@file Queue.h
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief Header file for a link-based queue data type.
*/
#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "Node.h"
#include "PreconditionViolatedException.h" //maybe I need this, maybe I don't

template<typename T>
class Queue : public QueueInterface<T>
{
public:
    /**
     * @post m_front and m_back are initialized to nullptrs,
     * m_length is set to 0
     */
    Queue();
    
    //deletes all nodes, makes sure all memory is deallocated properly
    ~Queue();
    
    /**
     * @return the number of items in the Queue
     */
    int getLength() const;
    
    //these methods are commented in QueueInterface.h
    bool isEmpty() const;
    void enqueue(const T& newEntry) throw (PreconditionViolatedException);
    void dequeue() throw (PreconditionViolatedException);
    T peekFront() const throw (PreconditionViolatedException);
    
private:
    Node<T>* m_front; //where things dequeue
    Node<T>* m_back; //where things enqueue
    int m_length; //initialized to 0 in constructor
};

#include "Queue.hpp"

#endif
