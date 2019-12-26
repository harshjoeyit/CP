#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<long long int> ans;
        long long int n, rt;
        cin >> n;   

        rt = sqrtl(n);

        ans.push_back(0);
        for(int i = 1; i <= rt; i++)
        {
            ans.push_back(i);
            if(floor(n/i) != i)
                ans.push_back(floor(n/i));
        
        }
        
        sort(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for(auto &x: ans)
            cout << x << " ";
        cout << endl;
    }
}