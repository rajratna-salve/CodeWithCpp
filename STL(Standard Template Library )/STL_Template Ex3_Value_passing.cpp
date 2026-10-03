#include<iostream>
using namespace std;

template<typename T>

class Box
{
	private:
		T value;
		
	public: 
		void setValue(T v)
		{
			value = v;	
		}	
		void display()
		{
			cout<<"Value: "<<value<<endl;
		}	
};
int main()
{
	Box<int> b1;
	b1.setValue(100);
	b1.display();
	
	Box<double> b2;
	b2.setValue(10.33);
	b2.display();
	
	Box<string> b3;
	b3.setValue("Raj");
	b3.display();
	
}