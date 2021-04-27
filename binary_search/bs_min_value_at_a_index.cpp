/*
https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll getMinSum(ll m, ll mid) {
    ll ones = m - (mid-1);
    if(ones > 0) {
        return ones + mid*(mid-1)/2;
    }
    ll k = mid-1-m;
    return mid*(mid-1)/2 - k*(k+1)/2;
}

bool go(ll n, int index, ll mid, ll maxSum) {
    ll leftEle = index;
    ll rightEle = n - index - 1;
    ll minLSum = getMinSum(leftEle, mid);
    ll minRSum = getMinSum(rightEle, mid);
    return (minLSum + minRSum + mid <= maxSum);
}

int maxValue(int n, int index, int maxSum) {
    int ans = 1, low = 1, high = 1e9;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(go(n, index, mid, maxSum)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {

}