/**
*	@file LinkedList.cpp
*	@author Zachary Bruennig 
*	@date 9/19/16
*	@brief A list data structure template which contains a pointer to a chain of nodes and methods
*              to manipulate and access that chain.
*/

#include "LinkedList.h"
#include "Node.cpp"
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList()
{
        m_front = nullptr;
        m_length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* curr = m_front;
    while(curr!=nullptr)
    {
        Node<T>* next = curr->getNext();
        delete curr;
        curr = next;
        m_length--;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return (m_front==nullptr);
}

template <typename T>
int LinkedList<T>::getLength() const
{
    return m_length;
}

template <typename T>
int LinkedList<T>::positionOf(T value) const
{
    int pos = 0;
    Node<T>* curr = m_front;
    while(curr!=nullptr)
    {
        pos++;
        if(curr->getItem()==value)
            return pos;
        else
            curr = curr->getNext();
    }
    return 0;
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
    Node<T>* curr = m_front;
    if(curr == nullptr) //FIXED THIS IN LAB 5
        addFront(value);
    else
    {
        Node<T>* newNode = new Node<T>(value);
        while(curr->getNext()!=nullptr)
            curr = curr->getNext();
        curr->setNext(newNode);
        m_length++;
    }    
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
    Node<T>* oldFront = m_front;
    Node<T>* newFront = new Node<T>(value);
    newFront->setNext(oldFront);
    m_front = newFront;
    m_length++;
}

template <typename T>
bool LinkedList<T>::insert(int position, T value)
{
    if(position < 1 || position > m_length+1)
        return false;
    else
    {
        if(position==1)
        {
            addFront(value);
            return true;
        }
        if(position==m_length+1)
        {
            addBack(value);
            return true;
        }
        Node<T>* curr = m_front;
        int currentPos = 2; //because 1 would be at the start of the LinkedList
        while(position>currentPos)
        {
            curr = curr->getNext();
            currentPos++;
        }
        Node<T>* newNode = new Node<T>(value);
        newNode->setNext(curr->getNext());
        curr->setNext(newNode);
        m_length++;
        return true;
    }
}

template <typename T>
bool LinkedList<T>::removeBack()
{
    if(m_front==nullptr)
        return false;
    Node<T>* curr = m_front->getNext();
    Node<T>* prev = m_front;
    while(curr->getNext()!=nullptr)
    {
        curr = curr->getNext();
        prev = prev->getNext();
    }
    //curr should be the last item in the list, prev the one before it
    prev->setNext(nullptr);
    delete curr;
    m_length--;
    return true;
}

template <typename T>
bool LinkedList<T>::removeFront()
{
    if(m_front==nullptr)
        return false;
    Node<T>* oldFront = m_front;
    Node<T>* newFront = m_front->getNext();
    m_front = newFront;
    delete oldFront;
    m_length--;
    return true;
}

template <typename T>
bool LinkedList<T>::removeAt(int position)
{
    if(position < 1 || position > m_length)
        return false;
    if(position==1)
        return removeFront();
    if(position==m_length)
        return removeBack();
    Node<T>* curr = m_front->getNext();
    Node<T>* prev = m_front;
    int currPos=2;
    while(position>currPos)
    {
        curr=curr->getNext();
        prev=prev->getNext();
	currPos++;
    }
    prev->setNext(curr->getNext());
    delete curr;
    m_length--;
    return true;
}

template <typename T>
void LinkedList<T>::setEntry(int position, T value)
{
    if(position < 1 || position > m_length)
    { /*do nothing*/ }
    else
    {
        Node<T>* curr = m_front;
        int currPos = 1;
        while(currPos<position)
        {
            curr = curr->getNext();
            currPos++;
        }
        curr->setValue(value);
    }
}

template <typename T>
T LinkedList<T>::getEntry(int position) const
{
    if(position < 1 || position > m_length)
        throw std::invalid_argument("ERROR: Invalid position");
    else
    {
        Node<T>* curr = m_front;
        int currPos = 1;
        while(currPos<position)
        {
            curr = curr->getNext();
            currPos++;
        }
        return curr->getItem();
    }
}

template <typename T>
void LinkedList<T>::reverseList()
{
    //this calls a helper method, which is actually recursive
    Node<T>* start = m_front;
    if(start!= nullptr && start->getNext()!= nullptr)
        reverseList(start);
    start->setNext(nullptr);
}

template <typename T>
void LinkedList<T>::reverseList(Node<T>* front)
{
    if(front->getNext() != nullptr)
    {
        Node<T>* next = front->getNext();
        reverseList(next);
        next->setNext(front);
    }
    else //we're at the "end" of the list, so we need m_front to point here
        m_front = front;
    
}
