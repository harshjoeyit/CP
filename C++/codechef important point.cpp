#include<bits/stdc++.h>
using namespace std;

main()
{
    short int T,i=0;
    cin>>T;
    long long int ans[11];

    while(T--)
    {
        long long int N,x,minn=INT_MAX;  // important how to consider th minimum value of a number
        set<int> a;
        cin>>N;

        for(int i=0; i<N; i++)
        {
            cin>>x;
            a.insert(x);
        }
        auto it = a.begin();
        ans[i++] = (*it)*(N-1);
    }

    for( int j=0; j<i; j++ )
        cout<<ans[j]<<endl;
}
