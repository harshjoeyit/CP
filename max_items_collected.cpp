

/*
Find max items that can be taken by two persons together 
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n, m, x, y, a, b, ans = 0;
      // n, m are cappacities 
      // x, y are number of items available  
      // a, b are corresponding wieghts
      cin >> n >> m;
      cin >> x >> y;
      cin >> a >> b;

      if(a > b) {
            swap(a, b);
            swap(x, y);
      }
      // we want to work with the item with less weight

      for (int i = 0; i <= x; i++) {
            // i is the nuber of items of type1
            // that person1 chooses 
            if(n >= a * i) {
                  // capacity >= total weight of the items
                  int j = min(y, (n - (a * i)) / b);
                  // n - a*i is remaining capacity of person1
                  // j = number of items of type2 that person1 takes
                  int k = min(x - i, m / a);
                  // x - i are remaining items of type1 
                  // m/a are items of type1 that can be taken by person2
                  int l = min(y - j, (m - (k * a)) / b);
                  // y - j are remaining items of type 2
                  // (m - (k * a)) is remaining capacity of person2
                  ans = max(ans, i + j + k + l);
            }
      }

      cout << ans << "\n";
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}