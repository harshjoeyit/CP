/*
    https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
    Min swaps to bring elements <= k together 
*/

#include<bits/stdc++.h>
using namespace std;

int minSwap(int a[], int n, int k) {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        cnt += (a[i] <= k);
    }
    if(cnt == 0)    return 0;
    
    // cnt is the window size
    int l = 0, h = cnt-1, gt = 0;
    // count greater than k elements 
    for(int i=l; i<=h; i++) {
        gt += (a[i] > k);
    }
    int ans = gt;
    // Slide Window 
    while(h < n-1) {
        gt -= (a[l++] > k);
        gt += (a[++h] > k);
        ans = min(ans, gt);
    }
    return ans;
}


int main() {
}