#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

Student::Student() // Sets default values
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->studentEmail = "";
	this->age = 0;
	for (int i = 0; i < courseArraySize; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::NONE;
}

Student::Student(string studentID, string firstName, string lastName, string studentEmail, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->studentEmail = studentEmail;
	this->age = age;
	for (int i = 0; i < courseArraySize; i++) {
		this->days[i] = days[i];
	}
	this->degreeProgram = degreeProgram;
}

Student::~Student() {} // Destructor

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getStudentEmail() { return this->studentEmail; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string ID) { this->studentID = ID; }
void Student::setFirstName(string fname) { this->firstName = fname; }
void Student::setLastName(string lname) { this->lastName = lname; }
void Student::setStudentEmail(string email) { this->studentEmail = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int days[]) {
	for (int i = 0; i < courseArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader()
{
	cout << "Output format: StudentID|FirstName|LastName|StudentEmail|Age|Days|DegreeProgram|\n";
}

void Student::print()
{
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getStudentEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << DegreeProgramStrings[this->getDegreeProgram()] << '\n';
}