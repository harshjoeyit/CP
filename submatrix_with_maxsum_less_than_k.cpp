
/*
submatrix with maximum sum less than equal to k 

concept used - 2d - kadane and maximum sum less that equal to k in 1 d array

*/

#include <bits/stdc++.h>
using namespace std;

int subarraySumLessThanEqualToK(vector<int> sums, int k)
{
      int sum = 0, ans = INT_MIN;
      set<int> st;
      st.insert(0);

      for (int i = 0; i < sums.size(); i++)
      {
            sum += sums[i];
            auto it = st.lower_bound(sum - k);
            if (it != st.end())
            {
                  ans = max(ans, sum - *it);
            }
            st.insert(sum);
      }
}

int maxSumSubmatrix(vector<vector<int>> &mat, int k)
{
      if (mat.size() == 0 || mat[0].size() == 0)
      {
            return 0;
      }
      int rows = mat.size(), cols = mat[0].size(), res = INT_MIN;

      for (int left = 0; left < cols; left++)
      {
            vector<int> sums(rows);
            for (int right = left; right < cols; right++)
            {

                  for (int row = 0; row < rows; row++)
                  {
                        sums[row] += mat[row][right];
                  }

                  res = max(res, subarraySumLessThanEqualToK(sums, k));
            }
      }

      return res;
}

int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      vector<vector<int>> mat = {
          {-1, -1, -1},
          {1, 3, 1},
          {-1, 1, -1}};

      cout << maxSumSubmatrix(mat, 4);
}