
// finding all the unique subset sums 

#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1010;                 // max sum of the array can be N
bool dp[N][N];                      // [index][sum]
set<int> res;
vector<int> v;
int n;

void subset_sum(int pos=0,int sum=0) {
    if(pos == v.size()) {
        res.insert(sum);
        return ;
    }
    if(dp[pos][sum])
        return;   
         
    dp[pos][sum]=true;
    subset_sum(pos+1,sum);
    subset_sum(pos+1,sum + v[pos]);
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    subset_sum();
    for(auto x: res)
        cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}