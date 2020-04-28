#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int, greater<int>()> mp;
    int sz;
    for(int i=1; i<=n; i++) {
        cin >> sz;
        ++mp[sz];
    }

    int mxcnt[n+1];
    for(int i=1; i<=n; i++) 
        cin >> mxcnt[i];
    
    vector<int> ans[n+1];
    int t = 0;
    int total_cnt = 0;

    while(total_cnt < n) {
        int ins_cnt = 0;

        for(auto it = mp.begin(); it!= mp.end(); it++) {

            int val = it->first;
            int freq = it->second;
            int eff_cnt = mxcnt[val] - ins_cnt;
            bool ins = 0;

            while(eff_cnt > 0 && freq > 0) {
                ans[t].push_back(val);
                freq--;     
                mp[val]--;
                eff_cnt--;
                ++total_cnt;
                ins = 1;
            }   
            ins_cnt += ins;
        }
        ++t;
    }

    for(int i=0; i<t; i++) {
        cout << ans[i].size() << " ";
        for(auto x: ans[i])
            cout << x << " ";
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}