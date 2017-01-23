/**
*	@file Node.cpp
*	@author Zachary Bruennig 
*	@date 9/19/16
*	@brief A Node class to be used in conjunction with the LinkedList class.
*/

#include "Node.h"

template <typename T>
Node<T>::Node(T anItem)
{
    m_item = anItem;
    m_next = nullptr;
}

template <typename T>
Node<T>::Node(T anItem, Node* nextNode)
{
    m_item = anItem;
    m_next = nextNode;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
    return m_next;
}

template <typename T>
T Node<T>::getItem() const
{
    return m_item;
}

template <typename T>
void Node<T>::setNext(Node* nextNode)
{
    m_next = nextNode;
}

template <typename T>
void Node<T>::setValue(T value)
{
    m_item = value;
}
