
/*

Next permutation -
https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/

Realted problems - 
Find the smallest number which has the same set of digits as n and larger than n
https://practice.geeksforgeeks.org/problems/next-greater-number-set-digits/0

sol - print next permutation if exist else -1
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

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n-1;
    while(i >= 1 && nums[i-1] >= nums[i])    i--;
    if(i == 0) {
        sort(nums.begin(), nums.end());
        return;
    } 
    // find the smallest number greater than nums[i-1], to its right
    int j=i;
    while(j < n && nums[j] > nums[i-1])     j++;
    swap(nums[i-1], nums[j-1]);
    sort(nums.begin()+i, nums.end());
}


int main() { 
    string s;
    cin >> s;
    
    // permute(s, 0);
    cout << ".................\n";
    
    set<string> st;
    permute(s, 0, st);
    for(auto x: st)
        cout << x << " ";
    cout << "\n.................\n";
} 

