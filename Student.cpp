#pragma once
#include "Student.h"

// Constructor with all parameters provided.
Student::Student : std::string studentID(" "), std::string firstName(" "), std::string lastName(" "),
std::string emailAddress(" "), int age(0), numberOfDays(int[daysToCompleteCourses]) {
    for (int i = 0; i < daysToCompleteCourses; i++)
        this->numberOfDays[i] = 0;
}
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress
    , int age, int numberOfDays[], DegreeProgram degreeProgram)



    // Accessor implementations
    std::string Student::getStudentID() { return studentID; }
std::string Student::getFirstName() { return firstName; }
std::string Student::getLastName() { return lastName; }
std::string Student::getEmailAddress() { return emailAddress; }
int Student::getAge() { return age; }
int* Student::getDaysToCompleteCourses() { return daysToCompleteCourses; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

// Mutator implementations
void Student::setStudentID(std::string StudentID) { this->studentID = StudentID; }
void Student::setFirstName(std::string FirstName) { this->firstName = FirstName; }
void Student::setLastName(std::string LastName) { this->lastName = LastName; }
void Student::setEmailAddress(std::string EmailAddress) { this->emailAddress = EmailAddress; }
void Student::setAge(int Age) { this->age = Age; }
void Student::setDaysToCompleteCourses(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    daysToCompleteCourses[0] = daysInCourse1;
    daysToCompleteCourses[1] = daysInCourse2;
    daysToCompleteCourses[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram newDegreeProgram) { degreeProgram = newDegreeProgram; }

// print() function to print specific student data
void Student::print() {
    void Student::print() const {
        std::cout << "Student ID : " << getStudentID() << "\t";
        std::cout << "First Name: " << getFirstName() << "\t";
        std::cout << "Last Name: " << getLastName() << "\t";
        std::cout << "Email Address: " << getEmailAddress() << "\t";
        std::cout << "Age: " << getAge() << "\t";
        std::cout << "daysInCourse: {" << daysToCompleteCourses[0] << ", "
            << daysToCompleteCourses[1] << ", " << daysToCompleteCourses[2] << "}" << "\t";
        std::cout << "Degree Program: ";
        DegreeProgram degree = getDegreeProgram();

        if (degree == DegreeProgram::SECURITY) {
            std::cout << "SECURITY";
        }
        else if (degree == DegreeProgram::NETWORK) {
            std::cout << "NETWORK";
        }
        else if (degree == DegreeProgram::SOFTWARE) {
            std::cout << "SOFTWARE";
        }
        std::cout << std::endl;
    }