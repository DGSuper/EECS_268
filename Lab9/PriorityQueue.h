/**
*	@file PriorityQueue.h
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief Heap-based Priority Queue data structure. Implemented according to specifications. 
*       No helper methods created.
*/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "EmptyPriorityQueue.h"
#include "Heap.h"

template <typename T>
class PriorityQueue
{
public:
    /* Constructor. Calls Heap's constructor.
     */
    PriorityQueue(int initialSize);
    /* Copy constructor. Calls Heap's copy constructor.
     */
    PriorityQueue(const PriorityQueue<T>& pq); //copy constructor
    
    /* Destructor. Deletes theHeap.
     */
    ~PriorityQueue();
    
    /* Adds newEntry to the heap
     */
    void enqueue(T newEntry);
    
    /* Removes the top item from the Heap. If it is empty, throws EmptyPriorityQueue
     */
    void dequeue() throw (EmptyPriorityQueue);
    
    /* Returns true if the heap has no items in it, false otherwise
     */
    bool isEmpty() const;
    
    /* Returns the T at the top of the heap. If it is empty, throws EmptyPriorityQueue
     */
    T peekFront() const throw (EmptyPriorityQueue);
private:
    Heap<T>* theHeap;
};

#include "PriorityQueue.cpp"

#endif
