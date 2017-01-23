/**
*	@file MedifcalExecutive.cpp
*	@author Zachary Bruennig 
*	@date 9/19/16
*	@brief Handles all user and file I/O, as well as manipulates the LinkedList of cities.
*              run() is the main method, and all other methods will be called as a result of user input in
*              run().
*/

#include "MedicalExecutive.h"
#include "City.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void MedicalExecutive::addToCityList(City newCity)
{
    int listSize = m_cityList->getLength();
    if(listSize==0)
        m_cityList->addFront(newCity);
    else
    {
        bool inserted = false;
        for(int i=1; i<=listSize; i++)
        {
            if(inserted)
                break;
            
            if (newCity.getPopulation() > m_cityList->getEntry(i).getPopulation()) //greater in population
            {
                m_cityList->insert(i, newCity);
                inserted = true;
            }
            else if(newCity.getPopulation() == m_cityList->getEntry(i).getPopulation()) // they must be equal in population
            {
                if(newCity.getInfectionLevel() > m_cityList->getEntry(i).getInfectionLevel()) // greater in infection level
                {
                    m_cityList->insert(i, newCity);
                    inserted = true;
                }
                else if(newCity.getInfectionLevel() < m_cityList->getEntry(i).getInfectionLevel()) // lesser in infection level
                {
                    m_cityList->insert(i+1, newCity);
                    inserted = true;
                }
                else // they must be equal in both population and infection level
                {
                    if(newCity.getName().compare(m_cityList->getEntry(i).getName()) > 0)
                    {
                        m_cityList->insert(i, newCity);
                        inserted = true;
                    }
                    else
                    {
                        m_cityList->insert(i+1, newCity);
                        inserted = true;
                    }
                }
            }
        }
        if(!inserted)
        {
            m_cityList->addBack(newCity);
        }
    }
}

void MedicalExecutive::addToQuarantineList(City newCity)
{
    int listSize = m_quarantineList->getLength();
    if(listSize==0)
        m_quarantineList->addFront(newCity);
    else
    {
        bool inserted = false;
        for(int i=1; i<=listSize; i++)
        {
            if(inserted)
                break;
            
            if (newCity.getPopulation() > m_quarantineList->getEntry(i).getPopulation()) //greater in population
            {
                m_quarantineList->insert(i, newCity);
                inserted = true;
            }
            else if(newCity.getPopulation() == m_quarantineList->getEntry(i).getPopulation()) // they must be equal in population
            {
                if(newCity.getInfectionLevel() > m_quarantineList->getEntry(i).getInfectionLevel()) // greater in infection level
                {
                    m_quarantineList->insert(i, newCity);
                    inserted = true;
                }
                else if(newCity.getInfectionLevel() < m_quarantineList->getEntry(i).getInfectionLevel()) // lesser in infection level
                {
                    m_quarantineList->insert(i+1, newCity);
                    inserted = true;
                }
                else // they must be equal in both population and infection level
                {
                    if(newCity.getName().compare(m_quarantineList->getEntry(i).getName()) > 0)
                    {
                        m_quarantineList->insert(i, newCity);
                        inserted = true;
                    }
                    else
                    {
                        m_quarantineList->insert(i+1, newCity);
                        inserted = true;
                    }
                }
            }
            
        }
        if(!inserted)
        {
            m_quarantineList->addBack(newCity);
        }
    }
}

MedicalExecutive::MedicalExecutive(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    if(!inFile.is_open())
        m_fileExists = false;
    else
    {
        m_fileExists = true;
        m_cityList = new LinkedList<City>;
        m_quarantineList = new LinkedList<City>;
        
        //TODO read in file and create the LinkedList of cities
        
        std::string line;
        while(std::getline(inFile, line))
        {
            std::string cityName;
            int population;
            int infectionLevel;
            
            cityName = line.substr(0, line.find(","));
            line = line.substr(line.find(",")+2,line.length());
            
            std::string temp = line.substr(0,line.find(","));
            population = std::stoi(temp);
            line = line.substr(line.find(",")+2,line.length());
            
            infectionLevel = std::stoi(line);
            
            City curr(cityName, infectionLevel, population);
            addToCityList(curr);
        }
    }
    
    inFile.close();
}

MedicalExecutive::~MedicalExecutive()
{
    if(m_fileExists)
    {
        delete m_cityList;
        delete m_quarantineList;
    }
}

bool MedicalExecutive::increaseAnInfectionLevel(int i)
{
    if(m_cityList->getLength() < i)
        return false;
    City current = m_cityList->getEntry(i);
    current.increaseInfectionLevel();
    switch(current.getInfectionLevel())
    {
        case 1: 
        {
            m_cityList->removeAt(i);
            current.setPopulationLevel(current.getPopulation()*0.9);
            addToCityList(current);
            break;
        }
        case 2:
        {
            m_cityList->removeAt(i);
            current.setPopulationLevel(current.getPopulation()*0.8);
            addToCityList(current);
            break;
        }
        case 3:
        {
            m_cityList->removeAt(i);
            std::string newName = "New " + current.getName();
            City newCity(newName,0,current.getPopulation()*0.25);
            current.setPopulationLevel(current.getPopulation()*0.75);
            addToCityList(current);
            addToCityList(newCity);
            break;
        }
        case 4:
        {
            m_cityList->removeAt(i);
            std::cout << "City " << current.getName() << " has been placed in quarantine\n";
            addToQuarantineList(current);
            m_isQuarantineListEmpty = false;
            break;
        }
        default:
            break;
    }
    return true;
}

