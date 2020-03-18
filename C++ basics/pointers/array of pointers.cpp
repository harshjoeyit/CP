#include<iostream>
using namespace std;

void print(int (*ia)[10])
{
    for(int j=0; j<10; j++)
    {
        cout<<(*ia)[j]<<" ";
    }
    cout<<endl;
}
// difference b/w array of pointers and pointer ti an array
main()
{
    int a[10]={1,2,3,4,5};
    int *poi[10];  // an array of pointers

    for(int i=0; i<10; i++)
        poi[i]=&a[i];// assigning to every int in array

    int (*p)[10];  // p pointer points to an array of 10 integers
    p=&a;  // IMP: assigning only base address
    print(p);

    for(int i=0; i<10; i++)
        cout<<*poi[i];
}

