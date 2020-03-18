#include<bits/stdc++.h>
using namespace std;


int main()
{


    
    priority_queue <int, vector<int>, greater<int>> pq;             // min heap
    priority_queue <int, deque<int>, greater<int>> pq1;             // min heap

    pq.emplace(10);
    pq.push(12);
    pq.push(5);
    pq.push(22);
    pq.push(15);

    while( !pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;





    priority_queue <string, vector<string>, greater<string> > pq2;             // min heap

    pq2.emplace("reek");
    pq2.push("nokia");
    pq2.push("zoopack");
    pq2.push("aala");
    pq2.push("bunick");

    while( !pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;





    priority_queue<int> pq3;            // max heap

    pq3.emplace(10);
    pq3.push(12);
    pq3.push(5);
    pq3.push(22);
    pq3.push(15);

    while( !pq3.empty())
    {
        cout << pq3.top() << " ";
        pq3.pop();
    }
    cout << endl;






    priority_queue<string> pq4;             // max heap

    pq4.emplace("reek");
    pq4.push("nokia");
    pq4.push("zoopack");
    pq4.push("aala");
    pq4.push("bunick");

    while( !pq4.empty())
    {
        cout << pq4.top() << " ";
        pq4.pop();
    }
    cout << endl;    





    priority_queue<pair<int, int> > pq5;            // heap

    pq5.emplace(make_pair(3,4));
    pq5.push({3,5});
    pq5.push({4,4});
    pq5.push({5,5});
    pq5.push({4,6});

    while( !pq5.empty())
    {
        cout << "(" << pq5.top().first << "," << pq5.top().second << ")" << "\t";
        pq5.pop();
    }
    cout << endl;   





    priority_queue < pair<int, int>, vector<pair<int, int >>, greater<pair<int, int>> > pq6;         // min heap

    pq6.emplace(make_pair(3,4));
    pq6.push({3,5});
    pq6.push({4,4});
    pq6.push({5,5});
    pq6.push({4,6});

    while( !pq6.empty())
    {
        cout << "(" << pq6.top().first << "," << pq6.top().second << ")" << "\t";
        pq6.pop();
    }
    cout << endl;  
}