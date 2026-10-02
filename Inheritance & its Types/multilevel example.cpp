#include <iostream>
#include <string>
using namespace std;

// Base class
class Human
{
protected:
    string name;
    string gender;

public:
    Human(string name, string gender)
    {
        this->name = name;
        this->gender = gender;
    }

    void displayHuman()
    {
        cout << "\nName   : " << name;
        cout << "\nGender : " << gender;
    }
};


// Derived class
class Student : public Human
{
protected:
    string degree;

public:
    Student(string name, string gender, string degree)
        : Human(name, gender)
    {
        this->degree = degree;
    }

    void displayStudent()
    {
        displayHuman();
        cout << "\nDegree : " << degree;
    }
};


// Derived class
class Employee : public Student
{
private:
    double salary;

public:
    Employee(string name, string gender, string degree, double salary)
        : Student(name, gender, degree)
    {
        this->salary = salary;
    }

    void displayEmployee()
    {
        displayStudent();
        cout << "\nSalary : " << salary;
    }
};


int main()
{
    // Only Employee object is created
    Employee e("Raj", "Male", "BTech AI & DS", 25000);

    e.displayEmployee();

    return 0;
}
