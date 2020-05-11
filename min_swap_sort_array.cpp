
/*
Given an array of first N numbers sort the elements using minimum swaps 
*/

#include<bits/stdc++.h>   
using namespace std; 

int minSwaps(int a[], int n) {
    int cnt = 0;
    int i=1; 
    while(i <= n) {
        if(a[i] != i) {
            while(a[i] != i) {
                swap(a[i], a[a[i]]);
                ++cnt;
            }
        }
        ++i;
    }
    return cnt;
}

int main()  { 
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    } 
    cout << minSwaps(a, n) << "\n";
} 