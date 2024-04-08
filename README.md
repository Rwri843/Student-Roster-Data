# Student Roster Program
This is the implementation of a student roster program as part of the WGU Scripting and Programming - Applications course (C867). The program is written in C++ and manages a roster of students, including adding, removing, and displaying student records.

### <u>Features<u/>
- Add new students to the roster
- Remove students from the roster
- Display student information
- Calculate and display student average grades
- Identify invalid email addresses and print them to the console
- Print a list of software degree students

### <u>Installation<u/>
- Clone the repository to your local machine.
- Compile the source code using a C++ compiler (e.g., g++).
- Run the compiled executable to start the program.
### <u>Usage<u/>
- Upon running the program, follow the on-screen instructions to perform various operations on the student roster.
- Use the menu options to add, remove, or display student information as needed.
### Example
''' cpp
Copy code
// Sample code snippet demonstrating usage
#include "roster.h"

int main() {
    Roster roster;
    // Add students to the roster
    roster.addStudent("John", "Doe", "john.doe@email.com", 1, {85, 90, 95});
    // Display student information
    roster.printAll();
    // Remove a student from the roster
    roster.removeStudent("John Doe");
    return 0;
}
'''
