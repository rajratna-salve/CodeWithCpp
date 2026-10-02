#include <iostream>
#include <string>
using namespace std;

class A
{

protected:
    int sq,a;

public:
    void set()
    {
        cout << "\nEnter a ";
        cin >> a;
        sq=a*a;
        cout<<"Suqare: "<<sq;
    }
};

class B
{
protected:
    int cube,a1;

public:
    void set()
    {
        cout << "\nEnter A of Cube:";
        cin >> a1;
        cube=a1*a1*a1;
        cout<<"\nCube: "<<cube;
        
    }
};

class C : public A, public B
{

protected:
    double ans,p,q;

public:
    void set()
    {
        A::set();
        B::set();

        cout << "\nEnte P and Q:  ";
        cin >> p>>q;
	
        ans=p+q*sq*cube;
        cout << "\nAns = " << ans << endl;
    }
};

int main()
{
    C c;
    c.set();

    return 0;
}