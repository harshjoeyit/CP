

/*
There is a set A consisting of N positive integers. 
Taro and Jiro will play the following game against each other.

Initially, we have a pile consisting of K stones. 
The two players perform the following operation alternately, starting from Taro:

Choose an element x in A , and remove exactly x stones from the pile.
A player loses when he becomes unable to play. 
Assuming that both players play optimally, determine the winner.
*/



#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e5+10;
int n, k, a[mxN];
int dp[mxN];

int play(int rem) {         
    if(rem < 0)
        return 1;

    if(dp[rem] != -1)
        return dp[rem];
    
    int ans = 0;
    for(int i=1; i<=n; i++)
        ans = ans | play(rem-a[i]) ^ 1;         // IMP

    return dp[rem] = ans;
}

void solve() {
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));

    if(play(k))   
        cout << "First\n";
    else 
        cout << "Second\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(15);
    solve();
}