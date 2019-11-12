// all the function use cases are based on the concept that function pointer can be passed as an argument to another function 
#include<bits/stdc++.h>
using namespace std;

// function pointers and callbacks 

void A()  // callback function
{
    printf("hello\n");
}

void B( void (*ptr)() )  // function pointer as argument
{
    (*ptr)();  //or simply ptr();
    // call_back function that "ptr " points to 
}

int main()
{
    void (*p)() = A;  // or &A
    B(p);

    // an alternative 

    B(A);   // we know A works as pointer argument

    return 0;
}