#include<bits/stdc++.h>
using namespace std;


weak_ptr<int> weakPointer()
{
    return weak_ptr<int>();
}

int main()
{
    weak_ptr<int> wip();
    if ( wip == nullptr ) 
        cout<<"wip = nullptr"<<endl; 
    else 
        cout<<"wip : default initialized "<<endl;
    // cannot be checked if its value is nullptr or not
    // if statement does not work 
    shared_ptr<int> sip = make_shared<int>(42);
    // sip and wip2 point to same object 
    weak_ptr<int> wip2(sip);
    // cannot derefernce the weak pointer to access the value of the pointed object

    // using lock function 
    // returns true if the object exists i.e. shared_ptr exist 
    if( shared_ptr<int> np = wip2.lock() )
    {
        // 1. assignment , np = wip2 , returns a shared ptr if exists , else nullptr
        // 2. the if condition - false if np is nullptr , else true 
        // 3. safe access 
        cout<<"obj pointed bu wip2: "<<*np<<endl;
    }


}

