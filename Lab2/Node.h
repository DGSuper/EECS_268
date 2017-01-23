/**
*	@file Node.h
*	@author Zachary Bruennig 
*	@date 9/19/16
*	@brief A header file for the Node class
*/
 
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
    T m_item;
    Node* m_next;
public:
    
    /** @pre None
    *   @post Creates a node object with m_next set to nullptr and m_item set to anItem
    */
    Node<T>(T anItem);
    
    /** @pre None.
    *   @post Creates a node object with m_next set to nextNode and m_item set to anItem
    */
    Node<T>(T anItem, Node* nextNode);
    
    /** @pre None.
    *   @post None.
    *   @return the Node object in m_next
    */
    Node<T>* getNext() const;
    
    /** @pre None.
    *   @post None.
    *   @return m_item
    */
    T getItem() const;
    
    /** @pre nextNode has already been initialized
    *   @post m_next is set to nextNode
    */
    void setNext(Node* nextNode);
    
    /** @pre None
    *   @post m_item is set to value
    */
    void setValue(T value);
};


#endif
