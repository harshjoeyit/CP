#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    vector<string> ans;

    while(T--)
    {
        int D,C,L,maxx,minn;
        cin>>C>>D>>L;
        maxx = (C+D)*4;

        if(C == 2*D || C < 2*D)
            minn = 2*D;
        else
        if(C > 2*D)
            minn = (C-D)*4;   // (C-2*D)*4 + D*4

        if( L >= minn && L <= maxx && L%4==0)
            ans.push_back("yes");
        else
            ans.push_back("no");
    }

    for(auto it= ans.begin(); it!= ans.end(); it++)
        cout<<*it<<endl;

    return 0;
}
