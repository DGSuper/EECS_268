/**
*	@file City.h
*	@author Zachary Bruennig 
*	@date 9/19/16
*	@brief A header file for the City class
*/

#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>

class City
{
private:
    int m_infectionLevel;
    int m_population;
    std::string m_name;
public:
    
    /** @pre None.
    *   @post Generates a default City object, with population and infection 0, and name is an empty string.
    */
    City(); 
    
    /** @pre 0<=infectionLevel<=3
    *   @post Generates a City object with values for name, infection level, and population
    */
    City(std::string name, int infectionLevel, int population);
    
    /** @pre None.
    *   @post Infection level is incremented by 1.
    */
    void increaseInfectionLevel();
    
    /** @pre None.
    *   @post None.
    *   @return The infection level of the city
    */
    int getInfectionLevel() const;
    
    /** @pre None.
    *   @post None.
    *   @return The population of the city
    */
    int getPopulation() const;
    
    /** @pre None.
    *   @post None.
    *   @return The name of the city
    */
    std::string getName() const;
    
    /** @pre newPopulation is not an empty string
    *   @post m_population is set to newPopulation
    */
    void setPopulationLevel(int newPopulation);
};

#endif
