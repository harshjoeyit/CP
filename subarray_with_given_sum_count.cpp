#include<bits/stdc++.h>
using namespace std;

#define int long long 


int count_subarrays(vector<int> &a, int sum) {
    unordered_map<int, int> ump;
    int curr = 0, cnt = 0, n = a.size();

    for(int i=0; i<n; i++) {
        curr += a[i];

        if(curr == sum) 
            ++cnt;

        if(ump.count(curr - sum) > 0) {
            cnt += ump[curr - sum];
        }

        ump[curr]++;
    }
    return cnt;
}



void solve() {
    int n, sum;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a)
        cin >> x;
    
    cin >> sum;
    int sub = count_subarrays(a, sum);
    cout << sub << endl;
}

signed main() {
    solve();
}