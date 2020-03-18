#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, p, k, ans = 0;
        cin >> n >> p >> k;
        vector<int> v(n);
        vector<int> sum(n);

        for(int i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end());
        sum[0] = v[0];
        for(int i = 1; i < k-1; i++)
            sum[i] = sum[i-1] + v[i];
        
        sum[k-1] = v[k-1];

        for(int i = k; i < n; i++)
            sum[i] = v[i] + sum[i-k];           // k items cost max cost of k items   
                                                // sum = max price of k items(v[i]) + price of items not bought in offer(s[i-p])
        
        // NOTE : the offer can be used multiple times
        // for example: 
        // 1 2 3 4 5 6 be the prices
        // p = 9
        // if the third item and 3 and 1 are free 
        // if the sixth item is bought 4 and 5 are free

        for(int i = 0; i < n; i++)
            if(p >= sum[i])
                ans = i+1;  

        cout << ans << endl;
    }
}