/**
*	@file MazeWalker.h
*	@author Zachary Bruennig
*	@date 10/22/16
*	@brief Given a char array consisting only of 'W', 'P' and 'E', and a starting row and column,
*       this will recursively try to solve the "maze". 'W' represents a wall, 'P' represents the path,
*       and 'E' represents an exit (there can be multiple, or none). Following the specifications, this
*       will always make the recursive calls in a clockwise order, starting with going Up.
*       This means the given solutions might not be the shortest, but it will still be valid.
*/

#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include <string>

class MazeWalker
{
	public:
	/**
	*	@pre The mazePtr pointer is to a valid maze.
	*	@post A maze walker if created ready to traverse the maze from the start position is the specified order.
	*/
	MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols);

	/**
	*
	*	@pre The visited array still exists and has the same dimensions (rows X cols)
	*	@post The visited array is deallocated
	*/
	~MazeWalker();

	/**
	*	@pre The maze is a valid maze.
	*	@post The maze is traversed until the end is reached or all moves are exhausted. 
	*	@return true if an exit was reached, false otherwise
	*/
	bool walkMaze();

	/**
	*	@return A const pointer to the visited array. (A pointer that cannot change the array)
	*/
	const int* const* getVisited() const;

	/**
	*	@return number of rows in maze
	*/
	int getVisitedRows() const;

	/**
	*	@return number of cols in maze
	*/
	int getVisitedCols() const;

	/**
	*	@return A const pointer to the maze. (A pointer that cannot change the array)
	*/
	const char* const* getMaze() const;

        private:  

	/**
	*	@returns If the current position is the exit, true is returned. False is returned otherwise.
	*/		
	bool isGoalReached() const;
        
        /**
         *     @pre directions is a String consisting of only U, D, L, and Rs (representing up, down, left, right) 
         *     @returns True, if the # of Ls equals the # of Rs, and if the # of Us equals the # of Ds, else false
         */
        bool isBalancedString(std::string directions) const;
        
        /**    
         *     @brief This is a recursive method that will try to move in all four cardinal directions in the maze
         *     until it reaches the end ('E'). previousMoves will be used to keep track of our progress
         *     @param curRow the current (starting for the first call) row position
         *     @param curCol the current (starting for the first call) column position
         *     @param previousMoves When this is initially called, this should be an empty string.
         *     As this is called recursively, it will be populated with the
         *     previous moves in that recursive sequence.
         *     @return True if the maze can be navigated from the current position to the exit, false otherwise
         */
        bool traverse(int curRow, int curCol, std::string previousMoves);
        
        /**
         *      @returns True only if the [row][column] index wouldn't cause a segfault if called in m_maze, 
         *      and if that index isn't a 'W', false otherwise
         */
        bool isValid(int row, int col) const;
	
	const char* const* m_maze;
	int** m_visited;
	int m_rows, m_cols;
	int m_curRow, m_curCol;
	int m_startRow, m_startCol;
	
	int m_curStep; //completely unused
};
#endif
