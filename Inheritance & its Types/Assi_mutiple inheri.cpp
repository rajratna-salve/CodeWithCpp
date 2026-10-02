/*
Q.No. 1 
Create two base classes: PersonalInfo and AcademicInfo.
PersonalInfo stores name and age.
AcademicInfo stores roll number and marks.
Create a class Student that inherits from both classes.
Display all student information and calculate the percentage.
Inheritance type: Multiple inheritance
Classes:
PersonalInfo   AcademicInfo
      \           /
       \         /
         Student
Example Input:
Name: Priya
Age: 20
Roll No: 25
Marks: 450
Total Marks: 500
Expected Output:
Name: Priya
Age: 20
Roll No: 25
Marks: 450/500
Percentage: 90%

*/

#include <iostream>
#include <string>
using namespace std;

class PersonalInfo
{
protected:
    string name;
    int age;

public:
    void getPersonalData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }
};

class AcademicInfo
{
protected:
    int rollNo;
    float marks;

public:
    void getAcademicData()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Marks: ";
        cin >> marks;
    }
};

class Student : public PersonalInfo, public AcademicInfo
{
protected:
    float percent;

public:
    void calDisplay()
    {
        getPersonalData();
        getAcademicData();

       
        percent = (marks / 500.0f) * 100;

        cout << "\n--- Student Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << "/500" << endl;
        cout << "Percentage: " << percent << "%" << endl;
    }
};

int main()
{
    Student s;
    s.calDisplay();

    return 0;
}