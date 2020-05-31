#include<bits/stdc++.h>
using namespace std;

// type alias
typedef unique_ptr<int> U_Iptr;
using UIP = unique_ptr<int> ;

// function that would return a unique pointer 
unique_ptr<int> clone( int p )
{
    // returning the pointer that would be inititialized with the value in the argument 
    return unique_ptr<int>( new int(p) );
}


int main()
{
    shared_ptr<int> s;
    unique_ptr<string> p;

    if( p == NULL )
        cout<<"p points to null "<<endl;
    else
        cout<<"p points to: "<<*p<<endl;
    


    // using new to create memory
    unique_ptr<int> u_ptr( new int(42) );
    // no copy for uniqued_ptr , no assign 
    cout<<"*u_ptr: "<<*u_ptr<<endl;



    // transfer ownership of p2 pointer to a built in pointer 
    int *q = new int(56);  // q must be a built i pointer 
    u_ptr.reset(q);
    // u_ptr now points to object pointed by q
    if( u_ptr == NULL )
        cout<<"u_ptr now points to null "<<endl;
    else
        cout<<"u_ptr npw points to: "<<*u_ptr<<endl;

    

    // transfer control to a dynamic pointer 
    unique_ptr<string> usptr1( new string("ragnarok"));
    cout<<"usptr1: "<<*usptr1<<endl;
    
    unique_ptr<string> usptr2( usptr1.release() );
    //1. release makes trnasfer of ownership to usptr2 by usptr1  
    //2. release makes usptr1 null and the location is now pointed by usptr2 
    cout<<"usptr2: "<<*usptr2<<endl;

    if( usptr1 == NULL )
        cout<<"usptr1 now points to null "<<endl;

    p.reset( usptr2.release() );
    cout<<"p: "<<*p<<endl;
    //1. reset deletes the object to which the pointer points,
    //2. if argument is supplid in the call 
    // then pointer p points to that object 
    // otherwise u is null
    // here upstr2.release  1. transfers ownership ,2. makes upstr2 becomes null

    if( usptr2 == NULL )
        cout<<"usptr2 now points to null "<<endl;
    
    p.reset();
    // no arguments are passed so 
    // 1. memory deletion
    // 2. making p null
    if( p == NULL )
        cout<<"p now points to null "<<endl;

    
    // declaring some unique pointers 
    int x = 1024 ,*p1 = &x ;
    int *pi2 = new int(2048);   //built int pointer 
    //U_Iptr p1(x); 
    //error new operator not used and no dyn memory used 
    //UIP p2(pi);

    UIP p3(pi2);                // attaching the unique pointer to the built in pointer
    cout<<"p3: "<<*p3<<endl;

    U_Iptr p4( p3.get() );      //p3.get() returns a built in pointer to the call location , pointing to the object owned by unique_ptr 
    cout<<"p4: "<<*p4<<endl; 
}