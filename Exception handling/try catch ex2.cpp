#include<iostream>
using namespace std;

main()
{
	int marks;
	cout<<"Enter Marks: "<<endl;
	cin>>marks;
	
	try{
		if(marks<0||marks>100)
			throw marks;
		cout<<"\n"<<marks<<"\tValid Marks";
		
	}
	catch(int x)
	{
		cout<<marks<<"\tInvalid Marks!";
	}
}