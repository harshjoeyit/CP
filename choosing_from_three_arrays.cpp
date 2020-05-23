
/*
given three sorted arrays 
print the final array the that contains the elements that occur in at least 2 of the 3 arrays

could be done using sets too
*/

#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int low, int high, int search) {
    int mid;
    while(low <= high) {
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
    int n1,n2,n3,  x,index=0,mx;
    cin>>n1>>n2>>n3;
    int a[n1],b[n2],c[n3];

    mx = max({n1, n2, n3});
    int d[mx];

    for(int i=0; i<n1; i++)
        cin>>a[i];
    for(int i=0; i<n2; i++)
        cin>>b[i];
    for(int i=0; i<n3; i++)
        cin>>c[i];

    for(int i=0; i<n1; i++)     // for each element in a find if it occurs in either b, c
    {
        if( binary_search(b,0,n2-1,a[i])  ||  binary_search(c,0,n3-1,a[i])  )
            d[index++] = a[i]; 
    }
    // elements in a that occur in b or c are done 

    for(int i=0; i<n2; i++)     // for elements in b that occur int c
    {
        if( binary_search(c,0,n3-1,b[i]) )      
             {
                 if( ! binary_search(d,0,index-1,b[i]) )     // if already present in the array , skip
                    d[index++] = b[i];
             }
    }

    cout<<index<<endl;
    // final list
    sort(d,d+index);
    for(int i=0; i<index; i++)
        cout<<d[i]<<endl;
}