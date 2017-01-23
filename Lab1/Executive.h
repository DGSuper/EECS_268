/* -----------------------------------------------------------------------------
 *
 * File Name: Executive.h
 * Author: Zachary Bruennig | zkb@ku.edu
 * Assignment:   EECS-268 Lab 1
 * Description:  Header file for the Executive class.
 * Includes all methods and class variables for it.
 * Date: 8/31/2016
 *
 ---------------------------------------------------------------------------- */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "VoterRegistrationRecord.h"
#include <string>
#include <iostream>
#include <fstream>

class Executive
{
private:
    VoterRegistrationRecord* voters;
    bool m_fileExists = false;
    int m_numberOfVoters;
    void queryLastName(std::string lastName);
    void queryAgeRange(int lower, int higher);
    void queryAffiliation(std::string affiliation);
    int numberAffiliated(std::string affiliation);
    void reportVoter(int i);
public:	
    Executive(std::string fileName);
    ~Executive();
    void run();
};
#endif
