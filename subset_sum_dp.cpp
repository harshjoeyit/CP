
/*
 subset sum problems 
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long 



// finding unique sum subsets 

const int N = 1010;                 
// max sum of the array can be N
bool dp[N][N];                      
// [index][sum]
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

void uniqueSum() {
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    subset_sum();
    for(auto x: res)
        cout << x << " ";
    cout << endl;
}




// finding subset with a given sum = k

#define mxN 1000
// maxsum 0f array <= 1000
int dp[mxN][mxN]; 
int a[mxN], n, sum;          

int go(int i, int s) {
    if(i == n) {
        return (s == 0);
    }
    if(s > sum) {
        return 0;
    }

    int &ans = dp[i][s];
    if(ans != -1) {
        return ans;
    }
    ans = go(i+1, s) + go(i+1, s+a[i]);
    return ans;
}

void sumEqualK() {
    cin >> n >> sum;
    for(int i=0; i<n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));
    int cnt = go(0, 0);
    cout << cnt << "\n";
}

void solve() {
    uniqueSum();
    sumEqualK();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}