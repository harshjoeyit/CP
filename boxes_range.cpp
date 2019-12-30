#include<bits/stdc++.h>
using namespace std;

#define int long long int

// n boxes have capacity mentioned 
// operation - choose L and fill 1 token in each box for 1,2,3,4.....L
// op can be performed any no of times 
// find the max tokens filled in the box

// logic
// For a range 0…L we cannot have more than min(0…L) in all the boxes collectively. If we keep calculating minimum for every next range and update for each ith box the best we can do to be min(0…i) 

signed main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int Min = 1e18, ans = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            Min = min(x, Min);
            ans += Min;
            
        }
        cout << ans << endl;
    }
    
}