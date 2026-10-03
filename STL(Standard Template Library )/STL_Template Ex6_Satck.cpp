#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    stack<int> s2;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    if(s.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    s.emplace(40);

    cout << "Top after emplace: " << s.top() << endl;

    s.pop();

    cout << "Top after pop: " << s.top() << endl;

    s2.push(100);
    s2.push(200);

    s.swap(s2);

    cout << "Top of stack s after swap: " << s.top() << endl;
    cout << "Top of stack s2 after swap: " << s2.top() << endl;

    return 0;
}