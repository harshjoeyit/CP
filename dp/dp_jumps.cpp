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


//###########################################################################################################################################################

// for can jump on the lily flowers '1' only 
// 1 <= jump <= d 
// s consists of 0 and 1 i.e. lily and no lily 
// st = 1, en = n-1
// find min jumps to en 



string s;
int n, d;
int Min = MOD;
vector<int> v(200);

// brute force 
// void move(int i, int steps)
// {
//     if(i == n-1)
//     {
//         if(steps < Min)
//             Min = steps;
//         return;
//     }
//     bool f = true;
//     for(int j = i+1; j <= min(i+d, n-1); j++)
//         if(s[i] == '1')
//             move(j, steps+1);
    
// }

int ret_min(int l, int r)
{
    int m = MOD;
    for(int i = l; i <= r; i++)
        if(s[i] == '1' && v[i] < m)
            m = v[i];
    return m;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    cin >> s;

    for(int i = 1; i < n; i++)
    {
        if(s[i] == '1')
        {
            int u = ((0 > i-d) ? 0 : i-d);
            v[i] = ret_min(u, i-1) + 1;
        }
    }

    if(v[n-1] >= MOD)
        v[n-1] = -1;
    
    cout << v[n-1] << endl;

    // brute force
    // move(0, 0);
    // if(Min == MOD)
    //     Min = -1;
    // cout << Min << endl;
}