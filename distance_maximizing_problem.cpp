#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
      int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x: a) {
		cin >> x;
	}

	vector<int> lmin(n);
	lmin[0] = 0;
	for(int i = 1; i < n; i++) {
	    lmin[i] = a[i] < a[lmin[i-1]] ? i : lmin[i-1];
	}

	vector<int> rmax(n);
	rmax[n-1] = n-1;
	for(int i = n-2; i >= 0; i--) {
	    rmax[i] = a[i] > a[rmax[i+1]] ? i : rmax[i+1];
	}

	int diff = 0;
	for(int i=0, j=0; i < n && j < n;) {
	    	if(a[lmin[i]] < a[rmax[j]]) {				// change condition accordingly here (a[i] < a[j])  could be (a[i] <= a[j]){
	        	diff = max(diff, j-i);
	      	// look for j, a[j] > a[i]  
			j++;
	    	} else {
	      	i++;
	    	}
	}
	cout << diff << endl;
}

signed main()  {
	solve();
}