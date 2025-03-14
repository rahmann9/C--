#pragma once
#include <iostream>
#include <iomanip>
#include "Degree.h"

class Student {
public:
    int daysToCompleteCourses[3]; // Array holding number of days to complete each course
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int numberOfDays[daysToCompleteCourses];
    DegreeProgram degreeProgram;
public:
    Student();
    // Constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int numberOfDays, DegreeProgram degreeProgram);
    // Destructor
    ~Student();
    // Accessor functions for each instance variable
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getNumberOfDays[];
    DegreeProgram getDegreeProgram();

    // Mutator functions for each instance variable
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setNumberOfDays(int numberOfDays[]);
    void setDegreeProgram(DegreeProgram dp);

    // print() to print specific student data
    void print();
};