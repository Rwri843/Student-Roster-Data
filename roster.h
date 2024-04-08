#pragma once
#include <string>
#include <array>
#include "student.h"

//E1. create Roster class
class Roster {
public:
    Roster(int classSize) {
    }
    void add(string StudentId, string FirstName, string LastName, string Email, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    string GetStudentId(int index);
    void parseAndAdd(string studentData);
    void remove(std::string StudentId);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
   
    // array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    const static int numStudents = 5;
    Student* ClassRosterArray[numStudents];
    int lastIndex = -1;
    
    // Destructor
        ~Roster() {
            for (int i = 0; i <= lastIndex; ++i) {
                delete ClassRosterArray[i];
                ClassRosterArray[i] = nullptr;
            }
        }


private:
    
};
