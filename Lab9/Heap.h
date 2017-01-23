/**
*	@file Heap.h
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief Array-based implementation of a Heap. Throws EmptyHeap if remove or peekTop is called when
*       numItemsInHeap is zero. Implemented according to specifications. Only helper method added is swap,
*       which swaps the two items at the given indices in theCompleteBinaryTree
*/


#ifndef HEAP_H
#define HEAP_H

#include "EmptyHeap.h"

template<typename T>
class Heap
{
public:
    Heap(int initialSize);
    Heap(const Heap<T>& heap); //copy constructor
    ~Heap();
    
    /**
     * Adds another T to the heap.
     * @pre T is initialized
     */
    void add(T& newItem);
    
    /**
     * Returns true if numItemsInHeap is 0, false otherwise
     */
    bool isEmpty() const;
    
    /**
     * Removes the T at the top of the heap, if it exists. Maintains heap ordering property
     * @throw EmptyHeap if Heap is empty
     */
    void remove() throw (EmptyHeap);
    
    /**
     * Returns the T at the top of the heap, if it exists.
     * @throw EmptyHeap if the Heap is empty
     */
    T peekTop() const throw (EmptyHeap);
private:
    T* theCompleteBinaryTree;
    int sizeOfArray;
    int numItemsInHeap;
    
    //Swaps two values in theCompleteBinaryTree
    void swap(int i1, int i2);
};

#include "Heap.cpp"

#endif
