/**
*	@file MedicalExecutive.h
*	@author Zachary Bruennig 
*	@date 9/19/16
*	@brief Header file for the MedicalExecutive class. 
*/

#ifndef MEDICAL_EXECUTIVE_H
#define MEDICAL_EXECUTIVE_H

#include "LinkedList.h"
#include "LinkedList.cpp"
#include "City.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class MedicalExecutive
{
private:
    LinkedList<City>* m_cityList;
    LinkedList<City>* m_quarantineList;
    
    //if this remains false after the constructor, then the program will simply terminate immediately
    bool m_fileExists = false;
    bool m_isQuarantineListEmpty = true;
    
    /** @pre newCity is an initialized city with infectionLevel <= 3
    *   @post newCity will be added to m_cityList. Its position in the list will be based on its population.
    */
    void addToCityList(City newCity);
    
    /** @pre newCity is an initialized city with infectionLevel == 4
    *   @post newCity will be added to m_quarantineList. Its position in the list will be based on its population.
    */
    void addToQuarantineList(City newCity);
    
    /** @pre i is a valid index in m_cityList
    *   @post The city at index i will have its infection level increased, and may be removed and modified based
    *         on its new infection level
    *   @return true if an infection level was successfully increased, false otherwise
    */
    bool increaseAnInfectionLevel(int i);
    
    /** @pre None
    *   @post If a city in cityList has a name identical to cityName, its infection level will be increased
    *   @return true if there exists a city with cityName
    */
    bool increaseAnInfectionLevel(std::string cityName);
    
    /** @pre None
    *   @post All cities will have their infection level increased and other modifications based on their
    *         infection levels.
    */
    void increaseAllInfectionLevels();
    
    /** @pre None
    *   @post Prints to console all cities greater than or equal to an infection level infectionLevel 
    */
    void printCities(int infectionLevel);
    
    /** @pre i is a valid index in m_cityList
    *   @post Prints to console information about the city in index i of m_cityList
    */
    void printACity(int i);
    
    /** @pre m_quarantineList is not empty
    *   @post A new file is created with name fileName, and contains every quarantined city in m_quarantineList
    */
    void createQuarantineLog(std::string fileName);
public:
    
    /** @pre fileName is a valid file name, and it is formatted properly
    *   @post m_cityList will be initialized based on the contents of fileName,
    *         m_fileExists will be set to true if the file was successfully opened
    */
    MedicalExecutive(std::string fileName);
    
    /** @pre None
    *   @post Deletes m_cityList and m_quarantineList upon termination of the program
    */
    ~MedicalExecutive();
    
    /** @pre None
    *   @post This method will loop until the user chooses to exit. It will take user input and run other methods
    *         based on the user's choice.
    */
    void run();
};

#endif
