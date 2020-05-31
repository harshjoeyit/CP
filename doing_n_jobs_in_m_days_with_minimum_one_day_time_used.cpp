#include<bits/stdc++.h>
using namespace std;

// greedy, binary search

int main()
{
    long long int n, t, days, l, h, sum, ans = -1, D;
    cin >> n >> days;
    D = days;
    vector<long long int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    l = 0, h = 1000000000000000000;

    // using binary dearch method to find correct value of t 
    while(l <= h)
    {
        t = l + (h-l)/2;
        int i;
        sum = 0;
        days = D;

        // loop for checking if in one day person spends t time , all the jobs requiring a[i] time can be completed in m days or not 
        for(i = 0; (days > 0) && (i < n); i++)
        {
            sum += a[i];
            if(sum == t)
            {
                sum = 0;
                days--;
            }
            else if(sum > t)
            {
                sum = 0;
                days--;
                // start from this object again as loop (i++) goes to next object\
                // but this task could not be completed 
                i--;
            }
        }

        if((days == 0) && (i != n))
            l = t + 1;
        
        else
        {
            ans = t;
            h = t - 1;
        }
    }

    cout << ans << endl;
}