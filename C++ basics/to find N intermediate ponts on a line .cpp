#include<bits/stdc++.h>
using namespace std;

main()
{
    int N;
    cout<<"N: ";
    cin>>N;
    float x1,y1,x2,y2;
    pair<float,float> ans[N];
    cout<<"x1: y1: \n";
    cin>>x1>>y1;
    cout<<"x2: y2: \n";
    cin>>x2>>y2;

    for(int i=1; i<=N; i++)
    {
        ans[i-1].first = ( (N+1-i)*x1 + i*x2 )/(N+1);
        ans[i-1].second = ( (N+1-i)*y1 + i*y2 )/(N+1);
    }

    cout<<"(x,y)"<<endl;
    for(int i=0; i<N; i++)
        cout<<"("<<ans[i].first<<","<<ans[i].second<<")"<<endl;
}
