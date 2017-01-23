/* -----------------------------------------------------------------------------
 *
 * File Name: Executive.cpp
 * Author: Zachary Bruennig | zkb@ku.edu
 * Assignment:   EECS-268 Lab 1
 * Description:  A simple data structure which holds information for a single registered voter.
 * Contains four instance variables: m_firstName, m_lastName, m_age, and m_affiliation
 * Also contains accessor and mutator methods for all four variables.
 * Date: 8/31/2016
 *
 ---------------------------------------------------------------------------- */

#include "VoterRegistrationRecord.h"

//default constructor, sets all variable to default values
VoterRegistrationRecord::VoterRegistrationRecord()
{
    m_firstName = "";
    m_lastName = "";
    m_age = -1;
    m_affiliation = "";
}

//constructor with initial values for all member variables
VoterRegistrationRecord::VoterRegistrationRecord(std::string first, std::string last, int age, std::string affiliation)
{
    m_firstName = first;
    m_lastName = last;
    m_age = age;
    m_affiliation = affiliation;
}

//mutator methods for all member variables

//mutator for m_firstName
void VoterRegistrationRecord::setFirstName(std::string first)
{
    m_firstName = first;
}

//mutator for m_lastName
void VoterRegistrationRecord::setLastName(std::string last)
{
    m_lastName = last;
}

//mutator for m_age
void VoterRegistrationRecord::setAge(int age)
{
    m_age = age;
}

//mutator for m_affiliation
void VoterRegistrationRecord::setAffiliation(std::string affiliation)
{
    m_affiliation = affiliation;
}

//accessor methods for all member variables

//accessor for m_firstName
std::string VoterRegistrationRecord::getFirstName() const
{
    return m_firstName;
}
//accessor for m_lastName
std::string VoterRegistrationRecord::getLastName() const
{
    return m_lastName;
}
//accessor for m_age
int VoterRegistrationRecord::getAge() const
{
    return m_age;
}
//accessor for m_affiliation
std::string VoterRegistrationRecord::getAffiliation() const
{
    return m_affiliation;
}
