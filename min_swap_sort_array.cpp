
/*
https://practice.geeksforgeeks.org/problems/minimum-swaps/1

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


// Case 1: No restriction of adjacent swaps 
// when  0 <= a[i] <= n-1, O(n)
int minSwaps1(vector<int> &a) {
      int n = (int)a.size();
      int swaps = 0;
      for(int i=0; i<n; i++) {
            while(a[i] != i) {
                  swap(a[i], a[a[i]]);
                  swaps += 1;
            }
            
            // if 1 <= a[i] <= n

            // while(a[i] != i+1) {
            //       swap(a[i], a[a[i]-1]);
            //       swaps += 1;
            // }
      }
      return swaps;
      // array is sorted finally 
}

// ADJACENT SWAPS, for general array, not restricted to 0 <= a[i] <= n-1
// Using inversion counts O(N.log(N))
int minAdjacentSwap(vector<int> &a) {
    // swaps = no of inversions in thw array 
    // The fact can be established using below observations:
    // 1) A sorted array has no inversions.
    // 2) An adjacent swap can reduce one inversion. Doing x adjacent swaps can reduce x inversions in an array.
}


// NON-ADJACENT SWAPS
// for general array, not restricted to 0 <= a[i] <= n-1
int minSwaps(int arr[], int n) { 
    
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    }   
    
    sort(arrPos, arrPos + n); 
    // after sorting, elements are placed on their correct index
    // and wrong index (index in arr[]) is arrPos[i].second
    // so we make a cycle from correct index to wrong index and carray on untill 
    // we revisit any index

    // we need a visited array since we are not swapping 
    // and correctly placing the values that we have come arross
    vector<bool> vis(n, false); 
    int ans = 0; 

    for (int i = 0; i < n; i++) { 
        // element already swapped and corrected (as arrPos[i].second is the correct position)
        // or already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // count the nodes in this cycle 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) { 
            vis[j] = 1; 
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        }  
        if (cycle_size > 0) { 
            ans += (cycle_size - 1); 
        } 
    } 
    return ans; 
} 


// for a binary array 
int minAdjacentSwapBinary(vector<int> &a) {
    int n = (int)a.size();
    int zeroAfter = 0;
    int swaps = 0;

    for(int i = n-1; i >= 0; i--) {
        if(a[i] == 0) {
            zeroAfter += 1;
        } else {
            swaps += zeroAfter;
        }
    }

    return swaps;
    // bonus 
    // if we want to sort the array too
    // 1. count 0s, 1s 
    // 2. two pointer 
}

int main() {
      int n;
      cin >> n;
      vector<int> a(n);
      for(auto &val: a) {
            cin >> val;
      }

}