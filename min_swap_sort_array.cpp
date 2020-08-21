
/*
Given an array of first N numbers sort the elements using minimum swaps 

example - 

7 6 1 5 4 3 2
1 2 3 4 5 6 7

all we try to do is find the correct value for this index 

so we see a cycle 
1 -> 7 -> 2 -> 6 -> 3 -> 1 

after this 1, 2, 3, 6, 7 are at correctly placed 

we see another cycle 
4 -> 5 -> 4

after this 4, 5 are at correct position 

total swaps = (cycle1 - 1) + (cycle2 - 1) + ..... (cycleN - 1)

*/


#include<bits/stdc++.h>   
using namespace std; 

int minSwaps(int a[], int n) {
    int cnt = 0;
    int i=1; 
    while(i <= n) {
        if(a[i] != i) {
            while(a[i] != i) {
                // continue swapping untill index is same as value 
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