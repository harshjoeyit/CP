
// even length substring of digits with left half sum = right half sum
// best solution O(n^2), O(1) space.


#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    int l = 0;
    for(int i=0; i<n; i++) {
        int s1 = 0, s2 = 0;
        for(int j=i, k=i+1; j>=0 && k<n; --j, ++k) {
            s1 += (int)(s[j]-'0');
            s2 += (int)(s[k]-'0');
            if(s1 == s2) {
                l = max(l, k-j+1);
            }
        }
    }
    cout << l << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}