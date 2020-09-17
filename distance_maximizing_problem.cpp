
#include<bits/stdc++.h>
using namespace std;

void distanceMaximizing(vector<int> &a) {
      int n = a.size();
      vector<int> left(n);
      vector<int> right(n);

      left[0] = 0, right[n-1] = n-1;
      for(int i=1; i<n; i++) {
            if(a[i] < a[left[i - 1]]) {
                  left[i] = i;
            } else {
                  left[i] = left[i - 1];
            }
      }
      for (int i = n - 2; i >= 0; i--) {
            if(a[i] > a[right[i + 1]]) {
                  right[i] = i;
            } else {
                  right[i] = right[i + 1];
            }
      }

      for (int i = 0; i < n; i++) {
            cout << left[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < n; i++) {
            cout << right[i] << " ";
      }
      cout << endl;

      int i = 0, j = 0, ans = 0;
      int st=-1, en=-1;
      while (i < n) {
            if(a[left[i]] < a[right[j]]) {
                  if(j - i > ans) {
                        st = i, en = j;
                        ans = j - i;
                  }
                  j += 1;
            } else {
                  i += 1;
            }
      }

      cout << st << " " << en << endl;
      cout << ans << endl;
}

int main() {
      int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
      distanceMaximizing(a);
}