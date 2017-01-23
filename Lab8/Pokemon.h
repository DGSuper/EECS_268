/**
*	@file Pokemon.h
*	@author Zachary Bruennig 
*	@date 11/12/16
*	@brief A header file for the Pokemon class
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
private:
    std::string m_americanName;
    std::string m_japaneseName;
    int m_number;
    
public:
    //initializes private variables to these parameters
    Pokemon(std::string americanName, std::string japaneseName, int number);
    
    //gives the output 'm_americanName,m_number,m_japaneseName'
    std::string toString();
    
    /** @returns m_americanName */
    std::string getKeyType();
    
    /** @returns m_americanName */
    std::string getAmericanName();
    
    /** @returns m_japaneseName */
    std::string getJapaneseName();
    
    /** @returns m_number */
    int getNumber();
    
    /** Comparison of Pokemon is determined by lexicographic ordering of americanName*/
    bool operator <(const Pokemon& other);
    bool operator >(const Pokemon& other);
};
#endif
