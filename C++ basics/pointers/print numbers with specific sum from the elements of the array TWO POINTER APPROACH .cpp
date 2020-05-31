#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[17]={10,0,2,8,6,7,5,4,3,5,8,9,11,45,1};  // defining array +1 actual size (16)
    //sorted: {0,1,2,3,4,5,5,6,7,8,9,10,11,45}
    int t,c=0,sz = sizeof(a)/sizeof(int);

    for(int i=0; i<sz-1; i++)
    {
        // swap ==0;
        for(int j=0; j<sz-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                // swap =1;
            }
        }
        for(int i=0; i<sz; i++) // breaking loop if already sorted no more passes required
        {
            if(a[i]>a[i+1])
                break;
        }
          // if(swap==0) // this means array is sorted and no value has swapped in the last pass
            // break;
    }

    // sorted;

    int *st=&a[0];  // pointing to first element
    int *fin=&a[sz -1];  // pointing to the last element
  //  int *previous=&a[sz];  // one next last filled index
    int p;

    while(st<fin)
    {
        if(*st + *fin == 10)
        {
          //  if(*fin==*previous)
            ++c;
            cout<<*st<<"+"<<*fin<<"="<<"10"<<endl;
            --fin;
        }
        else if(*st + *fin >10)
        {
            --fin;
            --previous;
        }
        else if(*st + *fin <10)
        {
            ++st;
        }
    }

    cout<<endl<<"count: "<<c;
}
