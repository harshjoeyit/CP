#include<bits/stdc++.h>
using namespace std;

const int nMx = 100;
int n, m;
bool g[nMx][nMx];
int match[nMx];
bool seen[nMx];

bool bpm(int u, bool seen[], int match[]) {
    for(int v = 0; v < n; v++) {
        if(g[u][v] && !seen[v]) {
            seen[v] = true;

            if(match[v] < 0 || bpm(v, seen, match)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM() {
    memset(match, -1, sizeof(match));

    int res = 0;
    for(int u = 0; u < m; u++) {
        memset(seen, 0, sizeof(seen));

        if(bpm(u, seen, match)) 
            res++;
    }
    return res;
}

int main() {
    cin >> m >> n;              // m applicants , n jobs
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) 
            cin >> g[i][j];
    
    cout << " max matching: " << maxBPM() << endl;
    for(int i = 0; i < n; i++) 
        if(match[i] >= 0)
            cout << match[i] << " -> " << i << endl;
    
}
