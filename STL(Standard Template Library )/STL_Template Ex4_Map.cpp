#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<int,string> students;
	
	students[101] = "Rahul";
	students[102] = "Ratna";
	students[103] = "Raj";
	
	cout<<"Student 103: "<<students[103]<<endl;
	
}