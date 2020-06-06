//count number of elements to removed to make collection 1 totally different from collection 2

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans;
    int T;
    cin>>T;

    while(T--)
    {
        int N,M,x,y,countt=0;
        cin>>N>>M;

        set<int> m;
        vector<int> n;
        while(N--)
        {
             cin>>y;
             n.push_back(y);
        }
        while(M--)
        {
            cin>>x;
            m.insert(x);
        }

        for(auto it= n.begin(); it!= n.end(); it++)
        {
            if( m.find(*it) != m.end() )
                ++countt;
        }
        ans.push_back(countt);
    }

    for(auto it= ans.begin(); it!= ans.end(); it++)
        cout<<*it<<endl;

    return 0;
}
