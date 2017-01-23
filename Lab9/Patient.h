/**
*	@file Patient.h
*	@author Zachary Bruennig 
*	@date 11/14/16
*	@brief A header file for the Patient class
*/

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <limits.h>

class Patient
{
private:
    std::string m_name;
    int m_priority;
public:
    //Sets variables to parameters.
    Patient(std::string name, int priority);
    
    //Default constructor. Initializes variables to default values.
    Patient() {m_name = ""; m_priority = INT_MIN;}
    
    //Setter method for m_name
    void setName(std::string name);
    
    //Setter method for m_priority
    void setPriority(int priority);
    
    //Getter method for m_name
    std::string getName() const;
    
    //Getter method for m_priority
    int getPriority() const;
    
    //Allows comparison of Patient objects through their priority
    bool operator <(const Patient& other);
    bool operator >(const Patient& other);
    bool operator ==(const Patient& other);
};
#endif


 
 double divide(double number, double divisor)
 {
    if(divisor==0)
    {
        throw std::exception("Cannot divide by zero!\n");
    }
    if(divisor < 0)
    {
        throw logic_error("I don't like negative numbers\n");
    }
    return number/divisor;
 }
 
 int main()
 {
    double x = 9;
    double y = 0;
    
    try
    {
        double z = divide(x,y);
        std::cout << z;
        std::cout << "That was fun!";
    }
    catch(std::logic_error e)
    {
        std::cout << "Don't use negative numbers";
    }
    catch(std::exception e)
    {
        std::cout << e.what();
    }
    
    
    return 0;
 }
 
 Circle** arr = new Circle[6];
 arr[i] = Circle(7);
 delete[] arr;
 
 
 
 
 
 
 
 
 
 
 
 */
