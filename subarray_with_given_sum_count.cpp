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


int count_subarrays_2(vector<int> &nums, int k) {
    int n = nums.size(), sum=0, res=0;
    unordered_map<int, int> m;
    m[0]=1;
    
    for(int i=0; i<n; i++){
        sum += nums[i];
        
        if(m.find(sum-k)!=m.end())
            res+= m[sum-k];
        
        m[sum]++;
    }
    return res;
 
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