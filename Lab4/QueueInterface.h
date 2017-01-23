//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified (JRM): Use Exceptions
//  I (Zachary Bruennig) did not write any of the code in this file

/** Listing 13-1.
 @file QueueInterface.h */

#ifndef QUEUE_INTERFACE
#define QUEUE_INTERFACE

#include "PreconditionViolatedException.h"

template<typename T>
class QueueInterface
{
public:
   /** Sees whether this queue is empty.
    @return True if the queue is empty, or false if not. */

   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the back of this queue.
    @post If the operation was successful, newEntry is at the back of the queue.
    @param newEntry  The object to be added as a new entry.
    @throw PreconditionViolatedException if no memory available for the new item */

   virtual void enqueue(const T& newEntry) throw (PreconditionViolatedException) = 0;
   
   /** Removes the front of this queue.
    @post If the operation was successful, the front of the queue has been removed.
    @throw PreconditionViolatedException if the queue is empty when called */

   virtual void dequeue() throw (PreconditionViolatedException) = 0;
   
   /** Returns the front of this queue.
    @pre The queue is not empty.
    @post The front of the queue has been returned, and the queue is unchanged.
    @throw PreconditionViolatedException if the queue is empty when called */

   virtual T peekFront() const throw (PreconditionViolatedException) = 0;
}; // end QueueInterface
#endif 
