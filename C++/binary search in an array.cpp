#include<bits/stdc++.h>
using namespace std;

bool binarysearch(int a[],int low, int high,int ss)
{
    int mid;
    while(low <= high)
    {
        mid = (low + high)/2;

        if( ss == a[mid])
            return true;
        else
        if(ss > a[mid])
            low = mid +1;
        else
        if(ss < a[mid])
            high = mid -1;
    }
    return false;
}

int main()
{
    int a[]={10,20,30,40,50,60,70,80,90};
    int s= sizeof(a)/sizeof(int);
    cout<<"search: ";
    sort(a,a+s);

    if(binarysearch(a,0,s-1,40))
        cout<<"found ";
    else
        cout<<"not found";

    return 0;
}
