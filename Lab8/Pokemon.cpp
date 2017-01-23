/**
*	@file Pokemon.cpp
*	@author Zachary Bruennig 
*	@date 11/12/16
*	@brief Defines a Pokemon object, which contains an american name, a japanese name, and a number
*/

#include "Pokemon.h"

Pokemon::Pokemon(std::string americanName, std::string japaneseName, int number)
{
    m_americanName = americanName;
    m_japaneseName = japaneseName;
    m_number = number;
}

std::string Pokemon::toString()
{
    std::string output = m_americanName+","+std::to_string(m_number)+","+m_japaneseName;
    return output;
}

std::string Pokemon::getKeyType()
{
    return m_americanName;
}

std::string Pokemon::getAmericanName()
{
    return m_americanName;
}

std::string Pokemon::getJapaneseName()
{
    return m_japaneseName;
}

int Pokemon::getNumber()
{
    return m_number;
}

bool Pokemon::operator >(const Pokemon& other)
{
    return m_americanName > other.m_americanName;
}

bool Pokemon::operator <(const Pokemon& other)
{
    return m_americanName < other.m_americanName;
}
