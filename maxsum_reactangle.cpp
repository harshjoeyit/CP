#include<bits/stdc++.h>
using namespace std;
#define int long long int

int T, B, L, R, maxsum;

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
      for(int t=0; t<n; t++) {
            vector<int> temp(m);
            for(int b=t; b<n; b++) {
                  for(int j=0; j<m; j++) {
                        temp[j] += matrix[b][j];
                  }
                  kadane(temp, t, b);
            }
      }
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