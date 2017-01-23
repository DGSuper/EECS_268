/**
*	@file main.cpp
*	@author Zachary Bruennig
*	@date 10/22/16
*	@brief Attempts to run MazeReader and, if successful, creates an instance of MazeRunner
*       and runs it. main will call reportOutput to print the results
*/

#include <iostream>
#include <string>
#include "MazeReader.h"
#include "MazeCreationException.h"
#include "MazeWalker.h"

/**
 * Handles all the printing of MazeWalker
 * 
 * @pre m and maze are a valid MazeReader and MazeRunner
 *      that is, m.isValidMaze() is true and maze is created from the data in m
 */
void reportOutput(MazeReader& m, MazeWalker& maze)
{
    const char* const* charMaze = m.getMaze();
    if(charMaze[m.getStartRow()][m.getStartCol()]=='W') //we start in a wall
    {
        std::cout << "Invalid starting position\n";
        return;
    }
    else //the above if statement is the only time we don't print this out
    {
        std::cout << "Starting position: " << m.getStartRow() << "," << m.getStartCol() << '\n'; 
        std::cout << "Size: " << m.getRows() << "," << m.getCols() << '\n';
    }
        
    bool exitExists = false;
    for(int i=0; i<m.getRows(); i++)
    {
        for(int j=0; j<m.getCols(); j++)
        {
            if(charMaze[i][j]=='E')
                exitExists = true;
        }
    }
    if(!exitExists) //there is no exit
    {
        std::cout << "No way out!\n";
        return;
    }
    
    if(maze.walkMaze()) //true if we can navigate the maze to the exit, false otherwise
    {
        const int* const* exitRoute = maze.getVisited();
        
        for(int i=0; i<maze.getVisitedRows(); i++)
        {
            for(int j=0; j<maze.getVisitedCols(); j++)
                std::cout << exitRoute[i][j] << " "; //prints out the maze
            
            std::cout << '\n';
        }
        std::cout << "We escaped!\n";
    }
    else
    {
        std::cout << "No way out!\n";
    }
}

int main(int argc, char** argv)
{
    if(argc>=2)
    {
        std::string fileName = argv[1];
        try
        {
            MazeReader m(fileName);
            if(m.isValidMaze())
            {    
                MazeWalker maze(m.getMaze(), m.getStartRow(), m.getStartCol(), m.getRows(), m.getCols());
                reportOutput(m, maze);
            }
        }
        catch(MazeCreationException e)
        {
            std::cout << e.what() << "\n";
        }
        return 0;
    }
    else
    {
        std::cout << "Error: invalid number of arguments. One required.\n";
        return 0;
    }
}
