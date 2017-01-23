 
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified (JRM): throw exceptions instead of return bool success codes
//  I (Zachary Bruennig) did not write any of the code in this file
/** @file StackInterface.h */

#ifndef STACK_INTERFACE
#define STACK_INTERFACE

#include "PreconditionViolatedException.h"

template<typename T>
class StackInterface
{
public:
   /** Sees whether this stack is empty.
    @return True if the stack is empty, or false if not. */

   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the top of this stack.
    @post If the operation was successful, newEntry is at the top of the stack.
    @param newEntry The object to be added as a new entry.
    @throw PreconditionViolatedException if no memory available for the new item */
   virtual void push(const T& newEntry) throw (PreconditionViolatedException) = 0;
   
	/** Removes the top of this stack.
	@pre The stack is not empty.
    @post If the operation was successful, the top of the stack has been removed.
    @throw PreconditionViolatedException if the stack is empty when called */
   virtual void pop() throw (PreconditionViolatedException) = 0;
   
   /** Returns the top of this stack.
    @pre The stack is not empty.
    @post The top of the stack has been returned, and the stack is unchanged.
    @return The top of the stack.
    @throw PreconditionViolatedException if the stack is empty when called */
   virtual T peek() const throw (PreconditionViolatedException) = 0;

}; // end StackInterface
#endif
