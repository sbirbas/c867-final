// roster.cpp
#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

// init the roster with no students
Roster::Roster() : index(0) {}

Roster::~Roster()
{
    for (int i = 0; i <= index; ++i)
    {
        delete classRosterArray[i];
    }
}

// parse student and add the student to the roster
void Roster::add(string studentID, string firstName, string lastName, string email, int age, const int daysInCourse[], DegreeProgram degreeProgram) {
    if (index < 5) {
        int days[3];
        for (int i = 0; i < 3; ++i) {
            days[i] = daysInCourse[i];
        }
        classRosterArray[index] = new Student(studentID, firstName, lastName, email, age, days, degreeProgram);
        ++index;
    } else {
        cout << "Roster is full, cannot add more students." << endl;
    }
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
