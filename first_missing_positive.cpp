#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
      int n = A.size();
      for (int i = 0; i < n; ++i) {
            // continue to move the current element to the right index 
            // till correct element the cond is satisfied 
            while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) {
                  swap(A[i], A[A[i] - 1]);
            }
      }
      // after this is finished, all the element if present are at correct positions 
      // the one that is not present at the correct  pos is the ans 
      for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                  return i + 1;
            }
      }
      return n + 1;
}

int main() {
}