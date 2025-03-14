#include "Roster.h"
#include <iostream>
#include <string>

// Constructor initializes lastIndex to -1 indicating an empty array
Roster::Roster() : lastIndex(-1) {}

// Destructor releases all allocated memory
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i]; // Deallocate memory for Student objects
            classRosterArray[i] = nullptr;
        }
    }
}

// Adds a new student to the roster
void Roster::add(std::string studentID, std::string firstName, std::string lastName,
    std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
    int daysInCourse3, DegreeProgram degreeProgram) {
    if (lastIndex < MAX_STUDENTS - 1) {
        lastIndex++;
        classRosterArray[lastIndex] = new Student(studentID, firstName, lastName,
            emailAddress, age, daysInCourse1,
            daysInCourse2, daysInCourse3, degreeProgram);
    }
    else {
        std::cout << "Error: Roster has reached maximum capacity. Cannot add more students." << std::endl;
    }
}

// Removes a student from the roster by student ID
void Roster::remove(std::string studentID) {
    bool studentFound = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i]; // Delete the Student object
            classRosterArray[i] = classRosterArray[lastIndex]; // Move last student to current position
            lastIndex–; // Reduce the count of students
            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
    }
}

// Prints all students in the roster
void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

// Prints average days in the course for a student by ID
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysToCompleteCourses();
            std::cout << "Average days in course for student ID " << studentID << ": "
                << (days[0] + days[1] + days[2]) / 3 << std::endl;
            return;
        }
    }
    std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
}

// Prints all invalid email addresses
void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            std::string email = classRosterArray[i]->getEmailAddress();
            if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
                std::cout << "Invalid email: " << email << std::endl;
            }
        }
    }
}

// Prints out student information for a degree program specified by an enumerated type
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}