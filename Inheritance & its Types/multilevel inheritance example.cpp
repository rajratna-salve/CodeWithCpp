#include<iostream>
using namespace std;
class base
{
	private:
		int a,b;
	protected:
		int c;
		
	public:
		void set()
		{
			cout<<"\nEnter value for a and b: "<<endl;
			cin>>a>>b;
			c=a+b;
		}
		void get(){
			cout<<"\nBase class "<<"\nA= "<<a<<"\tB= "<<b<<"\tC= "<<c;
		}
};
class sub:public base
{
	private:
		int p,q,ans;
	public :
		void set(){
			base::set();
			cout<<"\nEnter value for p and q: "<<endl;
			cin>>p>>q;
			ans=(p*q)+c;
		}
		void get(){
			base::get();
			cout<<"\nsub class"<<"\nP= "<<p<<"\tQ= "<<q<<"\tAns="<<ans;
		}
};
main(){
	sub obj;
	obj.set();
	obj.get();
}