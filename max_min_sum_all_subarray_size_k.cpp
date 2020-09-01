
/*
find the sum = (min + max)
of all subarrays of size k
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    map<int, int> mp;
    for(int i=0; i<k; i++)
        ++mp[a[i]];
    
    auto it1 = mp.begin();
    auto it2 = mp.rbegin();
    cout << (it1->first + it2->first) << " ";
    
    for(int i=k; i<n; i++) {
        mp[a[i]] += 1;
        
        if(mp[a[i-k]] > 1) {
            --mp[a[i-k]];
        } else {
            mp.erase(a[i-k]);
        }
        
        it1 = mp.begin();
        it2 = mp.rbegin();
        cout << (it1->first + it2->first) << " ";
    }
    cout << endl;
}



// in O(n) time 
void minMaxSum(vector<int> &a, int k) {
      int n = a.size();
      deque<int> mindq, maxdq;

      for (int i = 0; i < n; i++) {
            // outside the window 
            if (!mindq.empty() && mindq.front() == i-k) {
                  mindq.pop_front();
            }
            if (!maxdq.empty() && maxdq.front() == i-k) {
                  maxdq.pop_front();
            }
            while (!mindq.empty() && a[mindq.back()] > a[i]) {
                  mindq.pop_back();
            }
            while (!maxdq.empty() && a[maxdq.back()] < a[i]) {
                  maxdq.pop_back();
            }

            // cout << "pushed: " << a[i] << endl;
            mindq.push_back(i);
            maxdq.push_back(i);

            if(i >= k-1) {
                  cout << a[mindq.front()] + a[maxdq.front()] << " ";
            }
      }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}