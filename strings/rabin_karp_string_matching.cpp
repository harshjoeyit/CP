#include<bits/stdc++.h>
using namespace std;
#define int long long int 

/* 
string hashes are sure to collide since there are exponential strings and 2^64 hashes only 
>>> p = 31 is a good choice if the chars are lowercase letters only 
>>> if string has bith lowercase and uppercase letters then p = 53 is a good choice 
>>> p is roughly equal to the number of distinct chars in string
*/

const int p = 31;
const int mod = 1e9+9;

int modExp(int x, int y) {
	int ans = 1;
	while(y > 0) {
		if(y & 1) {
			ans = ans * x;
		}
		y = y >> 1;
		x = (x * x) % mod;
	}
	return ans;
}

int compute_hash(string s, int n) {
	int hash_value = 0;
	int p_pow = 1;
	for(int i = 0; i < n; i++) {
		hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % mod;
      	p_pow = (p_pow * p) % mod;
	}
	return hash_value;
}


bool match(string s, string pat, int st, int en) {
	// comparing a substring of s to pat
    	for(int i = st; i <= en; i++) {
		if(s[i] != pat[i-st]) {
			return false;
		}
	}
    	return true;
}

// pattern matching using rabin karp algo
void pattern_matching(string s, string pat) {
	int n = pat.length();
	int pat_hash = compute_hash(pat, n);
	int p_pow = modExp(p, n-1);
	vector<int> Hash(s.length());

	Hash[0] = compute_hash(s, n);
	for(int i=1; i<=s.length() - n; i++) {
		Hash[i] = Hash[i-1] - (s[i-1] - 'a' + 1);
       	Hash[i] = Hash[i]/p;
        	Hash[i] = (Hash[i] + ((s[i+n-1] - 'a' + 1) * p_pow) % mod) % mod;
	}

	for(int i=0; i<=s.length()-n; i++) {
		if(pat_hash == Hash[i] && match(s, pat, i, i+n-1)) {
			cout << "match at " << i << "\n";
		}
	}
}

// grouping together the strings that are identical 
// O(nm+nlogn)
vector<vector<int> > group_identical_strings(vector<string> const &arr) {
    int n = arr.size();
    vector<pair<int, int> > hashes(n);
    
    for(int i=0; i<n; i++) {
          hashes[i] = make_pair(compute_hash(arr[i], arr[i].length()), i);
    }
    
    sort(hashes.begin(), hashes.end());
    vector<vector<int> > groups;
    
    for(int i=0; i<n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first) {
            // push_back an empty vector 
            groups.emplace_back();
        }
        // push_back in the last vector pushed in the groups
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

// fast hash calculation for substrings of a string
/*
Suppose we have two hashes of two substrings, one multiplied 
by pi and the other by pj. If i<j then we multiply the first hash 
by pj−i, otherwise, we multiply the second hash by pi−j. By doing 
this, we get both the hashes multiplied by the same power of p 
(which is the maximum of i and j) and now these hashes can be 
compared easily with no need for any division.
*/


// count unique substrings 
int count_unique_substrings(string const &s) {
    int n = s.size();

    vector<int> p_pow(n);
    p_pow[0] = 1;
    for(int i=1; i<n; i++) {
        p_pow[i] = (p_pow[i-1] * p) % mod;
    }

    vector<int> hashes(n+1, 0);
    for(int i=0; i<n; i++) {
        hashes[i+1] = (hashes[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    
    int cnt = 0;
    // l - substring size
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        // all substring of size l
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (hashes[i + l] + mod - hashes[i]) % mod;
            cur_h = (cur_h * p_pow[n-i-1]) % mod;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

/*
Improving probability of collision of hash

There is a really easy trick to get better probabilities.
 We can just compute two different hashes for each string 
 (by using two different p, and/or different m, and compare 
 these pairs instead. If m is about 109 for each of the two 
 hash functions than this is more or less equivalent as having 
 one hash function with m≈1018. When comparing 106 strings with 
 each other, the probability that at least one collision happens 
 is now reduced to ≈10−6.
*/

signed main() {
	// string s, pat;
	// cin >> s >> pat;
	// pattern_matching(s, pat);
    
    	// int n;
      // cin >> n;
      // vector<string> arr;
      // for(int i=0; i<n; i++) {
      //     string str;
      //     cin >> str;
      //     arr.push_back(str);
      // }
      // auto ans = group_identical_strings(arr);
      // for(auto v: ans) {
      //     for(auto i: v) {
      //           cout << i << " ";
      //     }
      //     cout << endl;
      // }

	// string s;
	// cin >> s;
	// cout << count_unique_substrings(s) << endl;
}