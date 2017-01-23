/**
*	@file PriorityQueue.cpp
*	@author Zachary Bruennig 
*	@date 11/21/16
*	@brief Implementation of a Priority Queue data structure.
*/

#include "PriorityQueue.h"

template<typename T>
PriorityQueue<T>::PriorityQueue(int initialSize)
{
    theHeap = new Heap<T>(initialSize);
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& pq)
{
    theHeap = new Heap<T>(*pq.theHeap); //calls the copy constructor
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete theHeap;
}

template<typename T>
void PriorityQueue<T>::enqueue(T newEntry)
{
    theHeap->add(newEntry);
}

template<typename T>
void PriorityQueue<T>::dequeue() throw (EmptyPriorityQueue)
{
    try
    {
        theHeap->remove();
    }
    catch(EmptyHeap e)
    {
        throw EmptyPriorityQueue("Queue is empty!");
    }
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const
{
    return theHeap->isEmpty();
}

template<typename T>
T PriorityQueue<T>::peekFront() const throw (EmptyPriorityQueue)
{
    try
    {
        return theHeap->peekTop();
    }
    catch(EmptyHeap e)
    {
        throw EmptyPriorityQueue("Queue is empty!");
    }
}
