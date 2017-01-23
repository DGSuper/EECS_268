/* -----------------------------------------------------------------------------
 *
 * File Name: Executive.cpp
 * Author: Zachary Bruennig | zkb@ku.edu
 * Assignment:   EECS-268 Lab 1
 * Description:  Handles the user interface, takes input from the user and manages
 * all calls to DriversLicenseRecord. Holds an array of VoterRegistrationRecord.
 * Date: 8/31/2016
 *
 ---------------------------------------------------------------------------- */
#include "Executive.h"
#include "VoterRegistrationRecord.h"
#include <fstream>
#include <string>

/*
 * Constructor. Takes in a file name, creates an array of VoterRegistrationRecord,
 * with size the first number of the file.
 * Precondition, fileName is the name of a file which is appropriately formatted,
 * with an amount of VoterRegistrationRecords equal to the first number in the file.
 */
Executive::Executive(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    
    if(!inFile.is_open())
        m_fileExists = false;
    else
    {
        m_fileExists = true;
        inFile >> m_numberOfVoters;
        
        voters = new VoterRegistrationRecord[m_numberOfVoters];
        
        //fills array with VoterRegistrationRecords containing info from the text file
        for(int i=0; i<m_numberOfVoters; i++)
        {
            std::string firstName;
            std::string lastName;
            int age;
            std::string affiliation;
            
            inFile >> firstName;
            inFile >> lastName;
            inFile >> age;
            inFile >> affiliation;
            
            voters[i].setFirstName(firstName);
            voters[i].setLastName(lastName);
            voters[i].setAge(age);
            voters[i].setAffiliation(affiliation);
        }
    }
    inFile.close();
}

//Destuctor. If voters was ever initialized, this will delete it.
Executive::~Executive()
{
        if(m_fileExists)
                delete[] voters;
}

/*
 * Helper method used by other methods in Executive. Given an array index i,
 * this will print and format a single voter's information to the console.
 * Prints in the following format:
 * $firstName $lastName; age $age; Registered as $affiliation
 * Precondition: i < m_numberOfVoters, and voters has been created properly
 */
void Executive::reportVoter(int i)
{
	std::string firstName = voters[i].getFirstName();
	std::string lastName = voters[i].getLastName();
	int age = voters[i].getAge();
	std::string affiliation = voters[i].getAffiliation();

	std::cout << firstName << " " << lastName << "; age " << age 
		<< "; Registered as " << affiliation << "\n";
}

/*
 * Takes in a (case sensitive) string, and compares it to all last names in voters.
 * If any match, it calls reportVoter for that index
 */
void Executive::queryLastName(std::string lastName)
{
	bool oneExists = false;
	std::cout << "Record: ";
	for(int i=0; i<m_numberOfVoters; i++)
	{
		if(lastName==voters[i].getLastName())//comment
		{
			oneExists = true;
			reportVoter(i);
		}
	}
	if(!oneExists)
		std::cout << "None on record\n";
}

/*
 * Takes in two ints, and compares it to all voters ages.
 * If any voter's age is between those two numbers, it calls reportVoter for that index.
 * Precondition: lower <= higher
 */
void Executive::queryAgeRange(int lower, int higher)
{
	bool oneExists = false;
	std::cout << "Record: ";
	for(int i=0; i<m_numberOfVoters; i++)
	{
		if(voters[i].getAge() >= lower && voters[i].getAge() <= higher)
		{
			oneExists = true;
			reportVoter(i);
		}
	}
	if(!oneExists)
		std::cout << "None on record\n";
}
/*
 * Takes a (case sensitive) string, and compares it to all affiliations in voters.
 * For every match, the return, count, is incremented by 1.
 */
 
int Executive::numberAffiliated(std::string affiliation)
{
	int count = 0;
	for(int i=0; i<m_numberOfVoters; i++)
	{
		if(affiliation==voters[i].getAffiliation())
			count++;
	}
	return count;
}

/*
 * Takes a (case sensitive) string, and compares it to all affiliations in voters.
 * If any match, it calls reportVoter for that index
 */
void Executive::queryAffiliation(std::string affiliation)
{
	bool oneExists = false;
	std::cout << "Record: ";
	for(int i=0; i<m_numberOfVoters; i++)
	{
		if(affiliation==voters[i].getAffiliation())
		{
			oneExists = true;
			reportVoter(i);
		}
	}
	if(!oneExists)
		std::cout << "None on record\n";
}


/*
 * Handles the user interface and user input. Depending on the user input
 * this will also ask for a string or ints for any query requests.
 * The user will always return to this method unless they choose the "Quit" option
 * If an improper filename was given in the command line, this method will simply
 * report that and immediately terminate.
 */
void Executive::run()
{	
	if(!m_fileExists)
		std::cout << "Error: File could not be read.\n";

	while(m_fileExists)
	{
		char option = ' ';
		std::cout << "###########################################\n";
		std::cout << "Select an option:\n";
		std::cout << "1. Query last name\n";
		std::cout << "2. Query age range\n";
		std::cout << "3. Query affiliations\n";
		std::cout << "4. Report number of people with affiliation\n";
		std::cout << "5. Quit\n";
		std::cout << "###########################################\n";

		//verifies option is a valid input before continuing
		while(option!='1' && option!='2' && option!='3' && option!='4' && option!='5')
			std::cin >> option;
		if(option=='1')
		{
			//query last name - takes input last name
			std::string lastName;
			std::cout << "Enter last name: ";
			std::cin >> lastName;

			queryLastName(lastName);
		}
		else if(option=='2')
		{
			//query age range - takes two inputs, for age range
			int lower;
			int higher;
			std::cout << "Enter lower age: ";
			std::cin >> lower;
			std::cout << "Enter higher age: ";
			std::cin >> higher;

			//if they're in the wrong order, switch them
			if(lower > higher)
			{
				int temp = lower;
				lower = higher;
				higher = temp;
			}
			queryAgeRange(lower, higher);
		}
		else if(option=='3')
		{
			//query affiliations - takes input affiliation
			std::string affiliation;
			std::cout << "Enter affiliation: ";
			std::cin >> affiliation;

			queryAffiliation(affiliation);
		}
		else if(option=='4')
		{
			//report number with affiliation - takes input affiliation
			std::string affiliation;
			std::cout << "Enter affiliation: ";
			std::cin >> affiliation;

			std::cout << "There are " << numberAffiliated(affiliation) << " voters ";
			std::cout << "with " << affiliation << " affiliation.\n";
		}
		else
		{
			std::cout << "Thanks for checking voter registrations!\nBye.\n";
			break; //this will only happen is option = '5'
		}
	}
}
