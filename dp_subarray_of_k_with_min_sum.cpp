#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>

template <typename T>
void print(vector<T> v)
{
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}
template <typename T1, typename T2>
void print(vector<pair<T1, T2>> v)
{
    for(auto x: v)
        cout << "("<< x.first << "," << x.second <<"), ";
    cout << endl;
}
template <typename T1, typename T2>
void print(map<T1, T2> m)
{
    for(auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " - " << it->second << endl; 
}
template <typename T>
void print(set<T> s)
{
    for(auto x: s)
        cout << x << " ";
    cout << endl; 
}
int min(int i, int j)
{
    return ((i < j) ? i : j);
}

int max(int i, int j)
{
    return ((i > j) ? i : j);
}

//###########################################################################################################################################################


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vi a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vi pre(a), suf(a);
    for(int i = 2; i <= n; i++)
        pre[i] += pre[i-1];
    for(int i = n-1; i >= 1; i--)
        suf[i] += suf[i+1];

    suf.push_back(0);
    // print(a);
    // print(pre);
    // print(suf);

    int ans = MOD, s, t = pre[n], j;
    for(int i = 1; i <= n-k+1; i++)
    {
        s = t - pre[i-1] - suf[i+k];
        //cout << s << endl;
        if(s < ans)
        {
            ans = s;
            j = i;
        }
    }
    cout << j << endl;
}