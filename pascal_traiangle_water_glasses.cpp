#include<bits/stdc++.h>
using namespace std;
int t,n,i,j;
float dp[1001][1001],k;

int main() {
    cin>>t;
    while(t--) {  
        cin>>k>>i>>j;
        memset(dp,0,sizeof(dp));
        dp[1][1]=k;

        for(int x=1;x<=i;x++)
        {
            for(int y=1;y<=x;y++)
            {
                if(dp[x][y]>1)
                {
                    float diff=dp[x][y]-1;
                    dp[x][y]=1;
                    dp[x+1][y]+=diff/2;
                    dp[x+1][y+1]+=diff/2;
                }
            }
        }
        cout<<fixed<<setprecision(6)<<dp[i][j]<<endl;
    }


}