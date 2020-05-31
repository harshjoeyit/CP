#include <bits/stdc++.h> 
using namespace std; 
  
// Prints the pair with sum closest to x 
void printClosest(int arr[], int n, int x) 
{ 
    int res_l, res_r;
    int l = 0, r = n-1, diff = INT_MAX; 

    while (r > l) 
    { 
       // Check if this pair is closer than the closest pair so far 
       if (abs(arr[l] + arr[r] - x) < diff) 
       { 
           res_l = l; 
           res_r = r; 
           diff = abs(arr[l] + arr[r] - x); 
       } 

       if (arr[l] + arr[r] > x) 
           r--; 
       else // Move to larger values 
           l++; 
    } 
  
    cout <<" The closest pair is " << arr[res_l] << " and " << arr[res_r]; 
} 
  p
int main() 
{ 
    int arr[] =  {1, 2, 3, 4, 5, 8, 11}, x = 10; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printClosest(arr, n, x); 
    return 0; 
}