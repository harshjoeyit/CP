
/*
for a tetrahedorn find number of ways 
to travel N steps and stop on the starting vertex 


dp[steps][0] - number of ways to travel "steps" and reach other than source vertex
dp[steps][1] - number of ways to travel "steps" and reach source 


recurrance - 

from source - 3 (non-source vertex)
from a (non-source vertex) - 2 (non source vertex ) and 1 (source vertex)

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1e7+2, mod = 1e9+7;
int dp[mxN][2];
int n;


int mul(int a, int b) {
    return (a*b)%mod;
}

int add(int a, int b) {
    a = a+b;
    if(a >= mod) {
        a = a-mod;
    }
    return a;
}

/*
Recursive - gives TLE for 1e7

int count_ways(int steps, int same) {
    if(steps == 0) {
        if(same) {
            return 1;
        }
        return 0;
    }

    int &r = dp[steps][same];
    if(r != -1) {
        return r;
    }

    if(same) {
        r = mul(3, count_ways(steps-1, !same));
    } else {
        r = add(mul(2, count_ways(steps-1, same)), count_ways(steps-1, !same));
    }
    return r;
}
*/

void solve() {
    cin >> n;

    dp[0][1] = 1;
    for(int steps=1; steps<=n; steps++) {
        dp[steps][1] = mul(3, dp[steps-1][0]);
        dp[steps][0] = add(mul(2, dp[steps-1][0]), dp[steps-1][1]);
    }

    cout << dp[n][1] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}