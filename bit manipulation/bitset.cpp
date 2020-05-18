#include<bits/stdc++.h>
using namespace std;

int main() {

    bitset<32> b1(23);
    b1[10] = 1;
    cout << b1 << endl;

    bitset<10> b2("000101");
    cout << b2 << endl;

    cout << b1.count() << endl;
    
    // b[i] - same as b.test(i)

    // b.any() - true if atlest 1 bit is set, else false
    // b.none() - true if none bit set

    b1[0] = !b1[0];
    // or b1.flip(0);
    cout << b1 << endl;

    bitset<32> b3(7), b4(15);
    cout << (b3^b4) << endl;





    // -------------------------------------------------------------------------------------------------------------
    // Applications

    // count unique int in an array N <= 1e7, a[i] <= 1e9
    const int sz = 1e7+1;
    bitset<sz> visited;

    int a[] = {3, 4, 3, 5, 6, 4, 2, 2, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);

    for(int i=0; i<n; i++)
        visited[a[i]] = 1;
    
    cout << visited.count() << endl;



    //----------------------------------------------------------------------------------------------------------------


    /*
    You are given N ≤ 1000 items, each with some weight wi. 
    Is there a subset of items with total weight exactly W ≤ 1e6?
 
                            bool[mxW];
    int n, W;
	cin >> n >> W;
    can[0] = true;
	
    for(int id = 0; id < n; id++) {             // n times
		int x;
		cin >> x;
		for(int i = W; i >= x; i--) {           // w times
			if(can[i-x]) can[i] = true;
		}
	}
	puts(can[W] ? "YES" : "NO");


    //                                          solution complexity - O(N.W)





                            bitset<mxW> can;
    int n, W;
	cin >> n >> W;
	can[0] = true;

	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		can = can | (can << x);             // since 1 is at c[0], so if we want to set xth bit we do this
	}
	puts(can[W] ? "YES" : "NO");

    // solution complexity                          O(N.W/64) or O(N.W/32)  based on architecture   
    */
}