/**
*	@file MazeReader.cpp
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

#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
    m_inFile.open(file);
    if(!m_inFile.is_open())
    {   
        m_valid = false;
        throw MazeCreationException("Cannot open file");
    }
    
    try
    {
        readMaze();
    }
    catch(MazeCreationException e)
    {
        m_inFile.close();
        std::cout << e.what() << '\n';
    }
    m_inFile.close();
}

MazeReader::~MazeReader()
{
    if(m_deleteArrays)
    {    
        for(int i=0; i<m_numRows; i++)
            delete[] m_maze[i];
        delete[] m_maze;
    }
    
}

const char* const* MazeReader::getMaze() const
{
    return m_maze;
}

int MazeReader::getCols() const
{
    return m_numCols;
}

int MazeReader::getRows() const
{
    return m_numRows;
}

int MazeReader::getStartCol() const
{
    return m_startCol;
}

int MazeReader::getStartRow() const
{
    return m_startRow;
}

bool MazeReader::isValidMaze() const
{
    return m_valid;
}

void MazeReader::readMaze() throw (MazeCreationException)
{
    m_inFile >> m_numRows;
    m_inFile >> m_numCols;
    m_inFile >> m_startRow;
    m_inFile >> m_startCol;
    
    if(m_numRows<1)
    {
        m_valid = false;
        throw MazeCreationException("Invalid number of rows");
    }
    if(m_numCols<1)
    {
        m_valid = false;
        throw MazeCreationException("Invalid number of columns");
    }
    if(m_startRow>m_numRows || m_startCol>m_numCols || m_startRow<0 || m_startCol<0)
    {
        m_valid = false;
        throw MazeCreationException("Invalid starting position");
    }
    
    m_maze = new char*[m_numRows];
    m_deleteArrays = true;
    
    for(int i=0; i<m_numRows; i++)
    {   
        m_maze[i] = new char[m_numCols];
        std::string currentRow;
        m_inFile >> currentRow;
        
        for(int j=0; j<m_numCols; j++)
        {
            char curr = currentRow.at(j);
            if(curr!= 'E' && curr!= 'W' && curr!= 'P')
                throw MazeCreationException("Unexpected character in maze");
            m_maze[i][j] = curr;
        }
    }
    
    if(m_maze[m_startRow][m_startCol]=='W')
    {
        m_valid = false;
        throw MazeCreationException("Invalid starting position");
    }

//  TEST CODE THAT PRINTS OUT THE ARRAY    

//     for(int i=0; i<m_numRows; i++)
//     {
//         for(int j=0; j<m_numCols; j++)
//         {
//             std::cout << m_maze[i][j];
//         }
//         std::cout << '\n';
//     }
        
}
