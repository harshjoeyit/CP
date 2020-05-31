
/*
Student Arrangement

https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/student-arrangement-6/

binary search
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void print(set<int> st) {
	for(auto x: st) 
		cout << x << " ";
	cout << endl;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k; 
	
	int a[n+1], cnt[n+1];				// cnt for counting students on ith bench
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	memset(cnt, 0, sizeof(cnt));

	set<int> st;
	for(int i=1; i<=m; i++) {
		st.insert(i);
	}

	int ans = 0;
	int i;
	for(i=1; (i<=n); i++) {
		
		if(st.empty()) {
			break;
		}

		auto it = st.lower_bound(a[i]);			// find next bench
		if(it == st.end()) {
			it = st.begin();
		}
		
		if(*it != a[i]) {						// not fav bench
			++ans;
		}
		cnt[*it]++;								// make student sit here 
		if(cnt[*it] == k) {						// k sitting bech full
			st.erase(it);
		}
	}

	if(i <= n) {								// remaining students 
		ans += (n-i+1);
	}

	cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}