/*
Problem: 
count subarrays such that a[i]*a[i+1]......a[j] = p^2 -q^2;

A number can be written as the difference of two perfect squares  (p-q)*(p+q)
if and only if it is odd, or a multiple of 4.

We just need to find the number of contiguous subsequences having 
the product as multiple of 2 but not multiple of 4, and subtract 
from the total number of contiguous subsequences.

If we replace odd values with zeroes, multiples of 4 with 2 and 
rest with 1, the number of contiguous subsequences to be subtracted 
is the number of contiguous subsequences with sum 1, which can be 
easily computed using pointers.

*/


#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 1e5+10;
int n, a[mxN];

// counting subarrays with a given sum 
int count_subarrays(int sum) {
    unordered_map<int, int> ump;
    int curr = 0, cnt = 0;

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
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		a[i] = abs(a[i]);
		if(a[i] % 4 == 0)
			a[i] = 2;
		else if(a[i] % 2 == 0)
			a[i] = 1;
		else 
			a[i] = 0;
		// cout << a[i] << " ";
	}
	// cout << endl;

	cout << ((n*(n+1))/2 - count_subarrays(1)) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}