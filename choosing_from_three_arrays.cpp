
#include<bits/stdc++.h>
using namespace std;

int main() {
      int n1, n2, n3;
      cin >> n1 >> n2 >> n3;
      vector<int> a(n1), b(n2), c(n3);

      for (int i = 0; i < n1; i++)
            cin >> a[i];
      for (int i = 0; i < n2; i++)
            cin >> b[i];
      for (int i = 0; i < n3; i++)
            cin >> c[i];

      vector<int> ans;

      for (int i = 0; i < n1; i++) {
            if(binary_search(b.begin(), b.end(), a[i]) || binary_search(c.begin(), c.end(), a[i])) {
                  ans.push_back(a[i]);
            }
      }

      for (int i = 0; i < n2; i++) {
            if(binary_search(c.begin(), c.end(), b[i])) {
                  ans.push_back(b[i]);
            }
      }

      for (auto val: ans) {
            cout << val << " ";
      }
      cout << endl;
}