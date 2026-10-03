#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    queue<int> q2;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;

    if(q.empty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    q.emplace(40);

    cout << "Front after emplace: " << q.front() << endl;

    q.pop();

    cout << "Front after pop: " << q.front() << endl;

    q2.push(100);
    q2.push(200);

    q.swap(q2);

    cout << "Front of queue q after swap: " << q.front() << endl;
    cout << "Front of queue q2 after swap: " << q2.front() << endl;

    return 0;
}