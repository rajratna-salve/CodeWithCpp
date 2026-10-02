/*
Q.No. 2
Employee Payroll
Create two base classes:
Employee — stores employee ID and name.
Salary — stores basic salary and allowances.
Create a class Payroll that inherits from both and calculates the employee's net salary after deductions.
Inheritance:
Employee     Salary
    \         /
     \       /
      Payroll

*/
#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    int Id;

public:
    void getEmp()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Id: ";
        cin >> Id;
    }
};

class Salary
{
protected:
   double sal,allowance;

public:
    void getSalary()
    {
        cout << "\nEnter Salary: ";
        cin >> sal;
        cout << "\nEnter allowance: ";
        cin >>allowance ;
    }
};

class payroll : public Employee, public Salary
{
protected:
    double netSalary;

public:
    void PayDisplay()
    {
        getEmp();
        getSalary();

       
       netSalary=sal-allowance;

        cout << "\n--- Employee Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Id: " << Id << endl;
        cout << "Salary: " << sal<< endl;
        cout << "Allowance: " << allowance  << endl;
        cout << "Net Salary: " << netSalary << " Rs" << endl;
    }
};

int main()
{
   payroll s;
    s.PayDisplay();

    return 0;
}