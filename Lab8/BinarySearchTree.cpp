//  Subsetted from:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Zachary Bruennig on 11/12/2016

//http://stackoverflow.com/questions/15456606/binary-search-tree-class-identifier-itemtype-is-undefined

/** @file BinarySearchTree.cpp */
#include <iostream>

#include "BinarySearchTree.h" 

// PRIVATE HELPER METHODS - IMPLEMENT THESE
//KEYTYPE will be a String, the American name of the pokemon.
template<typename ItemType, typename KeyType> //definitely works
void BinarySearchTree<ItemType, KeyType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
    if(subTreePtr==nullptr)
        return;
    if(subTreePtr->isLeaf())
    {
        delete subTreePtr;
        return;
    }
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
}

template<typename ItemType, typename KeyType> //definitely works
BinaryNode<ItemType>* BinarySearchTree<ItemType,KeyType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                                                BinaryNode<ItemType>* newNodePtr)
{
    if(subTreePtr==nullptr)
        return newNodePtr;
    else
    {
        if(subTreePtr->getItem() > newNodePtr->getItem())
        {
            BinaryNode<ItemType>* left = subTreePtr->getLeftChildPtr();
            subTreePtr->setLeftChildPtr(insertInorder(left, newNodePtr));
        }
        else
        {
            BinaryNode<ItemType>* right = subTreePtr->getRightChildPtr();
            subTreePtr->setRightChildPtr(insertInorder(right, newNodePtr));
        }
        return subTreePtr; //should return rootPtr
    }
}

template<typename ItemType, typename KeyType> //definitely works
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::copyHelper(const BinaryNode<ItemType>* other) const
{
    BinaryNode<ItemType>* current = nullptr;
    if(other!=nullptr) //do a preorder traversal
    {
        current = new BinaryNode<ItemType>(other->getItem());
        current->setLeftChildPtr(copyHelper(other->getLeftChildPtr()));
        current->setRightChildPtr(copyHelper(other->getRightChildPtr()));
    }
    return current;
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType,KeyType>::findParent(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* child) const throw(NotFoundException)
{
    //Exception will be thrown if child isn't in the program OR if it's the rootPtr
    if(subTreePtr==nullptr)
        throw NotFoundException("Cannot find target node");
    ItemType item = subTreePtr->getItem();
    if(subTreePtr->getLeftChildPtr()==child || subTreePtr->getRightChildPtr()==child)
        return subTreePtr;
    BinaryNode<ItemType>* next;
    if(subTreePtr->getItem().getKeyType() > child->getItem().getKeyType()) // if we need a smaller value
        next = subTreePtr->getLeftChildPtr();
    else
        next = subTreePtr->getRightChildPtr();
    return findParent(next, child);
}


template<typename ItemType, typename KeyType> //definitely works
void BinarySearchTree<ItemType, KeyType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if(treePtr!=nullptr)
    {
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType item = treePtr->getItem();
        visit(item);
        inorder(visit, treePtr->getRightChildPtr());
    }
}

template<typename ItemType, typename KeyType> //definitely works
void BinarySearchTree<ItemType, KeyType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if(treePtr!=nullptr)
    {
        ItemType item = treePtr->getItem();
        visit(item);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
}

template<typename ItemType, typename KeyType> //definitely works
void BinarySearchTree<ItemType, KeyType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if(treePtr!=nullptr)
    {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType item = treePtr->getItem();
        visit(item);
    }
}

template<typename ItemType, typename KeyType> //definitely works
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::findNode(
                BinaryNode<ItemType>* subTreePtr, const KeyType& target) const throw(NotFoundException)
{
    if(subTreePtr==nullptr)
        throw NotFoundException("Cannot find target item");
    ItemType item = subTreePtr->getItem();
    if(item.getKeyType() == target)
    {
        return subTreePtr;
    }
    BinaryNode<ItemType>* next;
    if(item.getKeyType()>target) // if we need a smaller value
    {
        next = subTreePtr->getLeftChildPtr();
    }
    else
    {
        next = subTreePtr->getRightChildPtr();
    }
    return findNode(next, target);
}


//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType> //definitely works
BinarySearchTree<ItemType, KeyType>::BinarySearchTree() : rootPtr(nullptr)
{
    
}

template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType> //seems to be working, not sure why it returns a bool
bool BinarySearchTree<ItemType, KeyType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
        rootPtr = insertInorder(rootPtr, newNodePtr);
        if(rootPtr==newNodePtr)
            return true; //returns true if newNodePtr becomes the new root
        return false; //one of these needs to be false, not sure which one though
}

template<typename ItemType, typename KeyType> //definitely works
ItemType BinarySearchTree<ItemType, KeyType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{
    BinaryNode<ItemType>* item = findNode(rootPtr, aKey);
    return item->getItem();
}

