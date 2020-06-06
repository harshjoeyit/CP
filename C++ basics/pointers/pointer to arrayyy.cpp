#include<iostream>
using namespace std;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8}; // returns a pointer to an array of five int elements
float od[] = {1.0,3.0,5.0,7.0,9.0};
float eve[] = {0.0,2.0,4.0,6.0,8.0}; // returns a pointer to an array of five int elements
auto func(float i) -> float(*)[5]
{
    return (i > 2) ? &od : &eve;
}

decltype(odd) *func(int i)
{
    return (i % 2) ? &odd : &even; // returns a pointer to the array
}

int main()
{
    int i;
    while(cin>>i)
    {
        cout<<"array: ";
        int (*p)[5]=func(i);  // holding the returned value
        for(int i=0; i<5; i++)
        {
            cout<<(*p)[i]<<" ";  // most important ( ) around p
        }
        cout<<endl;

        int (*poi)[5]=func(i);  // holding the returned value
        for(int i=0; i<5; i++)
        {
            cout<<(*p)[i]<<" ";
        }
        cout<<endl;
    }
}
