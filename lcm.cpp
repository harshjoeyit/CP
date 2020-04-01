

// often lcm is large number -it leads to overflow
// store lcm as power of prime factors 



#include<bits/stdc++.h>
using namespace std;
const int maxn = 10009;
int n, m;
int t, cs = 1;
int ara[maxn];
vector<pair<int, int>> divs[maxn + 7];

int ppow[maxn + 7];

// void printdiv() {
//     for(int i=0; i<20; i++) {
//         cout << i << "--> ";
//         for(auto p: divs[i]) {
//             cout << "(" << p.first <<"-" << p.second <<"),  ";
//         }
//         cout << endl;
//     }
// }

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
	// cin >> t;
	sieve(maxn);
    // printdiv();
	// while(t--){
	    scanf("%d %d", &n, &m);
	    memset(ppow, 0, sizeof(ppow));

	    for(int i = 1; i <= n; i++){
	        scanf("%d", &ara[i]);
	        for(auto dv : divs[ara[i]]) 
                ppow[dv.first] = max(ppow[dv.first], dv.second);                // lcm is stored as prime power in ppow array 
	    }

	   // find max lcm on adding int [1, m] so that max lcm of the array can be formed
       
    //     int mxmLCM = 0, mxmAns = 0;

	//     for(int i = 1; i <= m; i++){

	//         int barbe = 1;
	//         for(auto dv : divs[i]){
	//             int dif = max(0, dv.second - ppow[dv.first]);
	//             for(int i = 1; i <= dif; i++) 
    //                 barbe = barbe * dv.first;
	//         }
	//         if(barbe > mxmLCM){
	//             mxmLCM = barbe;
	//             mxmAns = i;
	//         }
	//     }
	//     printf("%d\n", mxmAns);
	// }

	// return 0;
}
