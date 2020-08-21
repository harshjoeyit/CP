
#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s)
{
      int n = (int)s.length();
      vector<int> z(n);
      int l = 0, r = 0;
      for (int i = 1; i < n; i++) {
            if (i <= r) {
                  z[i] = min(r - i + 1, z[i - l]);
            }
            // segment should not stretch out of the array while copying previous values so (r-i+1)

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                  ++z[i];
            }

            // i + z[i] - 1 = rightmost index of the segment
            if (i + z[i] - 1 > r) {
                  l = i, r = i + z[i] - 1;
            }
      }
      return z;
}

void main()
{
}