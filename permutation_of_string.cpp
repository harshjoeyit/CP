
/*
permutations of a given string

Realted problems - 
Find the smallest number which has the same set of digits as n and larger than n

https://practice.geeksforgeeks.org/problems/next-greater-number-set-digits/0

son - print next permutation if exist else -1
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

