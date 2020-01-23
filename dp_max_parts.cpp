#include <iostream>
using namespace std;
int n,dp[4005],i,j,a;

int main()
{
	fill(dp+1,dp+4005,-1e9);
    cin >> n;                   // cut rope of length n in max pieces of length that are given as input only 

	for(j=1;j<=3;j++)           // 3 lengths
    { 
        cin >> a;               // length of piece
	    for(i=a;i<=n;i++)
	    dp[i]=max(dp[i-a]+1,dp[i]);      
	}
	cout<<dp[n];
    return 0;
}