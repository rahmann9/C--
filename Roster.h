#pragma once
#include "Student.h"
#include <string>

class Roster {
public:
    Roster();                                    // Constructor.
    ~Roster();                                   // Destructor.
    void add(std::string studentID,
        std::string firstName,
        std::string lastName,
        std::string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);       // Adds a new student to the roster.
    void remove(std::string studentID);          // Removes a student from the roster by student ID.
    void printAll();                       // Prints all students in the roster.
    void printAverageDaysInCourse(std::string studentID);  // Prints average days in course.
    void printInvalidEmails();             // Prints all invalid email addresses.
    void printByDegreeProgram(DegreeProgram degreeProgram); // Print students by degree program.

private:
    int lastIndex;
    Student* classRosterArray[5];
};
