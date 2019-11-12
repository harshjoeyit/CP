#include<iostream>
using namespace std;

int main()
{
    int T,output[102],s=0;

    cout<<"test cases: ";
    cin>>T;
    const int t=T;

    while(T--)
    {
        int N,n,odd=0;
        cout<<"how many no.s ? ";
        cin>>N;
        cout<<"enter no using spaces: "<<endl;


        for(int i=0; i<N; i++)
        {
            cin>>n;
            if(n%2 != 0)
                ++odd;
        }

        if(odd%2 == 0)
            output[s++]=1;
        else
            output[s++]=2;
    }

    cout<<"output: "<<endl;
    for(int i=0; i<t; i++)
        cout<<output[i]<<endl;

    return 0;
}
