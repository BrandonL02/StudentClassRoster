# Student Roster Management System – C++

## Overview 📘

This project is a student management system created using C++ and object-oriented design principles. The system reads, parses, stores, and manipulates student data including their ID, name, email, age, time to complete courses, and degree program.

---

### Project Structure 📂

/StudentRoster/
- degree.h           # Enum for DegreeProgram
- student.h          # Student class declaration
- student.cpp        # Student class implementation
- roster.h           # Roster class declaration
- roster.cpp         # Roster class implementation
- main.cpp           # Application entry point and functionality demonstration
- screenshot.png     # Screenshot of console output demonstrating functionality

---

### Scenario Description 📋

You were contracted by a university to migrate their existing student management system to a C++ application. This app reads hardcoded student data and allows the user to:

- Add and remove students

- Display all student data

- Validate email addresses

- Show average days in course

- Filter students by degree program

---

### Sample Data 🧾(studentData[])

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,YourFirstName,YourLastName,your.email@domain.com,25,25,30,35,SOFTWARE"
};

### Output Screenshot 📸

![output from sample data](http)

---

### Memory Management 🧼
A destructor is implemented in the Roster class to deallocate dynamically allocated memory and avoid memory leaks.
