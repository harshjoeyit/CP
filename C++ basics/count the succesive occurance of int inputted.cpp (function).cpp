#include<bits/stdc++.h>
using namespace std;

void COUNT (int c1, int cnt)
{
    int c2;
    cin>>c2;
    if(c2==0)
    {
        cout<<c2<<" occurs for 1 times."<<endl;
        cout<<c1<<" occurs for "<<cnt<<" times."<<endl;
        return ;
    }
    else if(c2 == c1)
    {
        ++cnt;
        COUNT(c1,cnt);
    }
    else
    {
        COUNT(c2,1);
        cout<<c1<<"occurs for "<<cnt<<" times."<<endl;
    }
}

main()
{
    cout<<"enter 0 to stop the counting :"<<endl;
    int c1;
    cin>>c1;
    COUNT(c1,1);
}

