/**
*	@file City.cpp
*	@author Zachary Bruennig 
*	@date 9/19/16
*	@brief Holds all the information about a City object
*/

#include "City.h"
#include <iostream>

City::City()
{
    m_infectionLevel = 0;
    m_population = 0;
    m_name = "";
}

City::City(std::string name, int infectionLevel, int population)
{
    m_name = name;
    m_infectionLevel = infectionLevel;
    m_population = population;
}

void City::increaseInfectionLevel()
{
    m_infectionLevel++;
}

int City::getInfectionLevel() const
{ return m_infectionLevel; }

int City::getPopulation() const
{ return m_population; }

std::string City::getName() const
{ return m_name; }

void City::setPopulationLevel(int newPopulation)
{ m_population = newPopulation; }
