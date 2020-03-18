#include<iostream>
using namespace std;


int main()
{
    int sz;
    cout<<"this is selection sort: "<<endl;
    cout<<"enter the size of the array max(20): ";
    cin>>sz;
    int a[20];
        int n;
    cout<<"enter the array elements max(20): "<<endl;

    for(int i=0; i<sz; i++)
    {
        cin>>n;
        a[i]=n;
    }

    cout<<"original: "<<endl;
    for(int i=0; i<sz; i++)
    {
        cout<<a[i]<<" ";
    }
     cout<<endl;
    // sorting
    cout<<"press 1 for ascending \npress 2 for descending"<<endl;
    int t; // int swap ;
    int choose;
    cin>>choose;

if(choose==1)
{
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
}
else
{
    for(int i=0; i<sz-1; i++)
    {
        for(int j=0; j<sz-i-1; j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
        for(int i=0; i<sz; i++) // breaking loop if already sorted no more passes required
        {
            if(a[i]>a[i+1])
                break;
        }
    }
}
    if(choose==1)
    cout<<"sorted in ascending : "<<endl;
    else
        cout<<"sorted descending: "<<endl;

    for(int i=0; i<sz; i++)
    {
        cout<<a[i]<<" ";
    }

return 0;
}

