#include<bits/stdc++.h>
using namespace std;

int main()
{

    int a[] = {1,2,3,3,8,5,2,2,0,4,4,6,6,3,3,8,7};
    int size = sizeof(a)/sizeof(int);
    int b[size] ,index = 0, count,sum = 0 ;

    sort(a,a+size);

    for(int i=0; i<size;  i++)
        cout<<a[i]<<" ";
    cout<<endl;

    for(int i=0; i<size-1; i++)
    {
        count=1;
        while(a[i] == a[i+1])
        {
            ++i;  // skipping the same elements
            ++count; // counting how many times the element occurred
        }
        if(count == 1)
            sum += b[index++] = a[i];
    }
    
    for(int i=0; i<index;  i++)
        cout<<b[i]<<" ";
        
    cout<<endl<<"sum : "<<sum<<endl;
 
}