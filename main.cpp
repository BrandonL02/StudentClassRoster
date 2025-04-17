#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>

using namespace std;

int main()
{

    cout << "Course Title: Course 123" << endl;
    cout << "Programming Language Used: C++ " << endl;
    cout << "Student ID: 12345678 " << endl;
    cout << "Student Name: Brandon L" << endl;
    cout << "   " << endl;
    cout << "   " << endl;



    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brandon,Latimer,blatim9@wgu.edu,23,21,55,40,SOFTWARE"
    };


    Roster* classRoster = new Roster(5);
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };


    classRoster->printAll();
    cout << endl;
    cout << endl;

    classRoster->printInvalidEmails();

    //loop through classRosterArray and for each element:

    for (int i = 0; i < 5; i++) {

        classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
    }
    cout << endl;
    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;
    cout << endl;

    classRoster->remove("A3");
    cout << endl;
    cout << endl;

    classRoster->printAll();
    cout << endl;
    cout << endl;

    classRoster->remove("A3");
    cout << endl;
    
    //expected: the above line should print a message saying such a student with this ID was not found.


    classRoster->~Roster();
    delete classRoster;

}
