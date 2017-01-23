/**
*	@file MazeReader.h
*	@author Zachary Bruennig
*	@date 10/22/16
*	@brief Attempts to read in a properly formatted file and create a character array from
*       the parameters and character matrix in the file. The matrix should only contain W, P, and Es.
*       The file should start with four numbers. The first two are the number of rows and number of columns in
*       the matrix, respectively. The third and fourth are the starting row column for the maze, respectively.
*       The size of the matrix should match the first two numbers in the file. If the size is smaller,
*       anexception will be thrown. If it is larger, it will only read the matrix up to the file's parameters,
*       namely, up to the first number for rows, and the second number for columns
*/

#ifndef MAZEREADER_H
#define MAZEREADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "MazeCreationException.h"


class MazeReader
{
    public:
	/**
	*	@post A MazeReader is created. A 2D char array is allocated with the maze information.
	*	@throws MazeCreationExecption
	*
	*/
	MazeReader(std::string file) throw (MazeCreationException);

	/**
	*	@post The maze is deallocated.
	*/
	~MazeReader();

	/**
	*	@pre the file was formatting and read in correctly
	*	@return Returns pointer to the maze
	*/
	const char* const* getMaze() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of columns listed in the file
	*/
	int getCols() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of rows listed in the file
	*/
	int getRows() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting column
	*/
	int getStartCol() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting row
	*/
	int getStartRow() const;
        
        /**
         *      @returns true if the maze was formatted well and properly read in, false otherwise
         */
        bool isValidMaze() const;

	private:
	/**
	*	@pre the file is properly formatted
	*	@post the characters representing the maze are stores
	*/
	void readMaze()	throw (MazeCreationException);	
        
        int m_startRow;
        int m_startCol;
        int m_numRows;
        int m_numCols;
        char** m_maze;
        std::ifstream m_inFile;
        bool m_deleteArrays = false; //used in destructor
        int m_valid = true; //will be false if an error is thrown, accessed through isValidMaze()
};
#endif
