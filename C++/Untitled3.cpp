#include<bits/stdc++.h>
using namespace std;

int start = 1;

bool compare ( int a[] , int N, int *start )
{
    int s =1;
    for(int i=N-1;  i>0; i--)
    {
        if( a[i]==a[i-1] )
            ++(*start);
        else
            return true;
    }
    return false;
}

int main()
{
    int start=1;
    int a[]={2,2,2,2,5};
    sort(a,a+5,greater<int>());

    for(int i=0; i<5; i++)
        cout<<a[i]<<" ";

    cout<<endl<<"start: "<<start<<"compare: "<<compare(a,5,&start)<<endl;
}
