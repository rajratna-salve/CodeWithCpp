/*
Problem Statement
*/

#include<iostream >
using namespace std;
 class Book
 {
 	public:
 		int bookId;
 		string title,auther;
		bool isAvailable; 
		
		Book()
		{
			bookId='\0';
			title="";
			auther="";
			isAvailable=true;
			
		}
		Book(int bookId,string title,string auther)
		{
			this->bookId=bookId;
			this->title=title;
			this->auther=auther;
			this->isAvailable=isAvailable;
			
		}
		void input()
		{
			cout<<"Enter Book Id: ";
			cin>>bookId;
			cout<<"Enter Book title: ";
			cin>>title;
			cout<<"Enter Book auther: ";
			cin>>auther;
	
		}
		void display()
		{
			cout<<"\nBook Id: "<<bookId;
			cout<<"\nBook Title: "<<title;
			cout<<"\nBook Auther: "<<auther;
			
		}
		void issueBook()
		{
			int Id;
			cout<<"Enter Id: "<<endl;
			cin>>Id;
			 
			if(bookId==Id){
				cout<<"\nBook is Available"<<title;
			}
			else
			{
				cout<<"\nBook is not Available";
			}
			
		}
		void returnBook()
		{
			
		}
	~Book(){
		cout<<"Book object is Destroyed:";
	}		
 };
 main()
 {
 	
 	Book obj;
 	int choice;
 	do
 	{
 		cout<<"\n1.Add book";
 		cout<<"\n2.Display";
 		cout<<"\n3.Issue Book";
 		cout<<"\n4.Return book.";
 		cout<<"\n5.Exit"<<endl;
 		
 		cout<<"Enter Choice:"<<endl;
 		cin>>choice;
 		
 		if(choice==1)
 		{
 			obj.input();
		 }
		 else if(choice==2)
		 {
		 	obj.display();
		 }
		 else if(choice==3)
		 {
		 	obj.issueBook();
		 }
		 else if(choice==4)
		 {
		 	obj.returnBook();
		 }
		 else if(choice==5)
		 {
		 	cout<<"Exit";
		 }
		 else
		 {
		 	cout<<"\nInvalid Choice";
		 }
 		
	 }
	 while(choice!=5);
 
 	
 }