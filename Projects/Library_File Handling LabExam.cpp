#include<iostream>
#include<fstream>
using namespace std;
class Library{
	public :
		int ID;
		string title,auther;
		string avl;
	void input(){
		cout<<"\nEnter ID:";
		cin>>ID;
		cout<<"\nEnter Title: ";
		cin>>title;
		cout<<"\nEnter Auther Name: ";
		cin>>auther;
		cout<<"\nEnter availability: ";
		cin>>avl;
	}
	void display()
			
	{			
		
		cout<<"\nId: "<<ID;
		cout<<"\nTitle: "<<title;
		cout<<"\nAuther: "<<auther;
		cout<<"\nAvailability: "<<avl;
		
	}	
};

main()
{
	Library e;
	int choice;
	do
	{
		cout<<"\n1.Add Book info";
		cout<<"\n2.Display ";
		cout<<"\n3.Exit";
		cout<<"\nEnter the choice: ";
		cin>>choice;
		
		if(choice==1)
		{
			ofstream file("LibraryInfo.txt", ios::app);
			e.input();
			
			file<<e.ID<<"\nBook Id: ";
			file<<e.title<< "\nTitle: ";
			file<<e.auther<<"\nAuther: ";
			file<<e.avl<<"\nAvailabilbity: ";
			
		file.close();
		cout<<"Record added successfully.";	
		}
		
		else if(choice==2)
		{
			ifstream file("LibraryInfo.txt");
			while(file>>e.ID>>e.title>>e.auther>>e.avl)
			{
			e.display();
	     	}
		}
		
		
	}
	while(choice!=0);
}
	
