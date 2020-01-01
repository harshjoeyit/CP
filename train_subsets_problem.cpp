#include<bits/stdc++.h>
using namespace std;

#define int long long int 
#define vi vector<int> 

// CHFRAN - codechef
// on the logic of min platform problem: 
// but this time we need to remove the trains such that we can sepearate the trains in two subsets(trains are in the same subset if their arr- dep range intersect with another) 
// or we can say there is a time where there is no train on the platrom 


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;

    while(T--)
    {
       int n;
        cin >> n;
        vi arr(n);
        vi dep(n);
        vector<pair<int, int>> merger(2*n);

        for(int i = 0; i < n; i++)
            cin >> arr[i] >> dep[i];

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0, k = 0, cnt = 0;

        while(i < n && j < n)
        {
            if(arr[i] <= dep[j])
            {
                ++cnt;  
                merger[k].first = cnt;              // merger[index].frist - how many trains are there at the platform at the time
                merger[k].second = 1;               // 1- arrival
                ++k;
                ++i;
            }
            else
            {
                --cnt;
                merger[k].first = cnt;
                merger[k].second = 0;
                ++j;
                ++k;
            }
        }  

        // for(auto &x: merger)
        //     cout << x.first << " " << x.second << "\t";
        // cout << endl;  

        bool one_departed = false;
        cnt = 1e9;
        for(int i = 0; i < k; i++)              // checking how many trains need to be removed for each arrival if at least one train has departed 
        {
            if(merger[i].second == 0)
                one_departed = 1;
            else
            {
                if(one_departed)
                    cnt = min(cnt, merger[i].first - 1);        // -1 because it contains the current/arriving train too
            }
        }    
        if(cnt == 1e9)
            cnt = -1;
        cout << cnt << endl;
    }

    
}