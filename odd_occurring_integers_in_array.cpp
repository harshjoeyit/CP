
#include <bits/stdc++.h> 
using namespace std; 


void printTwoOdd(int a[], int n)  {
      int x = 0;
      for (int i = 0; i < n; i++) {
            x ^= a[i];
      }

      int bit = x & (-x);
	// use this method to find first set bit in x
	// it works with neg numbers too
      int p = 0, q = 0;

      for (int i = 0; i < n; i++) {
            if(a[i] & bit) {
                  p ^= a[i];
            } else {
                  q ^= a[i];
            }
      }
      cout << p << " " << q << endl;
}

int main() { 
	int arr[] = {4, -2, 4, -5, -2, 3, 3, -1}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
	printTwoOdd(arr, arr_size); 
	return 0; 
} 