template<typename ItemType, typename KeyType> //definitely works
bool BinarySearchTree<ItemType, KeyType>::contains(const KeyType& aKey) const
{
    try
    {
        findNode(rootPtr, aKey);
        return true; //if we reach here it must be true, otherwise an exception would have been thrown
    }
    catch(NotFoundException e)
    {
        return false;
    }
}

template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::remove(const KeyType& aKey)
{
    if(rootPtr == nullptr) //nothing to remove!
        return false;
    else if(rootPtr->getItem().getKeyType()==aKey) //node to remove is root pointer
    {
        BinaryNode<ItemType>* target = rootPtr;
        if(target->getLeftChildPtr()==nullptr && target->getRightChildPtr()==nullptr)
        {   //it's the only thing in the tree
            delete target;
            rootPtr = nullptr;
        }
        else if(target->getLeftChildPtr()==nullptr) //right one points to something
        {
            rootPtr = target->getRightChildPtr();
            delete target;
        }
        else if(target->getRightChildPtr()==nullptr)
        {
            rootPtr = target->getLeftChildPtr();
            delete target;
        }
        else //they're both defined, and we need to find the inorder successor
        {
            BinaryNode<ItemType>* successor = target->getRightChildPtr();
            BinaryNode<ItemType>* successorParent = target;
            
            while(successor->getLeftChildPtr()!=nullptr) // go left as far as possible
            {
                successorParent = successor;
                successor = successor->getLeftChildPtr();
            }
            
            ItemType item = successor->getItem();
            //successor is guaranteed to have no leftPtr
            
            //CHANGED IN NEWEST SUBMISSION
            if(successorParent!=target) //meaning inorder successor isn't directly to the right of target
                successorParent->setLeftChildPtr(successor->getRightChildPtr());
            else
                successorParent->setRightChildPtr(successor->getRightChildPtr());
            
            delete successor;
            target->setItem(item);
        }
        
        return true;
    }
    else if(!contains(aKey)) //aKey isn't in the tree
        return false;
    else //it's in the tree
    {
        BinaryNode<ItemType>* target = findNode(rootPtr, aKey);
        //guaranteed to have a parent since it's in the tree and not the rootPtr
        BinaryNode<ItemType>* parent = findParent(rootPtr, target); //it's working right.
        
        bool left = parent->getLeftChildPtr()==target; //true if the child is the leftPtr, false otherwise
        
        if(target->getLeftChildPtr()==nullptr && target->getRightChildPtr()==nullptr)
        {
            if(left)
                parent->setLeftChildPtr(nullptr);
            else
                parent->setRightChildPtr(nullptr);
            delete target;
        }
        else if(target->getLeftChildPtr()==nullptr) //right one points to something
        {
            if(left)
                parent->setLeftChildPtr(target->getRightChildPtr());
            else
                parent->setRightChildPtr(target->getRightChildPtr());
            delete target;
        }
        else if(target->getRightChildPtr()==nullptr) //left one points to something
        {
            if(left)
                parent->setLeftChildPtr(target->getLeftChildPtr());
            else
                parent->setRightChildPtr(target->getLeftChildPtr());
            delete target;
        }
        else //they're both defined, and we need to find the inorder successor
        {
            BinaryNode<ItemType>* successor = target->getRightChildPtr();
            BinaryNode<ItemType>* successorParent = target;
            
            while(successor->getLeftChildPtr()!=nullptr) // go left as far as possible
            {
                successorParent = successor;
                successor = successor->getLeftChildPtr();
            }
            
            ItemType item = successor->getItem();
            //successor is guaranteed to have no leftPtr
            if(successorParent!=target) //meaning inorder successor isn't directly to the right of target
                successorParent->setLeftChildPtr(successor->getRightChildPtr());
            else
                successorParent->setRightChildPtr(successor->getRightChildPtr());
            delete successor;
            target->setItem(item);
        }
    }
    return true;
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::copy(BinarySearchTree<ItemType, KeyType>* other)
{
    //we need to start from scratch, assume that other is initialized to something
    this->destroyTree(rootPtr);
    
    rootPtr = copyHelper(other->rootPtr);
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType> //definitely works
void BinarySearchTree<ItemType, KeyType>::inorderTraverse(void visit(ItemType&)) const
{
    inorder(visit, rootPtr);
}

template<typename ItemType, typename KeyType> //definitely works
void BinarySearchTree<ItemType, KeyType>::preorderTraverse(void visit(ItemType&)) const
{
    preorder(visit, rootPtr);
}

template<typename ItemType, typename KeyType> //definitely works
void BinarySearchTree<ItemType, KeyType>::postorderTraverse(void visit(ItemType&)) const
{
    postorder(visit, rootPtr);
}
