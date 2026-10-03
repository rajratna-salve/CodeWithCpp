#include<iostream>
using namespace std;

template<typename T,typename U>

void Display(T a,U b)
{
	cout<<"First Value: "<<a<<endl;	
	
	cout<<"Second Value: "<<b<<endl;	
}
int main()
{
	Display(10,20.5);
	
}