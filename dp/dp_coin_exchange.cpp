#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1e3+10;
int dp[mxN][mxN];
int A[mxN], n;                     

/*
A - holds types of coins
dp[pos][S] - number of ways to make sum = S, when at index pos in the A[]

Note: Order of the coins in the array does not matter 
*/

int ways(int pos, int S) {
    if(pos == n) {
        return (S == 0);
    }

    int &ans = dp[pos][S];
    if(dp[pos][S] != -1) {
        return ans;
    }

    ans = 0;
    int times = 0;
    // This portion of code here increases the time complexity by since we are looping, number to transitions to next state are more 
    // use the current coins as many times as we can use, and going to next coin  
    while(times*A[pos] <= S) {
        ans += ways(pos+1, S-times*A[pos]);
        times++;
    }

    return ans;
}

//Faster than ways function as it causes only two transitions
int fasterWays(int pos, int S) {
	if(pos == n) {
        return S == 0;
    }
 	if(S < 0) {
        return 0;
    }
	int &ans = dp[pos][S];

 	if(ans != -1) {
        return ans; 
    }
    ans = 0;
	ans = ways(pos, S-A[pos]) + ways(pos+1, S);
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, S;
    cin >> n >> S;
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << ways(0, S) << "\n";
    memset(dp, -1, sizeof(dp));
    cout << fasterWays(0, S) << "\n";
    
}

/*
Minimum coins to amount to total

const int mxN = 1005;
const int mxS = 1005;
int total;
int n;
int coin[mxN];
int dp[mxN][mxS];

int go(int i, int sum) {
      if(sum == total) {
            return 0;
      }
      if(i >= n) {
            return INT_MAX;
      }
      if(dp[i][sum] != -1) {
            return dp[i][sum];
      }
      int ans = min(go(i+1, sum), 1 + go(i+1, sum + coin[i]));
      return dp[i][sum] = ans;
}

void solve() {
      cin >> n >> total;
      for(int i=0; i<n; i++) {
            cin >> coin[i];
      }     
      memset(dp, -1, sizeof(dp));
      cout << go(0, 0);
}

*/