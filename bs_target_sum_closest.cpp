
/*
https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

find min value - when all values above which when changed to it make the array sum closeset to target
*/


#include<bits/stdc++.h>
using namespace std;

int findBestValue(vector<int> &a, int target) {
      int n = a.size(), high = INT_MIN;
      sort(a.begin(), a.end());

      vector<int> prefix(n + 1, 0);
      for (int i = 0; i < n; i++) {
            prefix[i + 1] = a[i] + prefix[i];
            high = max(high, a[i]);
      }

      int diff, minDiff = INT_MAX, sum, mid, i, ans, low = 0;

      while (low <= high)   {
            mid = (low + high) / 2;
            i = lower_bound(a.begin(), a.end(), mid) - a.begin();
            sum = (n - i) * mid + prefix[i];
            diff = target - sum;

            if (abs(diff) < minDiff) {
                  minDiff = abs(diff);
                  ans = mid;
            } else if(abs(diff) == minDiff) {
                  ans = min(ans, mid);
            }

            if (diff > 0)
            {
                  low = mid + 1;
            }
            else
            {
                  high = mid - 1;
            }
      }

      return ans;
}

int main()
{
}
