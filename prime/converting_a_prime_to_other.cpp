#include<bits/stdc++.h>
using namespace std;

// given two 4 digit prime numbers convert a to b in minimum number if steps , A step means changing one digit at a time only

#define int long long int
vector<bool> arr(100000, true);
vector<bool> vis(100000, false);    
vector<int> primes;
int dis[100000];
vector<int> G[100000];

template <typename T>
void print(vector<T> v)
{
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

void find_primes()
{
    arr.assign(100000, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i <= 100000; i++) 
    {
        if (arr[i] && i * i <= 100000) 
        {
            for (int j = i * i; j <= 100000; j += i)
                arr[j] = false;
        }
    }

    for(int i = 1000; i <= 9999; i++)
        if(arr[i])
            primes.push_back(i);

}


bool isOk(int x, int y)
{
    int c = 0;
    while(x > 0 && y > 0)
    {
        if((x % 10) != (y % 10))
            ++c;
        x = x / 10;
        y = y / 10;
    }
    if(c == 1)
        return true;
    return false;
}


void make_edges()
{
    int n = primes.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int p = primes[i], q = primes[j];
            if(isOk(p, q))
            {
                G[p].push_back(q);
                G[q].push_back(p);
            }
        }
    }
}

void bfs(int a, int b)
{
    vis.assign(100000, false);
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(a);
    dis[a] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(u == b)
            break;

        for(auto v: G[u])
        {
            if(!vis[v])
            {
                dis[v] = dis[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    
    find_primes();
    make_edges();

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        bfs(a, b);
        if(dis[b] == -1)
            cout << "Impossible" << endl;
        else
            cout << dis[b] << endl;
    }
}