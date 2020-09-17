

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int range) {
      int n = a.size();
      int j = -1;
      // first light 
      for (int i = 0; i < range; i++) {
            if(a[i] == 1) {
                  j = i;
            }
      }
      // first light not found
      if(j == -1) {
            return -1;
      }

      int ans = 1;

      while (j < n-1) {
            if(j + range - 1 >= n-1) {
                  // we dont need another light
                  break;
            }

            // find another light
            int k = j + 2 * range - 1;
            for (; k > j; k--) {
                  if(a[k] == 1) {
                        break;
                  }
            }

            // light not found
            if(k == j) {
                  return -1;
            }

            // find next light after this
            ans += 1;
            j = k;
      }

      return ans;
}

int main() {
      int n, range;
	cin >> n >> range;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
      cout << solve(a, range) << endl;
}