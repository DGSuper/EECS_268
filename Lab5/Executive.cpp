/**
*	@file Executive.cpp
*	@author Zachary Bruennig
*	@date 10/7/16
*	@brief Contains several methods utilizing recursion. User starts in run, and run will call all
*              following methods
*/

#include "Executive.h"

int Executive::combinationsHelper(int n, int highestRemaining)
{
    if(n<0)
        return -1;
    
    if(highestRemaining == 0 || highestRemaining == 1)
        return 1;
    
    int total = 0;
    for(int i=highestRemaining; i>0; i--)
    {
        if(i<=n)
            total+=combinationsHelper(n-i, i);
    }
    return total;
}

int Executive::combinations(int n)
{
    return combinationsHelper(n+1, n+1) - 1;
}

int Executive::permutationsHelper(int n)
{
    if(n<=0)
        return -1;
    
    if(n==1)
        return 1;
    
    int total = 0;
    for(int i=1; i<n; i++)
    {
        total += permutationsHelper(n-i);
    }
    
    total+=1; //just n
    
    return total; 
    
    
}

int Executive::permutations(int n)
{
    return permutationsHelper(n) - 1; //should return 2^n-1 - 1
}

void Executive::compute()
{
    int n = 0;
    std::cout << "Input a number to compute: ";
    while(n<=0) //Maybe try/catch this?
    {
        std::cin >> n;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
        }
    }
    char input = ' ';
    std::cout << "Include permutations? (y/n): ";
    while(input!='y' && input!='Y' && input!='n' && input!='N')
    {
        std::cin >> input;
    }
    
    if(input=='y' || input=='Y')
    {
        int numPermutations = permutations(n); //this might take a while to calculate
        std::cout << "There are " << numPermutations << " permutations of " << n << ".\n";
    }
    else if(input=='n' || input=='N')
    {
        int numCombinations = combinations(n); //this might take a little less time to calculate, but still a while
        std::cout << "There are " << numCombinations << " combinations of " << n << ".\n";
    }
}

void Executive::listReversal()
{
    std::string fileName;
    std::ifstream inFile;
    LinkedList<std::string>* list = new LinkedList<std::string>;
    
    std::cout << "Input a file name: ";
    std::cin >> fileName;
    inFile.open(fileName);
    
    if(!inFile.is_open())
    {
        std::cout << "Error: invalid file name\n";

    }
    else
    {
        while(!inFile.eof())
        {
            std::string curr;
            inFile >> curr;
            list->addBack(curr);
        }
        std::cout << "Your list contains:\n";
        for(int i=1; i<=list->getLength(); i++) //prints out list
        {
            std::cout << list->getEntry(i) << '\n';
        }
        
        list->reverseList(); //reverses list
        
        std::cout << "The list is now reversed! It contains:";
        for(int i=1; i<=list->getLength(); i++) //prints out reversed list
        {
            std::cout << list->getEntry(i) << '\n';
        }
    }
    
    inFile.close();
    delete list;
}

void Executive::reportSimpleCellsIn(int Q[64][64], int firstRow, int lastRow, int firstCol, int lastCol)
{
    int count = 0;
    for(int i=firstRow; i<=lastRow; i++)
    {
        for(int j=firstCol; j<=lastCol; j++)
        {
            if(Q[i][j]==1)
                count++;
        }
    }
    
    if(count==0)
    {
        std::cout << "Row " << firstRow << " to " << lastRow << ", Column " << firstCol << " to " << lastCol << ": EMPTY\n";
    }
    else if(count==1)
    {
        std::cout << "Row " << firstRow << " to " << lastRow << ", Column " << firstCol << " to " << lastCol << ": ONE\n";
    }
    else
    {
        int midRow = (firstRow + lastRow)/2;
        int midCol = (firstCol + lastCol)/2;
        reportSimpleCellsIn(Q, firstRow, midRow, firstCol, midCol); //NW
        reportSimpleCellsIn(Q, firstRow, midRow, midCol+1, lastCol); //NE
        reportSimpleCellsIn(Q, midRow+1, lastRow, midCol+1, lastCol); //SE
        reportSimpleCellsIn(Q, midRow+1, lastRow, firstCol, midCol); //SW
    }
}

void Executive::quadtree() throw (std::runtime_error)
{
    std::string fileName;
    std::ifstream inFile;
    std::cout << "Input a file containing a 64 x 64 matrix of bits: ";
    std::cin >> fileName;
    inFile.open(fileName);
    if(!inFile.is_open())
    {
        throw std::runtime_error("Error: Invalid file name\n");
    }
    else
    {
        int Q[64][64];
        for(int row=0; row<64; row++) //fills 64x64 array with values from file
        {
            for(int col=0; col<64; col++)
            {
                std::string curr;
                inFile >> curr;
                if(curr!= "1" && curr!= "0") //if it's formatted improperly, this will actually check two things
                //does the file only contain 1s and 0s, and is it long enough?
                    throw std::runtime_error("Error: Invalid file format\n");
                int currInt = std::stoi(curr);
                Q[row][col] = currInt;                
            }
        }
        reportSimpleCellsIn(Q, 0, 63, 0, 63);
    }
}

void Executive::run()
{
    while(true)
    {
        char option = ' ';
        std::cout << "\nSelect an option:\n";
        std::cout << "1. List Reversal\n";
        std::cout << "2. Compute partitions for a number\n";
        std::cout << "3. Report a quadtree\n";
        std::cout << "4. Quit\n";
        
        while(option!='1' && option!='2' && option!='3' && option!='4')
            std::cin >> option;
        
        if(option=='1')
            listReversal();
        
        if(option=='2')
            compute();
        
        if(option=='3')
        {
            try
            {
                quadtree();
            }
            catch(std::runtime_error e)
            {
                std::cout << e.what();
            }
        }
        if(option=='4')
        {
            std::cout << "Thanks for using this program!\nBye.\n";
            break; //only happens if option = '4'
        }
    }
}
