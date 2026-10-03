/*The famous diamond problem is a problem when a single grandparent is inherited by two classes and further these two classes create one subclass. 

It's a classic example of multi-level inheritance taking place with multiple inheritance. 

In normal cases activation of a child will activate both the parent and also from each parent twice the grandparent class. 

In order to stop this we can use something called a virtual base class. 

Simple. Using `virtual` as a keyword in inheritance will allow only one activation to the grandparent class, coming from the first inherited class only. 
*/

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

class Student : public virtual Human
{
public:
    string degree;

    Student()
    {
        cout << "Student constructor called" << endl;
    }
};

class Employee : virtual public  Human
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


