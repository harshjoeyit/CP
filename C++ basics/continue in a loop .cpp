#include<iostream>
using namespace std;

int main()
{
     int a[]={10,1,15,1,1,45,72,81},i=0;

    for(i=0; i<8; i++)
    {
        if(a[i]%3 == 0)
            cout<<"\t"<<a[i];
         else if(a[i]==1)
            continue;     // skip processing of all the a[i] that are =1
                          //  control goes over to the loop again
    }
    return 0;
}
