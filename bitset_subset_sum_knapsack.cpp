

/*
T = O(N.W/64)

problems - 

knapsack - n weights , find if sum of W can be made
or

subset sum -n array values , find if any subset sum = W 

*/


/*
using a bool array

bool can[MAX_W];

int main() {
	int n, W;
	cin >> n >> W;
	can[0] = true;
	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		for(int i = W; i >= x; i--) {
			if(can[i-x]) can[i] = true;
		}
	}
	puts(can[W] ? "YES" : "NO");
}
*/


#include<bits/stdc++.h>
using namespace std;

bitset<1000001> can;

int main() {
    int w, n;                   // n <= 1000, w < 1000000
    cin >> n >> w;

    can[0] = 1;                   // 0 wieght is always possible 
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        can |= (can << x);       // set the xth bit	- faster than can = can | (can << x)
    }
    puts(can[w] ? "YES" : "NO");
}
