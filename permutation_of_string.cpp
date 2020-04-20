
/*
permutations of a given string
*/

#include <bits/stdc++.h> 
using namespace std; 

void permute(string a, int l, int r, set<string> &st) { 
	if (l == r) {
		st.insert(a);
    } else {  
		for (int i = l; i <= r; i++) { 
			swap(a[l], a[i]); 
			permute(a, l+1, r, st);
			swap(a[l], a[i]); 
		} 
	} 
} 

int main() { 
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        set<string> st;
        permute(s, 0, s.length()-1, st);
        for(auto x: st)
            cout << x << " ";
        cout << endl;
    }
} 

