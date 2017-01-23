/* -----------------------------------------------------------------------------
 *
 * File Name: VoterRegistrationRecord.h
 * Author: Zachary Bruennig | zkb@ku.edu
 * Assignment:   EECS-268 Lab 1
 * Description:  Header file for VoterRegistrationRecord.cpp
 * Holds all class variables and methods.
 * Date: 8/31/2016
 *
 ---------------------------------------------------------------------------- */

#ifndef VOTERREGISTRATIONRECORD_H
#define VOTERREGISTRATIONRECORD_H

#include <iostream>
#include <string>

class VoterRegistrationRecord
{
private:
    std::string m_firstName;
    std::string m_lastName;
    int m_age;
    std::string m_affiliation;
public:
    VoterRegistrationRecord(std::string first, std::string last, int age, std::string affiliation);
    VoterRegistrationRecord();
    
    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
    std::string getAffiliation() const;
    
    void setFirstName(std::string first);
    void setLastName(std::string last);
    void setAge(int age);
    void setAffiliation(std::string affiliation);
};
#endif
