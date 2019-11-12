#include<iostream>
using namespace std;

void maximum(int A[],int s)
{
    int maxim1,maxim2,maxim3;
    maxim1=maxim2=maxim3=-999;
    for(int i=0; i<s; i++)
    {
        if(A[i]>maxim1)
        {
            maxim3=maxim2;
            maxim2=maxim1;
            maxim1=A[i];
        }
    }
    cout<<"max1 : "<<maxim1<<"   max2 : "<<maxim2<<"   max3 : "<<maxim3<<endl;
}

int main()
{
    int a[]={10,4,10,12,13,19,7};

    maximum(a,7);
    return 0;
}
