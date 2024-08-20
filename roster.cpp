// roster.cpp
#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

// init the roster with no students
Roster::Roster() : index(-1) {}

Roster::~Roster()
{
    for (int i = 0; i <= index; ++i)
    {
        delete classRosterArray[i];
    }
}

// parse student and add the student to the roster
void Roster::parseAndAdd(string studentData)
{
    stringstream ss(studentData);
    string token;
    string studentID, firstName, lastName, emailAddress, degreeString;
    int age, daysInCourse1, daysInCourse2, daysInCourse3;
    DegreeProgram degreeProgram;

    getline(ss, studentID, ',');
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, emailAddress, ',');
    ss >> age;
    ss.ignore();
    ss >> daysInCourse1;
    ss.ignore();
    ss >> daysInCourse2;
    ss.ignore();
    ss >> daysInCourse3;
    ss.ignore();
    getline(ss, degreeString);

    // Convert degree string to DegreeProgram enum
    if (degreeString == "SECURITY")
    {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (degreeString == "NETWORK")
    {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (degreeString == "SOFTWARE")
    {
        degreeProgram = DegreeProgram::SOFTWARE;
    }

    // add student to roster
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

// adds new student to roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, const int daysInCourse[], DegreeProgram degreeProgram)
{
    if (index < 0 || index >= 100)
    { // Assuming a maximum of 100 students
        cout << "Roster is full or index is invalid!" << endl;
        return;
    }
    classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

// remove a student
void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i <= index; ++i)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[index];
            classRosterArray[index] = nullptr;
            --index;
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "Student " << studentID << " has been removed" << endl;
    }
    else
    {
        cout << "Student " << studentID << " was not found" << endl;
    }
}
void Roster::printAll()
{
    cout << "List of Student Data:" << endl;
    for (int i = 0; i <= index; ++i)
    {
        classRosterArray[i]->print();
    }
}

// print a students average number of days in course
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= index; ++i)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            int *days = classRosterArray[i]->getDaysInCourse();
            cout << "Student ID " << studentID << " average days in course: "
                 << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
    cout << "Student ID " << studentID << " not found." << endl;
}

void Roster::printInvalidEmails()
{
    bool invalidFound = false;
    for (int i = 0; i <= index; ++i)
    {
        string emailAddress = classRosterArray[i]->getEmail();
        if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos)
        {
            cout << "Invalid email for student ID " << classRosterArray[i]->getStudentID() << ": " << emailAddress << endl;
            invalidFound = true;
        }
    }
    if (!invalidFound)
    {
        cout << "No invalid email addresses found." << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    for (int i = 0; i <= index; ++i)
    {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->print();
        }
    }
}
