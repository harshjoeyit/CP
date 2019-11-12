#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int low, int high, int search)
{
    int mid;
    while(low <= high)
    {
        mid = (low + high)/2;

        if(a[mid] == search)
            return 1;
        else
        if( a[mid] > search )
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main()
{
    cout<<"Test cases: ";
    int T;
    cin>>T;
    while(T--)
    {
        cout<<"no. of elements: ";
        int N,search;
        cin>>N;
        int a[N];

        cout<<"array: \n";
        for(int i=0; i<N; i++)
            cin>>a[i];

        cout<<"search: ";
        cin>>search;
        
        sort(a,a+N);
        if( binary_search(a,0,N-1,search) )
            cout<<"found"<<endl;
        else
            cout<<"not found"<<endl;
    }
}