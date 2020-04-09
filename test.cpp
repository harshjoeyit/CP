#include<bits/stdc++.h>
using namespace std;

#define int long long
int x, k;

int cnt(int n) {
    map<int, int> freq;
    
    for (int i = 2; i * i <= n; ++i) 
        while (n % i == 0) 
        {                // loop fo checking the repeated factors 
            ++freq[i];
            n /= i;                         
        }
    if (n != 1) 
        ++freq[n];

    int s = 0;
	for(auto p: freq)
		s += p.second;
	
	return s;
}



int solve() {
	cin >> x >> k;
	if(x == 1) {
		return 0;
	}

	if(x % 2 == 1) {
		if(k != 1)
			return 0;
	} else {
		int d = divisors(x);
		if(d < k)
			return 0;
	}

	return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    	cout << solve() << "\n";
}