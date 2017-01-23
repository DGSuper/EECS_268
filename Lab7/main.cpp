/**
*	@file Sort.h
*	@author Zachary Bruennig
*	@date 10/22/16
*	@brief Runs and times a sort given from the command line, prints the time it takes to sort
*/

#include "Sort.h"
#include <ctime> //used for timing
#include <string>
#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc<=3)
    {
        std::cout << "Invalid number of arguments. Please format as:\nLab7 <data_size> <random|ascending|descending> <selection|insertion|bubble|merge|quick>\n";
        return 0;
    }
    else
    {
        try
        {
            std::string nStr = argv[1];
            int n = std::stoi(nStr);
            std::string format = argv[2];
            std::string sort = argv[3];
            
            if(n<=0)
            {
                std::cout << "Data size must be positive.\n";
                return 0;
            }
            
            double* nums = new double[n];
            
            if(format=="random")
            {
                srand48(1427683); //My roomate's favorite number
                for(int i=0; i<n; i++)
                {    
                    nums[i] = drand48();
                }
            }
            else if(format=="ascending")
            {
                for(int i=0; i<n; i++)
                    nums[i] = 0.001*static_cast<double>(i);
            }
            else if(format=="descending")
            {   
                for(int i=0; i<n; i++)
                    nums[i] = 0.001*static_cast<double>(n-i-1);
            }
            else
            {
                std::cout << "Invalid order. Please enter <random|ascending|descending>\n";
                return 0;
            }

            std::clock_t start;
            double duration;
            
            Sort<double> sorts;
            
            if(sort=="selection")
            {
                start = std::clock();
                
                sorts.selectionSort(nums, n); //this is getting timed
                
                duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
                std::cout << duration << '\n';
            }
            else if(sort=="insertion")
            {
                start = std::clock();
                
                sorts.insertionSort(nums, n); //this is getting timed
                
                duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
                std::cout << duration << '\n';
            }
            else if(sort=="bubble")
            {
                start = std::clock();
                
                sorts.bubbleSort(nums, n); //this is getting timed
                
                duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
                std::cout << duration << '\n';
            }
            else if(sort=="merge")
            {
                start = std::clock();
                
                sorts.mergeSort(nums, n); //this is getting timed
                
                duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
                std::cout << duration << '\n';
            }
            else if(sort=="quick")
            {
                start = std::clock();
                
                sorts.quickSort(nums, n); //this is getting timed
                
                duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
                std::cout << duration << '\n';
            }
            else
            {
                delete[] nums;
                std::cout << "Invalid sort. Please enter <selection|insertion|bubble|merge|quick>\n";
                return 0;
            }
            
        delete[] nums;
            
            
        }
        catch(std::invalid_argument e)
        {
            std::cout << "Invalid parameters: Insert a positive data size as the second argument.\n";
        }
        return 0;
    }
}
