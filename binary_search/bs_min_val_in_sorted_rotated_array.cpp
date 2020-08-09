
/*
Exmaples of array - 
2 3 4 5 6 1
4 5 6 1 2 3
8 9 1 2 3 4 6 7
1 2 3
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int

int findMin(vector<int>& a) {
    int n = a.size(), low = 0, high = a.size() - 1, mid;
    
    while(low <= high) {
        mid = low + (high - low)/2;
        // condition 1
        if(a[mid] > a[high]) {
            low = mid + 1;
        }
        // condition 2
        else if(a[mid] < a[high]) {
            high = mid;
        } 
        // high - low = 0
        else {
            return a[low];
        }
    }
    return -1;
}

// find value in rotated sorted array 
void findValInRotatedSortedArray(vector<int> &a, int val) {
      int low = findMin(a);
      int n = a.size();
      bool f;

      cout << "low: " << low << endl;

      if(a[low] <= val && val <= a[n-1]) {
            f = binary_search(a.begin()+low, a.end(), val);
      } else {
            f = binary_search(a.begin(), a.begin()+low, val);
      }

      if(f) {
            cout << "found\n";
      } else {
            cout << "not found\n";
      }
}