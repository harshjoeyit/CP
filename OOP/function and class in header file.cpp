#include<iostream>
#include"myheader.h"
using namespace std;

void printname();
void bubblesort(int (&a)[100],int sz);

int main()
{
    printname();
    int a[100]={10,5,4,8,7,56,78};
    bubblesort(a,7);
    for(int i=0; i<7; i++)
        cout<<a[i]<<" ";

// you could also define a class in the header file and use it anywhere you want to.

    student obj;
    cout<<"enter the class variables: "<<endl;
    cin>>obj.x>>obj.y;
    cout<<obj.x<<endl<<obj.y;
    return 0;

}
