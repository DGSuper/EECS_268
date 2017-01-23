/**
*	@file Sort.h
*	@author Zachary Bruennig
*	@date 10/22/16
*	@brief Header class for the Sort class, which combines all the methods from
*       quicksort, merge sort, insertion sort, bubble sort, and selection sort
*/
#ifndef SORT_H
#define SORT_H

template<class ItemType>
class Sort
{

public:
    
    Sort(){};
    void quickSort(ItemType theArray[], int n);
    void bubbleSort(ItemType theArray[], int n);
    void mergeSort(ItemType theArray[], int n);
    void insertionSort(ItemType theArray[], int n);
    void selectionSort(ItemType theArray[], int n);
    
private:
    //QUICKSORT METHODS
    void order(ItemType theArray[], int i, int j);
    int sortFirstMiddleLast(ItemType theArray[], int first, int last);
    int partition(ItemType theArray[], int first, int last);
    void quickSort(ItemType theArray[], int first, int last);
    void insertionSort(ItemType theArray[], int first, int last);
    
    static const int MIN_SIZE  = 10; // Smallest size of an array that quicksort will sort
    
    //MERGESORT METHODS
    void mergeSort(ItemType theArray[], int first, int last, ItemType tempArray[]);
    void merge(ItemType theArray[], int first, int mid, int last, ItemType tempArray[]);
    
    //SELECTIONSORT METHODS
    int findIndexofLargest(const ItemType theArray[], int size);
};

#include "Sort.cpp"

#endif
