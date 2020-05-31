// deque 
// double ended queues 
// contiguous storage allocation may not be guaranteed.
//. A queue data structure allows insertion only at the end and deletion from the front
// a douboully ended que allows insertion and deletion ata the end and the infront
// most of the deque functions are same as vector 
// here are a few additional
// emplace creates the element withiut using the copy operation 
// pushback creates the element using the copy operation

#include<bits/stdc++.h>
using namespace std;

void display(deque<int> dq)
{
    cout<<endl;
    for(auto it = dq.begin(); it != dq.end(); it++)
        cout<<*it<<" ";
}

int main()
{ 
    deque<int> dq;
    dq = { 14,2,5,3,6,4,8,95,4,133};
    
    display(dq);

    // front adding
    dq.push_front(20);
    // back addding
    dq.push_back(12);
    cout<<"updated : "<<endl;;
    display(dq);


    // add in front 
    dq.emplace_front(19);
    // add in the end 
    dq.emplace_back(166);

    display(dq);

    // remove from front 
    dq.pop_front();
    // remove from back
    dq.pop_back();


    deque<int> dq1;
    dq1.assign(10,3);

    display(dq1);

    dq1.assign(dq.begin(),dq.begin()+6);

    display(dq1);

    dq1.assign({5,8,9,4,6,1});

    display(dq1);

    return 0;
}

