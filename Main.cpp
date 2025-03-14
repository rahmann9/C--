#include "Roster.h"
#include <iostream>

int main() {
    const std::string studentData[] = {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5, Nahian, Rahman, nrahm29@wgu.edu, 20, 10, 10, 10, SOFTWARE"
    };


    std::cout << "Course Title : Scripting and Programming - Applications - C867\nLanguage: C++\nStudent ID : 012096094\nName: Nahian Rahman\n";


    Roster classRoster;

    // Parse sets of data in "studentData" and populate classRoster
    for (const std::string entry : studentData) {
        size_t rhs = 0;
        std::string delimiter = ", ";

        size_t lhs = rhs;
        rhs = entry.find(delimiter);
        std::string studentID = entry.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = entry.find(delimiter, lhs);
        std::string firstName = entry.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = entry.find(delimiter, lhs);
        std::string lastName = entry.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = entry.find(delimiter, lhs);
        std::string emailAddress = entry.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = entry.find(delimiter, lhs);
        int age = std::stoi(entry.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = entry.find(delimiter, lhs);
        int numberOfDays = std::stoi(entry.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        DegreeProgram degreeProgram;
        std::string degreeString = entry.substr(lhs, entry.size() - lhs);
        if (degreeString == "SECURITY") {
            degreeProgram = DegreeProgram::SECURITY;
        }
        else if (degreeString == "NETWORK") {
            degreeProgram = DegreeProgram::NETWORK;
        }
        else if (degreeString == "SOFTWARE") {
            degreeProgram = DegreeProgram::SOFTWARE;
        }

        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }


    classRoster.printAll();
    classRoster.printInvalidEmails();

    // Calculate average days in course for each student
    for (int i = 0; i <= classRoster.getLastIndex(); ++i) {
        classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
    }

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    // Remove a student by studentID
    classRoster.remove("A3");

    classRoster.remove("A3");

    return 0;
}
