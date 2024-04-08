#include "roster.h"
#include <sstream>
#include <string>
#include <iostream>


// E2. Parse the student data, then add the data to the "classRosterarray", and assign attributes to each student. "rhs" & "lhs" are used to find the data in the string separated by data. The "add" function of the Roster class is then called with all the extracted information.
void Roster::parseAndAdd(string studentData) {
    string::size_type rhs = studentData.find(",");
    string StudentId = studentData.substr(0, rhs);
    
    string::size_type lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string FirstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string LastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string Email = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int Age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int DaysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int DaysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int DaysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    DegreeProgram degreeProgram = DegreeProgram::UNKNOWN;
    string degreeString = studentData.substr(lhs, rhs - lhs);
    
    if (degreeString == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (degreeString == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (degreeString == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    add(StudentId, FirstName, LastName, Email, Age, DaysInCourse1, DaysInCourse2, DaysInCourse3, degreeProgram);
}
// E3a.Set the variable instance. New student object with the provided information and adds it to the ClassRosterArray at the next available index. The lastIndex is used to keep track of the last occupied index in the array.
void Roster::add(string StudentId, string FirstName, string LastName, string Email, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, DegreeProgram degreeProgram) {
    int DaysInCourse[Student::DaysInCourseArraySize] = { DaysInCourse1, DaysInCourse2, DaysInCourse3 };
    ClassRosterArray[++lastIndex] = new Student(StudentId, FirstName, LastName, Email, Age, DaysInCourse, degreeProgram);
}
//E3b. Removes students from the roster by student ID. Student ID does not exist, function prints an error message indicating that the student was not found.
void Roster::remove(string StudentId) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (ClassRosterArray[i]->getStudentId() == StudentId) {
            delete ClassRosterArray[i];
            for (int j = i; j < lastIndex; ++j) {
                ClassRosterArray[j] = ClassRosterArray[j + 1];
            }
            ClassRosterArray[lastIndex] = nullptr;
            found = true;
            lastIndex--;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << StudentId << " not found in the roster." << endl;
    }
}
// E3c. Loops through data in classrosterarray.
void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; ++i) {
        ClassRosterArray[i]->print();
    }
}
// E3d.   searches for a student with a specific ID in the roster, calculates and prints the average days spent in courses for that student, and provides an error message if the student is not found. The "for" loop searches for student by Id. The nested "for" loop, calculates the total number of days the student spent in courses by summing up the elements of the array. "double" divides the total days to get average.
void Roster::printAverageDaysInCourse(string studentID) const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (ClassRosterArray[i]->getStudentId() == studentID) {
            int* daysInCourses = ClassRosterArray[i]->getDaysInCourse();
            int totalDays = 0;
            for (int j = 0; j < Student::DaysInCourseArraySize; ++j) {
                totalDays += daysInCourses[j];
            }
            double averageDays = static_cast<double>(totalDays) / Student::DaysInCourseArraySize;
            cout << "Average days in courses for student " << studentID << ": " << averageDays << endl;
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found." << endl;
}
// E3e. "for" loop searches for the emails and "if" checks to see if they meet criteria.
void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; ++i) {
        string email = ClassRosterArray[i]->getEmail();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << "Invalid email address: " << email << endl;
        }
    }
}
//E3f. Prints output based on degree program. 
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (ClassRosterArray[i]->getdegreeProgram() == degreeProgram) {
            ClassRosterArray[i]->print();
        }
    }
}




