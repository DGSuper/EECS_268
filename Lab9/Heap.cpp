/**
*	@file Heap.cpp
*	@author Zachary Bruennig 
*	@date 11/21/16
*	@brief Array implementation of a heap data structure.
*/
#include "Heap.h"
#include <iostream>
template<typename T>
Heap<T>::Heap(int initialSize) //initialSize should be at least 1
{
    if(initialSize<1)
        initialSize = 1; //in case we get bad input
    sizeOfArray = initialSize;
    numItemsInHeap = 0;
    theCompleteBinaryTree = new T[sizeOfArray];
}

template<typename T>
Heap<T>::Heap(const Heap<T>& heap)
{
    sizeOfArray = heap.sizeOfArray;
    numItemsInHeap = heap.numItemsInHeap;
    theCompleteBinaryTree = new T[sizeOfArray];
    for(int i=0; i<heap.sizeOfArray; i++)
    {
       theCompleteBinaryTree[i] = heap.theCompleteBinaryTree[i]; //if this errors, change the . to a ->
    }
}

template<typename T>
Heap<T>::~Heap()
{
    delete[] theCompleteBinaryTree;
}

template<typename T>
bool Heap<T>::isEmpty() const
{
    return numItemsInHeap==0;
}

template<typename T>
T Heap<T>::peekTop() const throw (EmptyHeap)
{
    if(isEmpty())
        throw EmptyHeap("Heap is empty!");
    return theCompleteBinaryTree[0];
}

template<typename T>
void Heap<T>::swap(int i1, int i2)
{
    T temp = theCompleteBinaryTree[i1];
    theCompleteBinaryTree[i1] = theCompleteBinaryTree[i2];
    theCompleteBinaryTree[i2] = temp;
}

template<typename T>
void Heap<T>::add(T& newItem)
{    
    if(sizeOfArray==numItemsInHeap) //in the case where it's full
    {
        T* newTree = new T[2*sizeOfArray];
        for(int i=0; i<sizeOfArray; i++)
        { //copy over to the new array
            newTree[i] = theCompleteBinaryTree[i];
        }
        sizeOfArray*=2;
        
        delete[] theCompleteBinaryTree;
        
        theCompleteBinaryTree = newTree;
    }
    
    theCompleteBinaryTree[numItemsInHeap] = newItem;
    
    for(int i=numItemsInHeap; i!=0; i=(i-1)/2)
    {
        T& child = theCompleteBinaryTree[i];
        T& parent = theCompleteBinaryTree[(i-1)/2];
        if(child>parent)
            swap(i,(i-1)/2);
        else
            break;
    }
    numItemsInHeap++;
}

template<typename T>
void Heap<T>::remove() throw (EmptyHeap)
{
    if(isEmpty())
        throw EmptyHeap("Heap is empty!");
    
    numItemsInHeap--;
    theCompleteBinaryTree[0] = theCompleteBinaryTree[numItemsInHeap];
    //will be the last since we just decremented it
    //we won't worry about replacing theCompleteBinaryTree[numItemsInHeap] until we need to
        
    int i=0;
    while(i<numItemsInHeap)
    {
        if((2*i + 1) >= numItemsInHeap)
            break;
        if((2*i + 2) == numItemsInHeap) //there's no right
        {
            int iLeft = 2*i + 1;
            if(theCompleteBinaryTree[i] < theCompleteBinaryTree[iLeft])
                swap(i,iLeft);
            break; //this has to be the last one
        }
            
        int iLeft = 2*i + 1;
        int iRight = 2*i + 2;
        
        if(theCompleteBinaryTree[i] < theCompleteBinaryTree[iLeft] || theCompleteBinaryTree[i] < theCompleteBinaryTree[iRight])
        {
            if(theCompleteBinaryTree[iLeft] > theCompleteBinaryTree[iRight])
            {
                swap(i,iLeft);
                i= iLeft;
            }
            else
            {
                swap(i,iRight);
                i= iRight;
            }
        }
        else
            break;
    }
}
