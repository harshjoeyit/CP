
/*
You are given N ≤ 20 numbers, each up to 109. 
Is there a subset with sum equal to given goal S?
*/

#include<bits/stdc++.h>
using namespace std;

void find_subset(int a[], int n, int s) {

    // mask denotes subset of the elements
    // array elements' index is the bit of the mask
    // if bit is set, it means a[i] is included in subset else not 
    for(int mask=0; mask<(1<<n); mask++) {
        int subset_sum = 0;
        for(int i=0; i<n; i++) {
            if(mask & (1 << i))
                subset_sum += a[i];
        }
        if(subset_sum == s) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int a[] = {1, 3, 12, 10, 4, 5};
    int s = 21, n = sizeof(a)/sizeof(a[0]);
    find_subset(a, n, s);
}