#include<iostream>
using namespace std;

main()
{
	try{
		int choice;
		cout<<"Enter choice";
		cin>>choice;	
		
		if(choice==1)
			throw 10;
		else if(choice==2)
			throw 3.14;
	 	else
	 		throw"Unknown Choice";
	 
	}
	catch(int x)
	{
		cout<<"Integer Exception";
	}
	catch(int x)
	{
		cout<<"Double Exception";
		
	}
	catch(int x)
	{
		cout<<"String Exception";
	}
	

}