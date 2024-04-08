#include "roster.h"
#include <string>
#include <iostream>
using namespace std;


//F1
int main() {
    cout << "Course Title: C867 - Scripting and Programming Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 010924506" << endl;
    cout << "Name: Robert Wright" << endl << endl;

	const int numStudents = 5;
	const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Robert,Wright,rwri326@wgu.edu,28,21,10,11,SOFTWARE"
	};
     // F2. Declare instance of Roster called classRoster
    Roster classRoster(5);
    
     //f3. Add to Class Roster
    for (int i = 0; i < numStudents; i++) {
		classRoster.parseAndAdd(studentData[i]);
	}
    

    // f4. Print all student data
    cout << "Printing all student data:" << endl;
    cout << "--------------------------" << endl;
    classRoster.printAll();
    cout << endl;

    // Print invalid email addresses
    cout << "Invalid Email Addresses:" << endl;
    cout << "------------------------" << endl;
    classRoster.printInvalidEmails();
    cout <<endl;

    cout << "Average Days In Course:" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i <= classRoster.lastIndex; i++) {
        string studentId = classRoster.ClassRosterArray[i]->getStudentId();
        classRoster.printAverageDaysInCourse(studentId);
    }
    // Print students in SOFTWARE degree program
    cout << "Students in SOFTWARE degree program:" << endl;
    cout << "------------------------------------" << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;

    // Remove a student and print updated roster
    classRoster.remove("A3");
    cout << "Roster after removing student with ID A3:" << endl;
    cout << "-----------------------------------------" << endl;
    classRoster.printAll();
    cout << endl;
    
    
    
    return 0;
    
}

