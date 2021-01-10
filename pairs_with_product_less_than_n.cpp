
/*
	Ordered pairs with product less than N
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 10;
	int cnt = 0;
	for(int i=1; i<=sqrt(n-1); i++) {
		for(int j=i; j*i<n; j++) {
			// cout << i << " " << j << endl;
			cnt += 1;
		}
	}

	cnt *= 2;
	// remove duplicate fo types (1,1), (2,2)...
	cnt -= int(sqrt(n-1));
	cout << cnt << endl;
}