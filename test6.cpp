


// https://www.codechef.com/LTIME82B/problems/MXMLCM

// compare codes


#include<bits/stdc++.h>
using namespace std;
const int maxn = 10009;
int n, m;
int t, cs = 1;
int ara[maxn];
vector<pair<int, int>> divs[maxn + 7];

int ppow[maxn + 7];

void printdiv() {
    for(int i=0; i<20; i++) {
        cout << i << "--> ";
        for(auto p: divs[i]) {
            cout << "(" << p.first <<"-" << p.second <<"),  ";
        }
        cout << endl;
    }
}

void sieve(int n) {
	for(int i = 2; i <= n; i++) {
	    if(divs[i].size()) 
            continue;
	    for(int j = i; j <= n; j += i) 
            divs[j].push_back({i, 0});
	}

	for(int i = 2; i <= n; i++) {
	    for(int j = 0; j < divs[i].size(); j++) {
	        int cur = divs[i][j].first;
	        int cnt = 0, val = i;
	        while(val % cur == 0) 
                val = val / cur, cnt++;
	        divs[i][j].second = cnt;
	    }
	}
}

int main()
{
	cin >> t;
	sieve(maxn);
    // printdiv();
	while(t--){
	    scanf("%d %d", &n, &m);
	    memset(ppow, 0, sizeof(ppow));

	    for(int i = 1; i <= n; i++){
	        scanf("%d", &ara[i]);
	        for(auto dv : divs[ara[i]]) 
                ppow[dv.first] = max(ppow[dv.first], dv.second);
	    }

	    int mxmLCM = 0, mxmAns = 0;

	    for(int i = 1; i <= m; i++){

	        int barbe = 1;
	        for(auto dv : divs[i]){
	            int dif = max(0, dv.second - ppow[dv.first]);
	            for(int i = 1; i <= dif; i++) 
                    barbe = barbe * dv.first;
	        }
	        if(barbe > mxmLCM){
	            mxmLCM = barbe;
	            mxmAns = i;
	        }
	    }
	    printf("%d\n", mxmAns);
	}

	return 0;
}




// ...........................................................................................




#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mxN = 1e4+10;
bool isprime[mxN+10];
int n, m, a[mxN], ppow[mxN];

template <typename T1, typename T2>
void print(map<T1, T2> m) {
    for(auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " - " << it->second << endl; 
}

map<int, int> factorize(int n) {
    map<int, int> freq;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) 
        {                // loop fo checking the repeated factors 
            ++freq[i];
            n /= i;                         
        }
    }
    if (n != 1) 
        ++freq[n];
   return freq;
}

void sieve() {
    for(int i=2; i<=mxN; i++)
        isprime[i]=1;
    
    for(int i=2; i*i<=mxN; i++) {
        if(isprime[i]) {
            for(int j=i*i; j<=mxN; j=j+i) 
                isprime[j] = 0;
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++) {
        auto mp = factorize(a[i]);
        
        // print(mp);
        for(auto it = mp.begin(); it != mp.end(); it++) {
            int f = it->first;
            ppow[f] = max(ppow[f], it->second);
        }
    }
    // for(int i = 0; i < 10; i++)
    //     cout << ppow[i] << " ";
    // cout << endl;
    
    int mxl = 0, mxans = 0;

    for(int i=1; i<=m; i++) {
        int temp = 1;
        auto mp = factorize(i);

        for(auto it = mp.begin(); it != mp.end(); it++) {
            int f = it->first;
            int p = max((int)0, it->second - ppow[f]);
            for(int j=1; j<=p; j++)
                temp *= f;
        }
        if(temp > mxl) {
            mxl = temp;
            mxans = i;
        }
    }
    cout << mxans << endl;
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    sieve();
    while(t--) 
        solve();
}