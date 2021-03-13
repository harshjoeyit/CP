
/*
    Given a binary array, find
    Longest Subarray with at most k 0's
    Similar Problem 
    - https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int

void go(vector<int> &a, int k) {
    int n = a.size();
    int maxL = 0, i = 0, cnt = 0;

    for(int j=0; j<n; j++) {
        cnt += a[j] == 0;
        while(cnt > k) {
            cnt -= a[i] == 0;
            i++;
        }
        maxL = max(maxL, j - i + 1);
    }

    cout << maxL << endl;
}

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &val: a) {
        cin >> val;
    }
    go(a, k);
}