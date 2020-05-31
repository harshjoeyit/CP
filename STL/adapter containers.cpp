#include<bits/stdc++.h>
using namespace std;

// string to number and number to string 
int main()
{
    //..............stack is implemented using deque by default 
    stack<int> int_stack;

    for( size_t ix = 0 ; ix != 10; ++ix )
        int_stack.push(ix);

    cout<<"stack: ";
    while( !int_stack.empty() )
    {
        int value = int_stack.top();
        int_stack.pop();
        cout<<"\t"<<value;
    }

    // ,..........adapter 
    vector<int> vec{1,2,3,4,5,6,7};  
    stack<int,vector<int>> S(vec);  //  7 is the top of the vector 

    cout<<"\nstack: ";
    while( !S.empty())
    {
        int value = S.top();
        S.pop();
        cout<<"\t"<<value;
    }

    //.................. ADAPTER 
    list<int> li{1,2,3,4,5,6,7};  
    stack<int,list<int>> S1(li);  //  7 is the top of the vector 

    cout<<"\nstack: ";
    while( !S1.empty())
    {
        int value = S1.top();
        S1.pop();
        cout<<"\t"<<value;
    }

    //............ queue 
    // by default queue uses deque for implementation

    queue<int> q;

    for( size_t ix = 0 ; ix != 10; ++ix )
        q.push(ix);     // the enqueue operation 

    cout<<"\nqueue : ";
    while( !q.empty())
    {
        int value = q.front();
        q.pop();
        cout<<"\t"<<value;
    }

    // adapter   
    // error in using queue with vector implementation 
    queue<int,list<int>> Q(li);

    cout<<"\nqueue: ";
    while( !Q.empty())
    {
        int value = Q.front();
        Q.pop();
        cout<<"\t"<<value;
    }

    // solving a postfix expresssion 
    string postfix = "36+";
    stack<int> stack_one;
    int value1 , value2;

    // think of th elin=miting condition for the loop
    for( int i = 0; ; i++ )
    {
        if( postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' )
        {
            value1 =  stack_one.top()- 48 ;
            stack_one.pop();
            value2 = stack_one.top()- 48 ;
            stack_one.pop();

            stack_one.push( value2 - value1 );
            break;    // done for solving this particular postfix expression 
        }
        else
        {
            stack_one.push( postfix[i] - 48 );
        }
    }

    cout<<"\ntop"<<stack_one.top();

}

