#include "roster.h"

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>
#include <string>

using namespace std;


//Class Constructor
Roster::Roster(int classSize) {
	this->classSize = classSize;
	this->locator = 0;
	for (int index = 0; index < classSize; index++) {
		this->classRosterArray[index] = new Student;
	}
	return;
}

string Roster::GetStudentID(int index) {

	string sID = classRosterArray[index]->getStudentID();
	return sID;
}


// Parse method
void Roster::parse(string studentDataTable) {
	string studentID, firstName, lastName, studentEmail, degreeStr;
	int age, daysInCourse[3];

	if (locator < classSize) {
		classRosterArray[locator] = new Student();

		int x = 0;
		int y;

		for (int index = 0; index < 9; index++) {
			y = studentDataTable.find(",", x);
			string value = studentDataTable.substr(x, y - x);
			x = y + 1;

			switch (index) {
			case 0: studentID = value; break;
			case 1: firstName = value; break;
			case 2: lastName = value; break;
			case 3: studentEmail = value; break;
			case 4: age = stoi(value); break;
			case 5: daysInCourse[0] = stoi(value); break;
			case 6: daysInCourse[1] = stoi(value); break;
			case 7: daysInCourse[2] = stoi(value); break;
			case 8: degreeStr = value; break;
			}
		}

		classRosterArray[locator]->setStudentID(studentID);
		classRosterArray[locator]->setFirstName(firstName);
		classRosterArray[locator]->setLastName(lastName);
		classRosterArray[locator]->setStudentEmail(studentEmail);
		classRosterArray[locator]->setAge(age);
		classRosterArray[locator]->setDaysInCourse(daysInCourse);

		if (degreeStr == "SOFTWARE") {
			classRosterArray[locator]->setDegreeProgram(SOFTWARE);
		}
		else if (degreeStr == "SECURITY") {
			classRosterArray[locator]->setDegreeProgram(SECURITY);
		}
		else if (degreeStr == "NETWORK") {
			classRosterArray[locator]->setDegreeProgram(NETWORK);
		}
		else {
			cout << "Degree not found" << endl;
		}

		locator++; 
	}
}

// Add a student to the Roster

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	if (locator < numStudents) {
		int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		classRosterArray[locator] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		locator++;
	}
}


// Remove a student from the Roster

void Roster::remove(string studentID) {

	bool StudentExists = false;
	for (int index = 0; index < classSize; index++) {
		if (classRosterArray[index] == nullptr) {
			continue;
		}
		else if (studentID == classRosterArray[index]->getStudentID()) {
			classRosterArray[index] = nullptr;
			StudentExists = true;
			break;
		}
	}
	if (StudentExists == false) {
		cout << "Error: Student " << studentID << " is not on the roster." << endl;
	}
	else if (StudentExists == true) {
		cout << "Student " << studentID << " has been located and removed." << endl;
	}
	return;
}

// Print all students in the Roster

void Roster::printAll() {
	cout << "All of the students in the roster are as follows: " << endl;
	for (int index = 0; index < classSize; index++) {
		if (classRosterArray[index] == nullptr)
		{
			continue;
		}
		else {
			classRosterArray[index]->print();
		}
	}
	cout << endl;
	return;
}

// Print the average number of days in each course

void Roster::printAverageDaysInCourse(string studentID) {
	for (int index = 0; index < classSize; index++) {
		if (studentID == classRosterArray[index]->getStudentID())
		{
			cout << studentID << "" << "'s average day count for each course:" << ((classRosterArray[index]->getDays()[0] + classRosterArray[index]->getDays()[1] + classRosterArray[index]->getDays()[2]) / 3) << endl;
		}
	}
	return;
}

// Print invalid student emails from the Roster

void Roster::printInvalidEmails() {
	for (int index = 0; index < classSize; ++index) {
		string emailAd = classRosterArray[index]->getStudentEmail();
		if ((emailAd.find('.') == string::npos) || (emailAd.find('@') == string::npos) || (emailAd.find(' ') != string::npos)) {
			cout << "Invalid Email Addresses:" << classRosterArray[index]->getStudentID() << "'s email: " << emailAd << " is invalid." << endl;
		}
	}
	cout << endl;
	return;
}



// Print students based on their degree program

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string degreeString;
	if (degreeProgram == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "Null or invalid value detected";
	}
	
	cout << "Students in the degree program: " << degreeString << endl;
	
	int studentCount = 0;

	for (int index = 0; index < classSize; index++) {
		if (classRosterArray[index]->getDegreeProgram() == degreeProgram) {
			classRosterArray[index]->print();
			++studentCount;
		}
	}
	if (studentCount == 0) {
		cout << "None" << endl;
	}
	return;
}


// Destructor

Roster::~Roster() {
	for (int index = 0; index < 5; index++) {
		delete classRosterArray[index];
		classRosterArray[index] = nullptr;
	};


}
