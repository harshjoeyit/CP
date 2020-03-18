#include<bits/stdc++.h>
using namespace std;

bool check(int store[][101] , int index, int f[], int F)
{
    for(int i=0; i<index; i++)
    {
        int c=0;
        for(int j=0; j<F; j++)
        {
            if(store[i][j]==f[j])
                ++c;
        }
        if(c==F)
            return true;
    }
    return false;
}

int main()
{
    int T,N,F,n[101],f[101],ind=0;
    cin>>T;
    string ans[101];

    while(T--)
    {
        int store[101][101], index=0;
        cin>>N;
        for(int i=0; i<N; i++)
            cin>>n[i];
        cin>>F;
        for(int i=0; i<F; i++)
            cin>>f[i];

        for(int i=0; i<N; i++)
        {
            if(f[0]==n[i])
            {
                for(int j=0; j<F; j++)
                    store[index][j] = n[i+j];
                ++index;
            }
        }

        if(check(store,index,f,F))
            ans[ind++] = "Yes";
        else
            ans[ind++] = "No";

    }

    for(int i=0; i<ind; i++)
        cout<<ans[i]<<endl;

    return 0;
}
