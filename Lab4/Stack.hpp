/**
*	@file Stack.cpp
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief Implementation of a linked-based stack
*/

#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
    m_length = 0;
    m_front = nullptr;
}

template <typename T>
Stack<T>::~Stack()
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
bool Stack<T>::isEmpty() const
{
    return (m_front==nullptr);
}

template <typename T>
void Stack<T>::push(const T& newEntry) throw (PreconditionViolatedException)
{
    //since this *HAS* to throw an exception somewhere
    bool spaceAvailable = true;
    if(!spaceAvailable)
            throw PreconditionViolatedException("No memory available in stack");
    
    Node<T>* oldFront = m_front;
    Node<T>* newFront = new Node<T>(newEntry);
    newFront->setNext(oldFront);
    m_front = newFront;
    m_length++;
}

template <typename T>
void Stack<T>::pop() throw (PreconditionViolatedException)
{
    if(m_front==nullptr)
        throw PreconditionViolatedException("Stack is empty");
    Node<T>* oldFront = m_front;
    Node<T>* newFront = m_front->getNext();
    m_front = newFront;
    delete oldFront;
    m_length--;
}

template <typename T>
T Stack<T>::peek() const throw (PreconditionViolatedException)
{
    if(m_front==nullptr)
        throw PreconditionViolatedException("Stack is empty");
    return m_front->getItem();
}

template <typename T>
int Stack<T>::getLength() const
{
    return m_length;
}
