#pragma once
#ifndef student_h
#define student_h
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

//D1.  Create "class Student"
class Student {

public: 
    Student();
    Student(string StudentId, string FirstName, string LastName, string Email, int Age, int DaysInCourse[], DegreeProgram degreeProgram);

    
    string getStudentId() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int* getDaysInCourse();
    DegreeProgram getdegreeProgram() const;

    void setStudentId(string StudentIdToSet);
    void setFirstName(string FirstNameToSet);
    void setLastName(string  LastNameToSet);
    void setEmail(string EmailToSet);
    void setAge(int AgeToSet);
    void setDaysInCourse(int daysToSet[]);        
    void setdegreeProgram(DegreeProgram degreeProgramToSet);

    void print();

    const static int DaysInCourseArraySize = 3;

private:
    string StudentId;
    string FirstName;
    string LastName;
    string Email;
    int Age;
    int DaysInCourse[DaysInCourseArraySize];
    DegreeProgram degreeProgram;
    int i = 0;
};
#endif
