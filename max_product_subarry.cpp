// C++ program to find Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;

int maxProduct(int a[], int n) {
      int minp, maxp, ans;
      minp = maxp = ans = a[0];

      for (int i = 1; i < n; i++) {
            if(a[i] >= 0) {
                  maxp = max(maxp * a[i], a[i]);
                  minp = min(minp * a[i], a[i]);
            } else {
                  int temp = maxp;
                  maxp = max(minp * a[i], a[i]);
                  minp = min(temp * a[i], a[i]);
            }
      }
      return ans;
}

// Driver code
int main()
{
}
