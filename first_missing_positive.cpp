#include <bits/stdc++.h>
using namespace std;

// Example 
// 6 1 4 2 5 4 
// ans = 3

// -1 1 3 2 4
// ans = 5

// 6 9 8 5 3 1
// 2

int firstMissingPositive(vector<int> &a) {
      int n = a.size();
      // correct index of a value is (a[i]-1) if 1 <= a[i] <= n
      for (int i = 0; i < n; ++i) {
            // we only try to move the current element to its correct index
            // only the index of elements in range [1, n] can be found 
            // so we dont care about those numbers, since they do not have 
            // a correct index in the array 
            while (a[i] > 0 && a[i] <= n && a[a[i] - 1] != a[i]) {
                  swap(a[i], a[a[i] - 1]);
            }
      }

      // the first one that is not present at the correct index is the first missing
      for (int i = 0; i < n; ++i) {
            if (a[i] != i + 1) {
                  return i + 1;
            }
      }
      return n + 1;
}

int main() {
      int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
      cout << firstMissingPositive(a);
}