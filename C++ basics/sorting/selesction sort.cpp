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
    int t;
    int choose;
    cin>>choose;

if(choose==1)
{

    for(int i=0; i<sz-1; i++)
    {
        for(int j=i+1; j<sz; j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}
else
{
    for(int i=0; i<sz-1; i++)
    {
        for(int j=i+1; j<sz; j++)
        {
            if(a[i]<a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
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
