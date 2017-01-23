/**
*	@file Executive.h
*	@author Zachary Bruennig 
*	@date 11/12/16
*	@brief Header file for Executive. Executive is basically the foundation for the rest of the program, 
*       so that the BST and Pokemon classes work easily together. 
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Pokemon.h"
#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Executive
{
private:
    bool m_fileExists = false;
    bool m_isCopyInitialized = false;
    std::ofstream m_outFile;
    BinarySearchTree<Pokemon, std::string>* m_pokedex;
    BinarySearchTree<Pokemon, std::string>* m_copy;
    
    /** All the test methods are pass by reference. Calling them will only make temporary changes,
     *  just to test the output */
    void testAdds(BinarySearchTree<Pokemon, std::string> bst);
    void testRemoves(BinarySearchTree<Pokemon, std::string> bst);
    void testWriteToFile(BinarySearchTree<Pokemon, std::string> bst);
    
    /** Makes the names and inputs follow a common scheme, effectively making the input case insensitive */
    std::string standardize(std::string input);
    
    /** Prints the tree. Pass this method into a traverse method. */
    static void printTree(Pokemon& curr);
    
    /** Creates an output file for a tree. save will pass writeOutput into a traverse method. */
    void save(std::string fileName, bool copy, int traversal);
    static void writeOutput(Pokemon& curr);
public:
    /** Constructor. Tries to open the file. Program can't do anything else otherwise. */
    Executive(std::string fileName);
    
    /** Destructor. Deletes things. */
    ~Executive();
    
    /** Handles almost all i/o. This is the part with the menu that loops that takes in the user input. */
    void run();
};
#endif
