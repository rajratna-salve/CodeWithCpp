//The diamond problem.


It's a classic example of multi-level inheritance taking place with multiple inheritance. 
 
#include <iostream>
using namespace std;

class Human
{
public:
    string name;

    Human()
    {
        cout << "Human constructor called" << endl;
    }
};

class Student : public Human
{
public:
    string degree;

    Student()
    {
        cout << "Student constructor called" << endl;
    }
};

class Employee : public  Human
{
public:
    string company;

    Employee()
    {
        cout << "Employee constructor called" << endl;
    }
};

class WorkingStudent : public Student, public Employee
{
public:
    void display()
    {
      cout<<"\nWorking Student:my display";
    }
};

int main()
{
    WorkingStudent obj;
	obj.display();

    return 0;
}

