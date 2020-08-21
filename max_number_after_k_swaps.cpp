
/*
maximum number after k swaps 
*/

#include<bits/stdc++.h>
using namespace std;

// Optimized Brute Force O((n^2)^k)
// total n^2 call for each k

string ans;
void maxNum(string &num, int k) {
    if(k == 0) {
        return;
    }
    
    int n = (int)num.length();

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(num[j] > num[i]) {
                swap(num[i], num[j]);
                ans = max(ans, num);
                maxNum(num, k-1);
                swap(num[i], num[j]);
            }
        }
    }
}


// Time Complexity: O(n^k).
void maxNumNice(string num, string &ans, int k, int i) {
    if (k == 0) {
        return;
    }

    int n = (int)num.length();
    
    // find the maximum digit after i 
    char mx = num[i];
    for(int j = i+1; j < n; j++) {
        mx = max(mx, num[j]);
    }
    if(mx != num[i]) {
        k -= 1;
    }

    for(int j=i; j<n; j++) {
        if(num[j] == mx) {
            swap(num[i], num[j]);
            ans = max(ans, num);
            maxNumNice(num, ans, k, i+1);
            swap(num[i], num[j]);
        }
    }
}


int main() {
    string num;
    int k;
    cin >> num >> k;
    ans = num;
    maxNum(num, k);
    cout << ans << endl;

    ans = num;
    maxNumNice(num, ans, k, 0);
    cout << ans << endl;
}