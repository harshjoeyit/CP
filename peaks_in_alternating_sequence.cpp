
/*
finding peaks in the alternating sequence of numbers
each number is unique
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0; i<n; i++) {
            cin >> a[i];
      }
      vector<int> ans;
      vector<int> diff(n);

      // adjacent element diff 
      for(int i=1; i<n; i++) {
            diff[i] = a[i] - a[i-1];
      }

      ans.push_back(a[0]);
      for(int i=1; i<n; i++) {
            if((diff[i-1] > 0 && diff[i] < 0) || (diff[i-1] < 0 && diff[i] > 0)) {
                  ans.push_back(a[i-1]);
            }
      }      
      ans.push_back(a[n-1]);

      cout << ans.size() << endl;
      for(auto x: ans) {
            cout << x << " ";
      }cout << endl;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--)
      solve();
}



/*
Easier implementation

#include <bits/stdc++.h>
using namespace std;
int p[100005];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        scanf("%d",&p[i]);
        vector<int> ans;
        for (int i=1;i<=n;i++)
        {
            if (i==1 || i==n || (p[i-1]<p[i])!=(p[i]<p[i+1]))
            ans.push_back(p[i]);
        }
        printf("%d\n",ans.size());
        for (int i:ans)
        printf("%d ",i);
        printf("\n");
    }
}
*/