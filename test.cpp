#include<bits/stdc++.h>
using namespace std;

#define int long long int

struct line_seg{
    int p, q;
    int r, s;
};

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> v(n+1);
        vector<line_seg> lines;

        for(int i = 1; i <= n; i++)
            cin >> v[i];

        for(int i = 1; i < n; i++)
            lines.push_back({i, v[i], i+1, v[i+1]});
        
        // for(auto l: lines)
        // {
        //     cout << "(" << l.p << ", "<< l.q << ") - (" << l.r << ", " << l.s << ")" << endl;
        // }
        while(q--)
        {
            int x1, x2, y, ans = 0;
            scanf("%lld%lld%lld",&x1, &x2, &y);

            for(auto l: lines)
            {
                if(l.p < x1 && l.r <= x1)
                    continue;
                if(l.p >= x2 && l.r > x2)
                    continue;
                if(l.q > y && l.s > y)
                    continue;
                if(l.q < y && l.s < y)
                    continue;
                
                ++ans;
            }
            printf("%lld\n", ans);
        }
    }   
}