#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> results;
    int T,X,Y;
   // cout<<"test case: ";
    cin>>T;

    while(T--)
    {
   //     cout<<"enter X,Y\n";
        cin>>X>>Y;

        if(X<=Y)
            results.push_back(0);
        else
            results.push_back(X-Y);

    }

    for(auto it= results.begin(); it!=results.end(); it++)
        /*cout<<"matches to be won: "*/cout<<*it<<endl;

    return 0;
}
