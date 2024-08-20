#include "student.h"
#include <string>

class Roster {
    private:
    Student* classRosterArray[5];
    int lastIndex;

    public:
    Roster();
    ~Roster();

    //functions for adding, removing, and printing students
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};