
/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary the task is to complete the function which returns a string denoting the order of characters in the language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order.
Examples:
Input:  Dict[ ] = { "baa", "abcd", "abca", "cab", "cad" }, k = 4
Output: Function returns "bdac"
Here order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa"
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input: Dict[] = { "caa", "aaa", "aab" }, k = 3
Output: Function returns "cab"
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int

string dict[400];
vector<int> g[27];
int indegree[27]; 
int n, k;

vector<int> topo_sort() {
    queue<int> q;
    vector<int> topo;

    for(int i = 1; i <= k; i++)
        if(indegree[i] == 0)
            q.push(i);

    while( ! q.empty()) {
        int u = q.front();
        q.pop();
        topo.emplace_back(u);

        for(auto &v: g[u]) {
            --indegree[v];
            if(indegree[v] == 0)
                q.push(v); 
        }
    }
    return topo;
}

void print(vector<int> v) {       
    for(auto x: v) {
        char c = (char)(x-1+'a');
        cout << c;
    }
    cout << endl;
}

void add_edge(string &s1, string &s2) {
    int j=0; 
    int up = min(s1.length(), s2.length());
    while(j < up && s1[j] == s2[j]) {
        ++j;
    }
    if(j < up) {
        int x = s1[j]-'a'+1;
        int y = s2[j]-'a'+1;
        g[x].push_back(y); 
        ++indegree[y]; 
        
        // cout << x << "->" << y << endl;
    }
}

void insert_edges() {
    for(int i=0; i<n-1; i++) {
        add_edge(dict[i], dict[i+1]);
    }
}

// string printOrder(string dict[], int N, int k) {
    
// }

void solve() {
    for(int i=0; i<27; i++) {
        g[i].clear();
    }
    memset(indegree, 0, sizeof(indegree));

    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> dict[i];
    }

    insert_edges();

    vector<int> ans = topo_sort();
    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}