#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
      int m = a.size();
      int n = b.size();
      if(m > n) {
            // O(1) operation
            swap(a, b);
            swap(m, n);
      }

      int low = 0;
      int high = m;
      // the length of each half of the partition
      int halfLen = (m+n+1)/2;
      int i, j, maxOfLeft, minOfRight;

      while(low <= high) {
            // partition index in a
            i = (low + high)/2;
            // partition index in b
            j = halfLen - i;

            if(i < m && b[j-1] > a[i]) {
                  // we are too far left in a
                  low = i + 1;
            } else if(i > 0 && a[i-1] > b[j]) {
                  // we are too far right in a
                  high = i - 1;
            } else {
                  // i is perfect partiton index
                  // if 0 < 1 < m
                  // b[j-1] < a[i] && a[i-1] < b[j]

                  if(i == 0) {
                        // corner case 1. no elemnt in a in the left half
                        maxOfLeft = b[j-1];

                  } else if(j == 0) {
                        // corner case 2. no element in b in the left half
                        maxOfLeft = a[i-1];
                  } else {
                        maxOfLeft = max(a[i-1], b[j-1]);
                  }

                  if((m + n) % 2 == 1) {
                        return maxOfLeft;
                  }

                  if(i == m) {
                        // no element in a in right half
                        minOfRight = b[j];
                  
                  } else if(j == n) {
                        // no element in b in right half
                        minOfRight = a[i];
                  } else {
                        minOfRight = min(a[i], b[j]);
                  }

                  return (maxOfLeft + minOfRight) / 2.0;
            }
      }
}