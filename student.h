#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;
#pragma once

using namespace std;

class Student
{
public:
	const static int courseArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string studentEmail;
	int age;
	int days[courseArraySize];
	DegreeProgram degreeProgram;
public:
	Student(); // Set Default values
	Student(string studentID, string firstName, string lastName, string studentEmail, int age, int days[], DegreeProgram degreeProgram); 
	~Student(); // Destructor

	// Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getStudentEmail();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	// Setters
	void setStudentID(string ID);
	void setFirstName(string fname);	
	void setLastName(string lname);
	void setStudentEmail(string email);
	void setAge(int age);
	void setDaysInCourse(int days[]);
	void setDegreeProgram(DegreeProgram dp);

	void printHeader();
	void print(); // Display specific student's data
};

