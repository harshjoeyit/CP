/*
    Maximum sum of absolute difference of any permutation
    geeksforgeeks.org/maximum-sum-absolute-difference-array/

    For ex- 
    {1, 2, 4, 8} gives max ans on {1, 8, 2, 4}
    {1, 2, 4, 6, 8} gives max ans pn {1, 8, 2, 6, 4}

    NOTE: Last elements adjacent is first element 

    Break array into half, reverse the 2nd part and interleave into first part.
    {1, 2, 4, 8} => {1, 2} {4, 8} => {1, 2} {8, 4} => {1, 8, 2, 4}
    {1, 2, 4,, 6, 8} => {1, 2, 4} {6, 8} => {1, 2, 4} {8, 6} => {1, 8, 2, 6, 4}

    We could make a temp array, split and merge and then find sum of adjacent diff 
    but we can do it without it too.
*/

#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size(), ans = 0;;
    
    for(int i=n-1; i>=n/2; i--) {
        int j = n-i-1;
        int k = (j+1)%((n+1)/2);
        ans += (a[i] - a[j]) + (a[i] - a[k]);
    }
    return ans;
}

int main() {
    vector<int> a = {1};
    cout << sum(a) << endl;
}