#pragma once
#include "student.h"

class Roster
{
private:
	int classSize;
	int locator;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	Roster(int classSize);
	string GetStudentID(int index);
	void parse(string studentRow);
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};