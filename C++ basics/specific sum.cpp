#include<iostream>
using namespace std;

int main()
{
    int a[10]={6,4,5,3,7,8,2,1,9,0};

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if((a[i]+a[j])==10 && a[i]<10)
            {
                cout<<"("<<a[i]<<"+"<<a[j]<<")"<<endl;
            }
        }
    }

}
