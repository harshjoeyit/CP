#include<bits/stdc++.h>
using namespace std;

// odd in the beginning
// note: this algo preserves the order of odd elements 
// but not of even elements 
// to preserve order of even elements too 
// we need extra space 
void seperateEvenOdd(vector<int> &a) {
      int j, n = a.size();

      for(int i=0; i<n; i++) {
            if(a[i] % 2 == 1) {
                  continue;
            } 
            // num is even, find a odd number
            j = i+1;
            while(j < n && a[j] % 2 == 0) {
                  j += 1;
            }
            // if odd number found
            if(j < n) {
                  swap(a[i], a[j]);
            }
      }
}

// another implementation 
void seperate(vector<int> &a) {
      int n = a.size();
      int left = 0, right = n-1;

      while(left < right) {
            while(left < right && (a[left] % 2 == 1)) {
                  // if odd continue;
                  left += 1;      
            }
            // found an even no
            while(left < right && (a[right] % 2 == 0)) {
                  // if even continue;
                  right -= 1;
            }
            // found and odd number 
            if(left < right) {
                  // swap
                  swap(a[left], a[right]);
                  left += 1;
                  right -= 1;
            }
      }
}

int main() {
      vector<int> a = {2,1,4,6,3,8,1};
      // seperateEvenOdd(a);
      seperate(a);
      for(int i=0; i<a.size(); i++) {
            cout << a[i] << " ";
      }cout << endl;
}