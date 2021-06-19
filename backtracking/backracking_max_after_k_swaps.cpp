
/*
    Maximum number after k swaps 
    https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Method 1. generate all permutations of the string
    if the total swaps to convert this permutation to original string = k, 
    this can be our answer

    O(n! * n^2)
*/

/*
    Method 2. Optimized Brute Force, swap the larget char after

    total n^2 call for each k
    T(n) = O((n^2)^k)
*/

string ans;
void maxNum(string &num, int k) {
    if(k == 0) {
        return;
    }
    
    int n = (int)num.length();

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            // whenever we see a pair i, j such that 
            /// i < j and num[j] > str[j], we swap
            if(num[j] > num[i]) {
                swap(num[i], num[j]);
                ans = max(ans, num);
                maxNum(num, k-1);
                swap(num[i], num[j]);
            }
        }
    }
}


/*
    Method 2. Find the maximum char and swap

    In each recursive call we can make at most n recursive call 
    and compare string with ans which takes O(n) time (inside for loop which runs for at most n)
    T(n) = n*(T(n-1) + O(n))  
    // since we go only k steps in recursion 
    T(n) = O(n!/(n-k)!)
    T(n) = O(n^k)      => a bigger upperbound.
*/

string mxStr;

void go(int i, string &str, int k) {
    int n = str.length();
    // string finished or swap operations exhausted
    if(i == n-1 || k == 0) {
        // mxStr = max(mxStr, str);
        return;
    }

    // find the max char after i
    char mxCh = str[i];
    for(int j=i+1; j<n; j++) {
        mxCh = max(mxCh, str[j]);
    }
    // swap and do recursive call with each index of max char 
    for(int j=i+1; j<n; j++) {
        if(str[j] == mxCh) {
            swap(str[i], str[j]);
            // comparison for maxStr can be done here or in base case
            mxStr = max(mxStr, str);
            go(i+1, str, k-1);
            swap(str[i], str[j]);
        }
    }
    /*
    don't swap, just move forward
    for cases like "4322", there are not swaps possible, 
    we just try to reach the base condition
    */
    go(i+1, str, k);
}

string findMaximumNum(string str, int k) {
    mxStr = str;
    go(0, str, k);
    return mxStr;
}

int main() {
    cout << findMaximumNum("61892795431", 4);
}