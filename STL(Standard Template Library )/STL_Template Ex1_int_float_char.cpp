#include<iostream>
using namespace std;

template<typename T>
T maximum(T a,T b)
{
	if(a>b)
		return a;
	else
		return b;	
}
int main()
{
	cout<<"\nMaximum integer: "<<maximum(10,20)<<endl;
	
	cout<<"\nMaximum float: "<<maximum(5.5,2.6)<<endl;
	
	cout<<"\nMaximum char: "<<maximum('A','B')<<endl;	
}