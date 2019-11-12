#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T, ans[101]={},index=0;
    cin>>T;

    while(T--)
    {
        int N, A[101],K;
        cin>>N>>K;
        for(int i=0; i<N; i++)
            cin>>A[i];

        sort(A,A+N);
        ans[index++]=A[ (N+K)/2];
    }
    for(int i=0; i<index; i++)
        cout<<ans[i]<<endl;;

    return 0;
}
