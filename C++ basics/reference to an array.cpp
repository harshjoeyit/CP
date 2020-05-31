#include<iostream>
using namespace std;

using arrtT = int[5];  // arrtT is used as an array of five integers
arrtT &func(int (&r)[5])  // returns reference to array of 5 int (arrtT) after receiving an argument of type of reference to an array
{
    return r;
}
int main()
{
    int a[]={1,2,3,4,5};
    int arr[]={10,20,30,40,50};
    int (&r)[5]=a;  // reference to an array. without using arrtT

    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<"-"<<r[i]<<endl;
    }

    //typedef int arrT[10];
    arrtT &refer=arr;   // declaring reference to an array
    arrtT &r2=func(refer);  // declaring another variable to hold the reference to array returned in the function call.

    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<"-"<<r2[i]<<endl;
    }

    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<"-"<<refer[i]<<endl;
    }
    return 0;
}
