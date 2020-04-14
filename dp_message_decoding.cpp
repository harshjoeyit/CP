

/*
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input 
contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more 
consecutive 0’s then it is an invalid string.

*/


#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n;
string s;
int dp[100000];

int decode(int i) {
    if(i == n)
        return 1;
    if(s[i] == '0')
        return 0;
    if(i == n-1)
        return decode(i+1);
    
    int ans = 0;
    if(dp[i+1] == -1) {
        dp[i+1] = decode(i+1);
    }
    ans += dp[i+1];
        
    if(s[i] == '2' && s[i+1] <= '6' || s[i] == '1')  {
        if(dp[i+2] == -1)
            dp[i+2] = decode(i+2);
        ans += dp[i+2];
    }
    
    return ans;
}

void solve() {
    cin >> s;
    n = s.length();

    memset(dp, -1, sizeof(dp));
    
    bool invalid = 0;
    if(n == 0)
        cout << "1\n";
    
    if(s[0] == '0') 
        invalid = 1;
    
    for(int i=0; (i<n-1 ) && (!invalid); i++) {
        if(s[i] == '0' && s[i+1] == '0')
            invalid = 1;
            
        if(s[i] > '2' && s[i+1] == '0')
            invalid = 1;
    }
        
    if(!invalid)
        cout << decode(0) << "\n";
    else 
        cout << "0\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}