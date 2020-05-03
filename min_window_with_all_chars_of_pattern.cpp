#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 256;

// find smallest window in str that contains all the chars of pat 
string find_window(string s, string pat) {
    int n = s.length();
    int m = pat.length();

    if(n < m) {
        return "-1";
    } 

    int hash_pat[mxN] = {0};
    int hash_str[mxN] = {0};

    for(int i=0; i<m; i++) {
        ++hash_pat[pat[i]];
    }

    int l = 0, ans_l = -1, min_len = INT_MAX;

    int count = 0;
    for(int j=0; j<n; j++) {
        
        hash_str[s[j]]++;

        // count of a specific character in hash_pat i more than in hash_str 
        if (hash_pat[s[j]] != 0 && hash_str[s[j]] <= hash_pat[s[j]]) {
            count++;
        } 

        // all chars have been found
        if(count == m) {
            //minimize window from left

            // either count of char is greater than required or the char is not present in pat
            while ( hash_str[s[l]] > hash_pat[s[l]] || hash_pat[s[l]] == 0) {
                
                if (hash_str[s[l]] > hash_pat[s[l]]) {
                    hash_str[s[l]]--; 
                }
                l++; 
            }
            // update window size 
            int wind = j - l + 1; 
            if (min_len > wind) { 
                min_len = wind; 
                ans_l = l; 
            } 
        }
    }

    if(ans_l == -1) {
        return "-1";
    }

    return s.substr(ans_l, min_len ;
}

void solve() {
    string s, t;
    cin >> s >> t;

    cout << find_window(s, t) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}