bool MedicalExecutive::increaseAnInfectionLevel(std::string cityName)
{
    for(int i=1; i<=m_cityList->getLength(); i++)
    {
        if(m_cityList->getEntry(i).getName()==cityName)
            return increaseAnInfectionLevel(i);
    }
    return false;
}

void MedicalExecutive::increaseAllInfectionLevels()
{
    LinkedList<int>* specialIndex = new LinkedList<int>;
    for(int i=m_cityList->getLength(); i>=1; i--)
    {
        if(m_cityList->getEntry(i).getInfectionLevel()==3) //meaning they will get removed from the list
        {
            try
            {
                increaseAnInfectionLevel(i);
            }
            catch(std::invalid_argument e)
            {
                //This should never happen, but just in case
                std::cout << e.what() << '\n';
            }
        }    
    }
    for(int i=1; i<=m_cityList->getLength(); i++)
    {
        //meaning a new city will be created which messes everything up
        if(m_cityList->getEntry(i).getInfectionLevel()==2)
            specialIndex->addFront(i); //will be in descending order
            
        else //this means its infection level is 0 or 1
        {
            try
            {
                increaseAnInfectionLevel(i);
            }
            catch(std::invalid_argument e)
            {
                std::cout << e.what() << '\n';
            }
        }
    }
    for(int i=1; i<=specialIndex->getLength(); i++)
    {
        //this will go through the indexes in decreasing population order, since that's how they were added
        //that means the off by one errors will not become a problem with the future loops of this function, hopefully
        try
        {
            increaseAnInfectionLevel(specialIndex->getEntry(i));
        }
        catch(std::invalid_argument e)
        {
            std::cout << e.what() << '\n';
        }
    }
    delete specialIndex;
}

void MedicalExecutive::printACity(int i)
{
    City current = m_cityList->getEntry(i);
    std::cout << current.getName() << ": Population " << current.getPopulation()
	      << ", Infection level " << current.getInfectionLevel() << "\n";
}

void MedicalExecutive::printCities(int infectionLevel)
{
    for(int i=1; i<=m_cityList->getLength(); i++)
    {
        if(m_cityList->getEntry(i).getInfectionLevel() >= infectionLevel)
            printACity(i);
    }
}

void MedicalExecutive::createQuarantineLog(std::string fileName)
{
    std::ofstream outFile;
    outFile.open(fileName);
    for(int i=1; i<=m_quarantineList->getLength(); i++)
    {
        City curr = m_quarantineList->getEntry(i);
        int population = curr.getPopulation();
        int infectionLevel = curr.getInfectionLevel();
        std::string name = curr.getName();
        outFile << name << ", " << population << ", " << infectionLevel << "\n";
    }
    outFile.close();
	
}

void MedicalExecutive::run()
{
    if(!m_fileExists)
        std::cout << "Error: File could not be read.\n";
    
    while(m_fileExists)
    {
        char option = ' ';
        std::cout << "\nMake a selection:\n";
        std::cout << "1) Increase infection level of all cities\n";
        std::cout << "2) Increase infection level of a specific city\n";
        std::cout << "3) Print status of a specific city\n";
        std::cout << "4) Create quarantine log\n";
        std::cout << "5) Print all cities above an infection level\n";
        std::cout << "6) Exit\n";
        std::cout << "Choice: ";
        
        //verifies option is a valid input before continuing
        while(option!='1' && option!='2' && option!='3' && option!='4' && option!='5' && option!='6')
            std::cin >> option;
        
        if(option=='1')
        {
            increaseAllInfectionLevels();
            std::cout << "Infection levels increased for all cities.\n";
        }
        else if(option=='2')
        {
            std::string cityName;
            std::cout << "Which city would you like to infect?: ";
            std::getline(std::cin, cityName);
            std::getline(std::cin, cityName);
            if(!increaseAnInfectionLevel(cityName))
                std::cout << "Sorry, '" << cityName << "' is not a city in the list.\n";
            else
                std::cout << "Infection level for '" << cityName << "' increased by 1\n";
        }
        else if(option=='3')
        {
            bool exists = false;
            std::string cityName;
            std::cout << "Input city name: ";
            std::getline(std::cin, cityName);
            std::getline(std::cin, cityName);
            for(int i=1; i<=m_cityList->getLength(); i++)
            {
                if(cityName==m_cityList->getEntry(i).getName())
                {   
                    printACity(i);
                    exists = true;
                }
            }
            if(!exists)
                std::cout << "Sorry, '" << cityName << "' is not a city in the list.\n";
                
        }
        else if(option=='4')
        {
            if(m_quarantineList->getLength() > 0)
            {    
                std::string fileName;
                std::cout << "Input a file name: ";
                std::cin >> fileName;
                createQuarantineLog(fileName);
            }
            else
            {
                std::cout << "No cities are quarantined. Cannot make a quarantine log.\n";
            }
        }
        else if(option=='5')
        {
            int level;
            std::cout << "Input infection level: ";
            std::cin >> level;
            //we're assuming we get new input
            printCities(level);
        }
        else //will only happen if option == '6'
        {
            break;
        }
    }
}
