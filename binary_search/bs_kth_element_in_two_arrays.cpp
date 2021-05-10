/*
      K-th element of two sorted Arrays
*/

#include <iostream>
using namespace std;

// Method 1. O(n+m) time, O(n+m) space Using temp array to store all elements 

// Method 2. Using min-heap/max-heap

// Method 3. O(n) time, O(1) Space
int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    int i = 0, j = 0;
    
    while(i < n || j < m) {
        if(i+j+1 == k) {
            if(i == n)  return arr2[j];
            else if(j == m) return arr1[i];
            else return min(arr1[i], arr2[j]);
        }
        
        if(i == n) {
            j++;
        } 
        else if(j == m) {
            i++;
        } 
        else if(arr1[i] < arr2[j]) {
                i++;
            } else {
                j++;
            }
        }
    return -1;
}

// Method 4. using binary search O(logn + logm)
int kth(int *arr1, int *arr2, int *end1, int *end2, int k) {
    if (arr1 == end1)
        return arr2[k];     // k = 0
    if (arr2 == end2)
        return arr1[k];     // k = 0

    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    
    if (mid1 + mid2 < k) {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2, k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2, k - mid1 - 1);
    }
    else {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}

int main() {
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};

    int k = 5;
    cout << kth(arr1, arr2, arr1 + 5, arr2 + 4,  k - 1);
    return 0;
} 
