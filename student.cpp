#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

// D2d.  Constructor used to create default Student class. Initializes data with starting values to help create objects.
Student::Student() {
    this->StudentId = "";
    this->FirstName = "";
    this->LastName = "";
    this->Email = "";
    this->Age = 0;
    for (int i = 0; i < DaysInCourseArraySize; ++i) {
        this->DaysInCourse[i] = 0;
    }
    this->degreeProgram = SOFTWARE;
}
// Constructor with Student class using arugemnts to ensure each attribute set is properly set.
Student::Student(string StudentId, string FirstName, string LastName, string Email, int Age, int DaysInCourse[], DegreeProgram degreeProgram) {
    this->StudentId = StudentId;
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->Email = Email;
    this->Age = Age;
    for (int i = 0; i < DaysInCourseArraySize; ++i) {
        this->DaysInCourse[i] = DaysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}


// D2a. Member functions to access(get) using encapsulation principle to access data.
string Student::getStudentId() const {
    return StudentId;
}

string Student::getFirstName() const {
    return FirstName;
}

string Student::getLastName() const {
    return LastName;
}

string Student::getEmail() const {
    return Email;
}

int Student::getAge() const {
    return Age;
}

int* Student::getDaysInCourse() {
    return DaysInCourse;
}

DegreeProgram Student::getdegreeProgram() const {
    return degreeProgram;
}

// D2b. Mutator(setter) to access data in student.h using "this" pointer.
void Student::setStudentId(string StudentIdToSet) {
    this->StudentId = StudentIdToSet;
}

void Student::setFirstName(string FirstNameToSet) {
    this->FirstName = FirstNameToSet;
}

void Student::setLastName(string LastNameToSet) {
    this->LastName = LastNameToSet;
}

void Student::setEmail(string EmailToSet) {
    this->Email = EmailToSet;
}

void Student::setAge(int AgeToSet) {
    this->Age = AgeToSet;
}

void Student::setDaysInCourse(int daysToSet[]) {
    for (int i = 0; i < DaysInCourseArraySize; i++) {
        this->DaysInCourse[i] = daysToSet[i];
    }
}

void Student::setdegreeProgram(DegreeProgram degreeProgramToSet) {
    this->degreeProgram = degreeProgramToSet;
}

//D2e. Output data from the student object's private members using getter functions. 
void Student::print() {
    cout << getStudentId() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getAge() << "\t";
    cout << "Course Length Days: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "} ";
    cout << "Degree: " << degreeString[static_cast<int>(getdegreeProgram())] << endl;
}

