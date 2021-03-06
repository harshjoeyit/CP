#include<bits/stdc++.h>
using namespace std;
#define int long long int

int T, B, L, R, maxsum;

// finding the coordinates as well 
void kadane(vector<int> &a, int &t, int &b) {
      int l=0, r=0, sum=0, ans=a[0], minus_pos=-1, m=a.size();
      for(int i=0; i<m; i++) {
            sum += a[i];
            if(sum > ans) {
                  ans = sum;
                  l = minus_pos+1;
                  r = i;
            }
            if(sum < 0) {
                  sum = 0;
                  minus_pos = i;
            }
      }
      if(ans > maxsum) {
            maxsum = ans;
            T = t, B = b, L = l, R = r;
      }
}

void maxsum_rectangle(vector<vector<int>> matrix, int n, int m) {
      // fixing the top side 
      for(int t=0; t<n; t++) {
            vector<int> temp(m);
            // fixing the bottom side 
            for(int b=t; b<n; b++) {
                  for(int j=0; j<m; j++) {
                        temp[j] += matrix[b][j];
                  }
                  // find rectangle between these two sides 
                  kadane(temp, t, b);
            }
      }
}


// Similar 
// Maxsum rectangle, sum <= k 
int subarraySumLessThanEqualToK(vector<int> &sums, int k) {
      int sum = 0, ans = INT_MIN;
      set<int> st;
      st.insert(0);

      for (int i = 0; i < sums.size(); i++) {
            sum += sums[i];
            auto it = st.lower_bound(sum - k);
            if (it != st.end())
            {
                  ans = max(ans, sum - *it);
            }
            st.insert(sum);
      }
      return ans;
}

int maxSumSubmatrix(vector<vector<int>> &mat, int k) {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      if (mat.size() == 0 || mat[0].size() == 0) {
            return 0;
      }
      int rows = mat.size(), cols = mat[0].size(), res = INT_MIN;

      for (int left = 0; left < cols; left++) {
            vector<int> sums(rows);
            for (int right = left; right < cols; right++) {
                  for (int row = 0; row < rows; row++) {
                        sums[row] += mat[row][right];
                  }
                  res = max(res, subarraySumLessThanEqualToK(sums, k));
            }
      }
      return res;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int n, m;
      cin >> n >> m;
      vector<vector<int> > matrix;
      matrix.assign(n, vector<int>(m));
      for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                  cin >> matrix[i][j];
            }
      }
      // O(n^3)
      maxsum_rectangle(matrix, n, m);
      cout << maxsum << endl;
      cout << T << " " << B << " " << L << " " << R << endl;
}