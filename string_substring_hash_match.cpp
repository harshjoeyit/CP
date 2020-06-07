
/*
https://www.codechef.com/COOK118B/problems/CHEFSHIP
substring pattern matching
given a string with even length 
count ways to break strings int substrings 

s1, s2, t1, t2,  where (s1+s2+t1+t2) = s
such that s1 = s2 and t1 = t2
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1e5+10;
const int mod = 1e9+9;
const int p = 31;
int Hash[mxN];
int p_pow[mxN];

// precomputations for for reducing time complexity
void compute_pow() {
	p_pow[0] = 1;
	for(int i=1; i<mxN; i++) {
		p_pow[i] = (p_pow[i-1] * p) % mod;
	}
}
void compute_hash(string s) {
	for(int i=0; i<s.length(); i++) {
		Hash[i+1] = (Hash[i] + (s[i]-'a'+1) * p_pow[i]) % mod;
	}
}
int get_hash(int i, int j) {
	return (Hash[j+1] - Hash[i] + mod) % mod;
}

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	// hash for complete string
	compute_hash(s);
	int ans = 0;

	// i is partition index for s1+s2 and t1+t2
	for(int i=1; i<n-1; i += 2) {
		int len = i+1;
		// write hash, then try it out
		// read substring hash on cp algo page of string hashing
		// multiplying hash with power of prime for comparison
		int hash_s1 = (get_hash(0, len/2-1) * p_pow[len/2]) % mod;
		int hash_s2 = get_hash(len/2, len-1);

		int len2 = n-len;
		int hash_t1 = (get_hash(len, len+len2/2-1) * p_pow[len2/2]) % mod;
		int hash_t2 = get_hash(len+len2/2, n-1);

		// 
		if(hash_s1 == hash_s2 && hash_t1 == hash_t2) {
			ans += 1;
		}
	}
	cout << ans << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
	cin >> t;
	compute_pow();
	while(t--) {
		solve();
	}
}