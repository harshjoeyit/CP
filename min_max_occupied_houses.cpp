#include<bits/stdc++.h>
using namespace std;

/*
Oh, New Year. The time to gather all your friends and reflect on the heartwarming events of the past year...

n friends live in a city which can be represented as a number line. The i-th friend lives in a house with an integer coordinate xi. 
The i-th friend can come celebrate the New Year to the house with coordinate xi−1, xi+1 or stay at xi.
Each friend is allowed to move no more than once.

For all friends 1≤xi≤n holds, however, they can come to houses with coordinates 0 and n+1 (if their houses are at 1 or n, respectively).

Print two integers — the minimum and the maximum possible number of occupied houses after all moves are performed.
*/

#define vi vector<int>
int main()
{
    int n, x;
    cin >> n;
    vi cnt(n+2);
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        ++cnt[x];
    }

    int min_count = 0, i = 1; 
    while(i <= n)
    {
        if(cnt[i] > 0) 
        {
            ++min_count;
            i = i+3;
        }
        else
            ++i;
    }
    
    for(int i=1; i<=n; ++i) 
    {
        if(!cnt[i]) continue;
        if(!cnt[i-1]) --cnt[i], ++cnt[i-1];
        if(cnt[i]>1) --cnt[i], ++cnt[i+1];
    }

    int max_count = 0;
    for(auto x : cnt)
    {
        if(x > 0)
            ++max_count;
    }

    cout << min_count << " " << max_count << endl;
}