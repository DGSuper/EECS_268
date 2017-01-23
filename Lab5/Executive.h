/**
*	@file Executive.h
*	@author Zachary Bruennig
*	@date 10/7/16
*	@brief Header file for Executive.cpp. Defines multiple recursive methods assigned in this lab
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

class Executive
{
private:
    /**
     * @param n a positive integer
     * @return number of unique ways to combine positive integers smaller than n which sum up to n
     */
    int combinations(int n);
    
    /**
     * @param n a positive integer
     * @param highestRemaining, should initially be the same as n, will change in subsequent recursive calls
     * @return number of unique ways to combine positive integers smaller or equal to than n+1 which sum up to n
     */
    int combinationsHelper(int n, int highestRemaining);
    
    /**
     * @param n a positive integer
     * @return number of ways to combine positive integers smaller than n which sum up to n, including duplicates
     */
    int permutations(int n);
    
    /**
     * @param n a positive integer
     * @return 1 more than permutations should return
     */
    int permutationsHelper(int n);
    
    /**
     * @param Q a 64x64 int array filled with only 0s or 1s. 
     * Should really be a bool array but that's not my choice
     * @param firstRow index of the first row in the region to be considered
     * @param lastRow index of the last row in the region to be considered
     * @param firstcol index of the first column in the region to be considered
     * @param lastcol index of the last column in the region to be considered
     * Reports if the specified region has exactly one 1 or zero 1s. If it has more, it recursively splits 
     * into four equal subsections and determines if any of those have exactly one or zero 1s. 
     */
    void reportSimpleCellsIn(int Q[64][64], int firstRow, int lastRow, int firstCol, int lastCol);
    
    /**
     * Reads in a text file, saves every word of it in a LinkedList, prints out the LinkedList.
     * It then reverses the LinkedList, and prints out the newly-reversed LinkedList
     */
    void listReversal();
    
    /**
     * Takes in a number from the user, and if the algorithm should include permuatations or not
     * Prints out the result of combinations(n) or permuatations(n)
     */
    void compute();
    
    /**
     * Reads in a text file filled with 64x64 bits (1s or 0s), creates a 64x64 array of them, then calls
     * reportSimpleCellsIn to report the data
     * @throw std::runtime_error if the filename is incorrect or the file is formatted incorrectly
     */
    void quadtree() throw (std::runtime_error);
public:  
    /**
     * Main i/o method. Gives the user a menu with different options, which call other methods
     */
    void run();
};
#endif
