#include "student.h"
#include <string>

class Roster {
private:
    int index;

public:
    Student* classRosterArray[5];

    Roster();
    ~Roster();

    //functions for parsing, adding, removing, and printing students
    void parseAndAdd(string studentData);
    void add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, const int daysInCourse[], DegreeProgram degreeProgram);    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
