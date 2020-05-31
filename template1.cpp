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

void print(int a[], int l, int r) {
    for(int i=l; i<=r; i++)
        cout << a[i] << " ";
    cout << "\n";
}

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

// directly printing out the pairs as - 
// cout << p << endl;
template<class A, class B> 
ostream& operator << (ostream& out, const pair<A, B> &p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

// print out any vector using vector of pairs(of any type), use the above class to print vector of pair 
template<class A> 
ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    for(int i = 0; i < v.size(); i++) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
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


void solve() {

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // for precision
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}