#include<iostream>
using namespace std;

main()
{
	try
	{
		cout<<"Try Block";
		int age=25;
		if(age<18)
			throw age;
	
		cout<<"\nYou are eligible";
		cout<<"\tEnd of try";
	}
	catch(int x)
	{
		cout<<" \nException:Age is less than 18. n ";
	}
}