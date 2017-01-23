/**
*	@file MazeWalker.cpp
*	@author Zachary Bruennig
*	@date 10/22/16
*	@brief Implementation of MazeWalker.h
*       Given a char array consisting only of 'W', 'P' and 'E', and a starting row and column,
*       this will recursively try to solve the "maze". 'W' represents a wall, 'P' represents the path,
*       and 'E' represents an exit (there can be multiple, or none). Following the specifications, this
*       will always make the recursive calls in a clockwise order, starting with going Up.
*       This means the given solutions might not be the shortest, but it will still be valid.
*/
#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols)
{
    m_maze = mazePtr;
    m_startRow = startRow;
    m_startCol = startCol;
    m_rows = rows;
    m_cols = cols;
    
    m_visited = new int*[rows];
    for(int i=0; i<rows; i++)
    {
        m_visited[i] = new int[cols];
    }
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            m_visited[i][j]=0;
        }
    }
}

MazeWalker::~MazeWalker()
{
    for(int i=0; i<m_rows; i++)
        delete[] m_visited[i];
    delete[] m_visited;
}

const int* const* MazeWalker::getVisited() const
{
    return m_visited;
}

int MazeWalker::getVisitedRows() const
{
    return m_rows;
}

int MazeWalker::getVisitedCols() const
{
    return m_cols;
}

const char* const* MazeWalker::getMaze() const
{
    return m_maze;
}

bool MazeWalker::isGoalReached() const
{
    return m_maze[m_curRow][m_curCol] == 'E';
}

bool MazeWalker::walkMaze()
{
    return traverse(m_startRow, m_startCol, "");
}

bool MazeWalker::isBalancedString(std::string directions) const
{
    /**
     * Checks to see if there's the same number of left moves as right (no net horizontal change)
     * And if there's the same number of up moves as down moves (no net vertical change)
     */
    int u=0, d=0, l=0, r=0;
    for(unsigned int i=0; i<directions.length(); i++)
    {
        char cur = directions.at(i);
        if(cur=='U')
            u++;
        if(cur=='D')
            d++;
        if(cur=='L')
            l++;
        if(cur=='R')
            r++;
    }
    return(u==d && l==r);
}

bool MazeWalker::isValid(int row, int col) const
{
    return(row>=0 && row<m_rows && col>=0 && col<m_cols && m_maze[row][col]!='W');
    //it's still in the maze and it's not in a wall
}

bool MazeWalker::traverse(int curRow, int curCol, std::string previousMoves) //L=left, R=right, U=up, D=down
{
    m_curRow = curRow;
    m_curCol = curCol;
    
    /* We will end up at a previous position if any substring from any index i to the end contains
     * the same amount of Ls as Rs, and the same amount of Us as Ds
     * If that happens, we're repeating our steps and should stop.
     */
 
    int length = previousMoves.length();
    for(int i=length-1; i>=0; i--)//starting at length would try to balance an empty string
    {
        if(isBalancedString(previousMoves.substr(i,length)))
            return false;
    }
    
    // "if(m_maze[curRow][curCol]=='E')" would have been a simpler implementation, 
    // but according to the assignment I HAVE to do it this way. 
    if(isGoalReached())
    {
        m_visited[curRow][curCol] = previousMoves.length()+1;
        return true;
    }
    
    if(isValid(curRow-1,curCol)) //try going up
    {   
        //std::cout << previousMoves << " Recursive call Up\n"; // some test code
        if(traverse(curRow-1,curCol,previousMoves+"U"))
        {
            m_visited[curRow][curCol] = previousMoves.length()+1;
            return true;
        }
    }
    if(isValid(curRow,curCol+1)) //try going right
    {   
        //std::cout << previousMoves << " Recursive call Right\n"; // some test code
        if(traverse(curRow,curCol+1,previousMoves+"R"))
        {
            m_visited[curRow][curCol] = previousMoves.length()+1;
            return true;
        }
    }
    if(isValid(curRow+1, curCol)) //try going down
    {
        //std::cout << previousMoves << " Recursive call Down\n"; // some test code
        if(traverse(curRow+1,curCol,previousMoves+"D"))
        {
            m_visited[curRow][curCol] = previousMoves.length()+1;
            return true;
        }
    }
    if(isValid(curRow, curCol-1)) //try going left
    {
        //std::cout << previousMoves << " Recursive call Left\n"; // some test code
        if(traverse(curRow,curCol-1,previousMoves+"L"))
        {
            m_visited[curRow][curCol] = previousMoves.length()+1;
            return true;
        }
    }
    //if we get here, there's no valid moves and we're surrounded by walls
    return false;
}
