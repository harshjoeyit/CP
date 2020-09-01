// C++ program to rotate an array by 
// d elements 
#include <bits/stdc++.h> 
using namespace std; 


// 1. O(n) space approach uses temp array 
// 2. O(1) space, O(n*n) approach rotates 1 by 1
// 3. A Juggling Algorithm
// 4.  Revesal Algorithm

/*Fuction to get gcd of a and b*/
int gcd(int a, int b)  { 
    if (b == 0) 
        return a; 
    else
        return gcd(b, a % b); 
} 
  
/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)  { 
    /* To handle if d >= n */
    d = d % n; 
    int g_c_d = gcd(d, n); 
    for (int i = 0; i < g_c_d; i++) { 
        /* move i-th values of blocks */
        int temp = arr[i]; 
        int j = i; 

        while (1) { 
            // go cyclic
            int k = (j + d) % n;  
            if (k == i) 
                break; 

            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    } 
} 


// Reversal Algorithm 

/*Function to reverse arr[] from index start to end*/
void reverseArray(int arr[], int start, int end)  { 
    while (start < end) {
          swap(arr[start], arr[end]);
          start++;
          end--; 
    } 
} 
  
/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n) { 
    if (d == 0) 
        return; 
    reverseArray(arr, 0, d - 1); 
    reverseArray(arr, d, n - 1); 
    reverseArray(arr, 0, n - 1); 
} 

// Function to print an array 
void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
} 
  
/* Driver program to test above functions */
int main() { 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function calling 
    leftRotate(arr, 4, n); 
    printArray(arr, n); 
  
    return 0; 
} 