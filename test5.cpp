#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string s, rev;
    cin >> s;
    rev = s;
    reverse(rev.begin(), rev.end());
    auto pi = prefix_function(s);
    auto revpi = prefix_function(rev);
    int n = s.length();
    int cnt = 0;

    for(int i=0; i<n/2-1; i++) {
        int halflen = i+1;
        int len = 2*halflen;
        int revlen = n - len;
        int revhalflen = revlen/2;
        int curr = 0;

        if(pi[len-1] >= halflen) {
            curr += 1;
        }  
        if(revpi[revlen-1] >= revhalflen) {
            curr += 1;
        }
        if(curr == 2) {
            cnt += 1;
        }
    }
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}