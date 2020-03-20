#include <bits/stdc++.h>
using namespace std;

#define int long long int 
const int N = 200 * 1000 + 13;
int n;
int a[N];

// eg. 
// 5
// 5 -3 3 -1 1
// ans - 8 7

void solve() {
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int pos = -1;
	int ans0 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			pos = i;
		}
		if (pos != -1) {
			ans0 += pos + 1;
		}
	}	
	int cnt1 = 0, cnt2 = 0;
	int bal = 0;
	int ansP = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cnt1 = 0, cnt2 = 0, bal = 0;
			continue;
		}
		if (bal % 2 == 0) {	
			cnt1++;
		} else {
			cnt2++;
		}
		if (a[i] < 0) {
			bal++;
		}
		if (bal % 2 == 0) {
			ansP += cnt1;
		} else {
			ansP += cnt2;
		}
	}
	cout << n * 1ll * (n + 1) / 2 - ans0 - ansP << ' ' << ansP << endl;
}

signed main () {
    solve();
}