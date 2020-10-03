//?https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k/0
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> pre(n);
        pre[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + a[i];
        }
        unordered_map<int, int> ump;
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << pre[i] << endl;
            if (pre[i] == k)
            {
                len = max(len, i + 1);
            }
            if (ump.find(pre[i] - k) != ump.end())
                len = max(len, i - ump[pre[i] - k]);
            if(ump.find(pre[i]) == ump.end())
                ump[pre[i]] = i;
        }
        cout << len << endl;
    }
}