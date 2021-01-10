
/*

Next permutation -
https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/

Realted problems - 
Find the smallest number which has the same set of digits as n and larger than n
https://practice.geeksforgeeks.org/problems/next-greater-number-set-digits/0

son - print next permutation if exist else -1
*/

#include <bits/stdc++.h>        
using namespace std; 

// unique permutations 
void permute(string a, int i, set<string> &st) { 
	if (i == a.length()) {
		st.insert(a);
    } else {  
		for (int j = i; j <a.length(); j++) { 
			swap(a[i], a[j]); 
			permute(a, i+1, st);
			swap(a[i], a[j]); 
		} 
	} 
} 

// all permutations (may be repeated)
void permute(string a, int i) {
    if(i == a.length()) {
        cout << a << " ";
    }
    for(int j=i; j<a.length(); j++) {
        swap(a[i], a[j]);
        permute(a, i+1);
        swap(a[i], a[j]);
    }
}

void lexicographicalNext(string s) {
    bool ret = next_permutation(s.begin(), s.end());
    if(ret == false) {
        cout << "No lexicographical next permutation possible\n";
        // eg. cba, aaa
    } else {
        cout << s << "\n";
    }
} 

void lexicographical_next(string s) {
    int n = s.length();
    int i = n-2;
    // 1. from right to left find the pos where s[i] < s[i+1]
    while(i >= 0 && s[i] >= s[i+1]) {
        --i;
    }
    if(i < 0) {
        cout << "No lexicographical next permutation possible\n";
        return;
    }
    // pos found 
    // from pos + 1 to n-1, find the smallest among the chars that are greater than s[pos]
    char c = s[i+1];
    int k = i+1;
    for(int j=i+1; j<n; j++) {
        if(s[j] > s[i] && s[j] < c) {
            k = j;
        }
    }
    // Note: since the string is sorted from pos+1, n-1, we can use binary search to find k
    // swap char at i, k
    swap(s[i], s[k]);
    // reverse the string between i [...] k 
    reverse(s.begin()+i+1, s.begin()+k);

    cout << s << endl;
}

int main() { 
    string s;
    cin >> s;
    
    // permute(s, 0);
    cout << ".................\n";
    
    set<string> st;
    // permute(s, 0, st);
    for(auto x: st)
        cout << x << " ";
    cout << "\n.................\n";
    
    lexicographicalNext(s);

    lexicographical_next(s);
} 

