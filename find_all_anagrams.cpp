#include<bits/stdc++.h>
using namespace std;

// find anagrams of p in s 

vector<int> findAnagrams(string s, string p) {
    vector<int> sv(26, 0);
    vector<int> pv(26, 0);
    vector<int> res;
    
    for (auto c : p)
        pv[c - 'a']++;
    
    // sliding window of size = p.size()
    for (int i = 0; i < s.size(); i++) {
        sv[s[i] - 'a']++;
        if (i >= p.size()) {
                sv[s[i - p.size()] - 'a']--;
        }
        if (sv == pv) {
                // char freq match and window size is already same 
                res.push_back(i - p.size() + 1);
        }
    }
    
    return res;
}


int main() {
	string s = "cbaebabacd";
	string p = "abc";
	
	vector<int> ans = findAnagrams(s, p);
	for(auto i: ans) {
		cout << i << " ";
	}cout << endl;
}