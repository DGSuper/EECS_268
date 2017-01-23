/**
*	@file Patient.cpp
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief Defines a Patient object, which contains an name and a priority
*/

#include "Patient.h"


Patient::Patient(std::string name, int priority)
{
    m_name = name;
    m_priority = priority;
}

void Patient::setName(std::string name)
{
    m_name = name;
}

void Patient::setPriority(int priority)
{
    m_priority = priority;
}

std::string Patient::getName() const
{
    return m_name;
}

int Patient::getPriority() const
{
    return m_priority;
}

bool Patient::operator <(const Patient& other)
{
    return m_priority < other.m_priority;
}

bool Patient::operator >(const Patient& other)
{
    return m_priority > other.m_priority;
}

bool Patient::operator ==(const Patient& other)
{
    return m_priority == other.m_priority;
}
