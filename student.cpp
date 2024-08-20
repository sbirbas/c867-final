#include <iostream>
#include "student.h"
#include "degree.h"
#include <iostream>
#include <sstream>

using namespace std;

//implementing contrustor for student class 
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i <3; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}

//getters
string Student::getStudentID(){ return studentID; }
string Student::getFirstName(){ return firstName; }
string Student::getLastName(){ return lastName; }
string Student::getEmail(){ return email; }
int Student::getAge(){ return age; }
int* Student::getDaysInCourse(){ return daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }
//setters
void Student::setStudentID(string studentID){ this->studentID = studentID; }
void Student::setFirstName(string firstName){ this->firstName = firstName; }
void Student::setLastName(string lastName){ this->lastName = lastName; }
void Student::setEmail(string email){ this->email = email; }
void Student::setAge(int age){ this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]){ for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i]; }
void DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

//display student details

void Student::print() {
    cout << "Student ID: " << studentID << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Email: " << email << endl;
    cout << "Days in Course: ";
    for (int i = 0; i < 3; i++) {
        cout << daysInCourse[i] << " ";
    }
    cout << endl;
    cout << "Degree Program: ";
    switch (degreeProgram) {
        case DegreeProgram::SECURITY:
            cout << "Security";
            break;
        case DegreeProgram::NETWORK:
            cout << "Network";
            break;
        case DegreeProgram::SOFTWARE:
            cout << "Software";
            break;
    }
    cout << endl;
}