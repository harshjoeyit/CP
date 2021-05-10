/*
      Similar Questions 
      K-th element of two sorted Arrays 
      https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
      Sol - below
*/

#include <bits/stdc++.h>
using namespace std;

/*
      Brute Force 2: O(n+m) time and, O(n+m) space
      Merge both sorted arrays and store in temp array
*/

// Sorted arrays are of different size 
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

/*
      Sorted arrays are same size
      Space Optimized Brute Force - counting when merging
      O(n) time, O(1) space
*/
int getMedian(int a[], int b[], int n) {
    int i = 0, j = 0, cnt;
    int m1 = -1, m2 = -1;
 
    /* Since there are 2n elements, median will be average of elements at 
    index n-1 and n in the array obtained after merging a and b */
    for (cnt = 0; cnt <= n; cnt++) {
        // for the case when all a[i] < b[0]
        if (i == n) {
            m1 = m2;
            m2 = b[0];
            break;
        }
        // for the case when all b[i] < a[0]
        else if (j == n) {
            m1 = m2;
            m2 = a[0];
            break;
        }
        /* equals sign because if two
           arrays have some common elements */
        if (a[i] <= b[j]) {
            /* Store the prev median */
            m1 = m2;
            m2 = a[i];
            i++;
        }
        else {
            /* Store the prev median */
            m1 = m2;
            m2 = b[j];
            j++;
        }
    }
 
    return (m1 + m2)/2;
}


int median(int a[], int n) {
    if(n%2 == 0)
        return (a[n/2] + a[n/2-1]) / 2;
    return a[n/2];
}

/*
      Median by comparing median of two arrays 
      O(logn) time, O(1) space
*/
int getMedian(int a[], int b[], int n) {

    if(n <= 0) {
        return -1;
    }
    // 2 elements only, 1 in each array
    if(n == 1) {
        return (a[0] + b[0]) / 2;
    }
    // 4 elements remaining, 2 in each array 
    if(n == 2) {
        return (max(a[0], b[0]) + min(a[1], b[1])) / 2;
    }
    
    int ma = median(a, n);
    int mb = median(b, n);

    if(ma < mb) {
        // median is in later part of a and earlier part of b
        if(n%2 == 0) {
            return getMedian(a + n/2-1, b, n-n/2+1);
        }
        return getMedian(a + n/2, b, n-n/2);
    }

    // ma >= mb
    // median is in later part of b and earliar part of a
    if(n%2 == 0) {
        return getMedian(b + n/2-1, a, n-n/2+1);
    }
    return getMedian(b + n/2, a, n-n/2);
}


