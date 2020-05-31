#include<iostream>
using namespace std;

void input(int a[],int sz)
{
    for(int i=0; i<sz; i++)
    {
        int in;
        cin>>in;
        a[i]=in;
    }
}

int findmin(int a[],int sz)
{
    int mini=+9999;
    for(int i=0; i<sz; i++)
    {
        if(mini>a[i])
            mini=a[i];
    }
    return mini;
}


int main()
{
    int N,coins[1002]={},type[1002]={},t1[1002]={},t2[1002]={},t3[1002]={},s1=0,s2=0,s3=0;
    cout<<"workers: ";
    cin>>N;

    cout<<"coins: ";
    input(coins,N);

    cout<<"type: ";
    input(type,N);

    for(int i=0; i<N; i++)
    {
        if(type[i]==1)
        {
            t1[s1]=coins[i];
            ++s1;
        }
        else
        if(type[i]==2)
        {
            t2[s2]=coins[i];
            ++s2;
        }
        else
        if(type[i]==3)
        {
            t3[s3]=coins[i];
            ++s3;
        }
    }

    int min1=findmin(t1,s1);
    int min2=findmin(t2,s2);
    int min3=findmin(t3,s3);

    cout<<endl<<min1<<" "<<min2<<" "<<min3<<endl;

    if((min1+min2) >= min3)
        cout<<"result: "<<min3;
    else
        cout<<"result: "<<(min1+min2);

    return 0;
}
// successful submission
