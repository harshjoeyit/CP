
/*
Given Some books with each having `pages` = pages[i]
These books are to be divided into `k` sub-books such that 
- A sub-book has pages from 1 book only 
- All sub-books have same number of pages 
- k >= 1
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    int low = 1, high = *max_element(pages.begin(), pages.end());
    // each sub-book can have at minimum 1 page, and max high page (when k = 1)
    int ans = 0;
    // there is possibility that no k subboks cannot be created 
    // then ans = 0

    while (low <= high) {
        int pg = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // add the sub-books that can be made out of this book 
            // with each sub-book having pages = pg
            cnt += pages[i] / pg;
        }

        if(cnt >= k) {
            low = pg + 1;
            ans = max(ans, pg);
        } else if (cnt < k){
            high = pg - 1;
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