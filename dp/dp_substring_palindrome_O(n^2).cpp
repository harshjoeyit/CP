#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
bool dp[mxN][mxN];
string s;

void pre_process() {
    int n = s.length();
    
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            dp[i][j] = false;
      
    for(int j=1; j<=n; j++){                    // j = for length of the string
        for(int i=0; i<=n-1; i++) {             // i - iterate to every index where length j string is possible
            if(j <= 2) {                        // for string of length = 1, 2
                if(s[i] == s[i+j-1])            // [i - i+length-1] indices of start and end of string 
                    dp[i][i+j-1] = true;

            } else if(s[i] == s[i+j-1]){
                dp[i][i+j-1] = dp[i+1][i+j-2];  // for [l, r] to be palindrome [l+1, r-1] must be a palindrome    
            }
        }
    }   
}

void disp() {
    for(int i=0; i<s.length(); i++) {
        for(int j=0; j<s.length(); j++) { 
           cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    int q;
    cin >> s;
    cin >> q;
    pre_process();
    disp();

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << ((dp[l][r])?"yes" : "no") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}

// other algos for palindromic queries - Rabin Karp 