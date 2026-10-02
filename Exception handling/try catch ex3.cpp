#include<iostream>
using namespace std;

main()
{
	int choice;
	cout<<"Enter Choice";
	cin>>choice;
	try
	{
	 	if(choice==1)
	 		throw 100;
	 		
	 	if(choice==2)
	 		throw'X';
			  
		if(choice==3)
			throw "Invalid Operation";
	}
		 catch(int x)
		 {
		 	cout<<"Integer Exception: "<<x; 
		 }
}