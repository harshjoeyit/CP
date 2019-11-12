#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T;
    vector<int> ans;
    cin>>T;

    while(T--)
    {
        int A,B,N;
        cin>>A>>B>>N;

        if(N%2 == 1)
            A = 2*A;

            cout<<"A:"<<A<<"B:"<<B<<endl;
            cout<<"A/B:"<<A/B<<"B/A:"<<B/A<<endl;
            ans.push_back( (A >= B) ? (A/B) : (B/A) );
    }

    for(auto it= ans.begin(); it != ans.end(); it++)
       cout<<*it<<endl;

    return 0;
}
