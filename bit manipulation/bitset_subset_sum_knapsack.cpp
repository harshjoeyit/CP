
/*
T = O(N.W/64)

original problems - given a knapsack(W) and n weights , find if sum of knapsack can be filled completely
or
find a subset with sum = W 
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
	// after this operation all every ith bit is set 
	// such that sum i is possible using the value up untill now  
        can |= (can << x);       
	// Examlpe
	// x = 2     can = ..00000000101 			         	- possible sums {2}
	// x = 3     can = ..0000000101 | ..000000101000 = ..00000101101 	- possible sums {2, 3, 5}
	// x = 4     can = ..00000101101 | ..01011010000 = ..1011111101  	- possible sums {2, 3, 5, 4, 4, 7, 9} 
	// Note: writing this way it is faster than can = can | (can << x)
    }
    puts(can[w] ? "YES" : "NO");
}
