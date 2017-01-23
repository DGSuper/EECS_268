//  Subsetted from:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Zachary Bruennig on 11/12/2016

// Listing 16-4.


/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */
 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"
#include "NotFoundException.h"

template<typename ItemType, typename KeyType>
class BinarySearchTree
{
private:
   BinaryNode<ItemType>* rootPtr;
   
   // Recursively deletes all nodes from the tree.
   void destroyTree(BinaryNode<ItemType>* subTreePtr);

   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
                                       BinaryNode<ItemType>* newNode);
   
   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
                                  const KeyType& target) const throw(NotFoundException);
                                  
   // Helper method for copy. Does the recursive part.          
   BinaryNode<ItemType>* copyHelper(const BinaryNode<ItemType>* other) const;
   
   // Pass in rootPtr to subtreePtr. This method will find the node that points to child, if it exists.
   // Throws an exception if child is the rootPtr or child isn't in the tree.
   BinaryNode<ItemType>* findParent(BinaryNode<ItemType>* subtreePtr, BinaryNode<ItemType>* child) const throw(NotFoundException);
                                  
   //Traversal helper methods
   void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   BinarySearchTree(BinarySearchTree<ItemType, KeyType>* other) {copy(other);}
   virtual ~BinarySearchTree();
   
   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool add(const ItemType& newEntry);
   ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);
   bool contains(const KeyType& aKey) const;
   
   // Removes a node from the tree, while keeping all the properties of BSTs intact.
   // Returns true if the removal was successful, false otherwise. If it returns false aKey was not found.
   bool remove(const KeyType& aKey);
   
   //sets all the nodes in the tree to be exactly like a different tree
   void copy(BinarySearchTree<ItemType, KeyType>* other);
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void inorderTraverse(void visit(ItemType&)) const;
   void preorderTraverse(void visit(ItemType&)) const;
   void postorderTraverse(void visit(ItemType&)) const;
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
