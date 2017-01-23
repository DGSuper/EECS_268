/**
*	@file Queue.cpp
*	@author Zachary Bruennig
*	@date 10/2/16
*	@brief Implementation of a linked based queue
*/
#include "Queue.h"
#include "Node.cpp"

template <typename T>
Queue<T>::Queue()
{
    m_length = 0;
    m_front = nullptr;
    m_back = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    m_back = nullptr; //we can do this because we'll be deleting through the front
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
bool Queue<T>::isEmpty() const
{
    return (m_front==nullptr);
}

template <typename T> // if there's a bug in this program it's probably in here or dequeue
void Queue<T>::enqueue(const T& newEntry) throw (PreconditionViolatedException)
{
    //just to be consistent with QueueInterface's definition
    bool spaceAvailable = true;
    if(!spaceAvailable)
        throw PreconditionViolatedException("No memory available in queue");
    
    Node<T>* newNode = new Node<T>(newEntry);
    if(m_length==0)
    {
        m_front = newNode;
        m_back = newNode;
        m_length++;
    }
    else
    {
        m_back->setNext(newNode);
        m_back = m_back->getNext();
        m_length++;
    }
}

template <typename T>
void Queue<T>::dequeue() throw (PreconditionViolatedException)
{
    if(m_front==nullptr)
        throw PreconditionViolatedException("Queue is empty");
    Node<T>* oldFront = m_front;
    Node<T>* newFront = m_front->getNext();
    m_front = newFront;
    delete oldFront;
    m_length--;
    
    if(m_length==0) //if there was only one thing in the queue
        m_back = nullptr;
}

template <typename T>
T Queue<T>::peekFront() const throw (PreconditionViolatedException)
{
    if(m_front==nullptr)
        throw PreconditionViolatedException("Queue is empty");
    return m_front->getItem();
}

template <typename T>
int Queue<T>::getLength() const
{
    return m_length;
}
