#include <bits/stdc++.h> 
using namespace std; 
  
// Prints the pair with sum closest to x 
void printClosest(int a[], int n, int target) { 
    int ansi, ansj;
    int i = 0, j = n-1, diff = INT_MAX; 

    while (i < j) { 
       // Check if this pair is closer than the closest pair so far 
       if (abs(a[i] + a[j] - target) < diff) {
           ansi = i;
           ansj = j;
           diff = abs(a[i] + a[j] - target);
       } 

       if (a[i] + a[j] > target) 
           j--; 
       else 
           i++; 
    }

    cout << ansi << " " << ansj << "\n";
}

int main() { 
    int arr[] =  {1, 2, 3, 4, 5, 8, 11}, x = 10; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printClosest(arr, n, x); 
    return 0; 
}