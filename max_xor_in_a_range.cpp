#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;


int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        ll l, r, x, c = 1;
        cin >> l >> r;

        // finding the most significant bit that mismatches
        while(l != r)
        {   
            l = l >> 1LL;
            r = r >> 1LL;
            c = c << 1;
        }
		//set all bits after the mismatch bit to 1 in l and to 0 in r
		// take xor of both
		// the common part becomes 0000.... the rest part is ....1111
        c = c - 1; 
        cout << c << endl;
    }
}