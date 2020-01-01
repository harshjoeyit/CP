#include<bits/stdc++.h>
using namespace std;

#define int long long int 
#define vi vector<int> 

// edges weight, vertices weights are given
// arrange them so that adjacent vertices of every edge is greater than or equal to its weight
// arrange nodes in descending order of degree and then balance the edge weightd by vertices weigths  

signed main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;

    while(T--)
    {
        int n, u, v, Max = -1;;
        cin >> n;
        vector<int> edge(n);
        vector<int> ver(n);
        for(int i = 0; i < n-1; i++)
        {
            cin >> u >> v >> edge[i];
            Max = max(edge[i], Max);
        }
        edge[n-1] = Max;

        for(int i = 0; i < n; i++)
            cin >> ver[i];

        sort(ver.begin(), ver.end(), greater<int>());
        sort(edge.begin(), edge.end(), greater<int>());

        // print_vector(ver);
        // print_vector(edge);

        int j = 0, cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(edge[i] > ver[j])
                ++cnt;
            else
                ++j;
        }  
        cout << cnt << endl;
    }
}