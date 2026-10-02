#include<iostream>
using namespace std;

main()
{
	float a,b;
	cout<<"Enter Two Numbers: ";
	cin>>a>>b;	
	try
	{
		if(b==0)	
			throw "Number Cannot Divisible by Zero.";
		cout<<"Result: "<<a/b;
	}
	catch(const char *message)
	{
		cout<<"Exception: "<<message;
	}
}