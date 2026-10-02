#include <iostream>
using namespace std;

class student
{
public:
    int rollNo;

    void getRollNo()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
    }

    void displayRollNo()
    {
        cout << "\nRoll No: " << rollNo << endl;
    }
};

class marks : public virtual student
{
protected:
    int marks; 
public:
    void getMarks() 
    {
        cout << "Enter Marks: ";
        cin >> marks;
    }
};

class sports : virtual public student
{
protected: 
    int sportMark;

public:
    void getSportMark()
    {
        cout << "Enter Sports Marks: ";
        cin >> sportMark;
    }
};


class result : public marks, public sports
{
public:
    int Result;

    void DisplayResult()
    {
        Result = marks + sportMark; 
        displayRollNo();
        cout << "\nMarks: " << marks << "\tSports Marks: "<<sportMark <<"\tTotal Result: " << Result << endl;
        
    }
};

int main()
{
    result obj;

  
    obj.getRollNo();
    obj.getMarks();
    obj.getSportMark();

    obj.DisplayResult();

    return 0;
}