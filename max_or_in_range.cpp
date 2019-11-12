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

        // finding the most significant bit that mismatches B
        while(l != r)
        {   
            l = l >> 1LL;
            r = r >> 1LL;
            c = c << 1;
        }
        l = l*c;
        c = c - 1;
        
        l = l | c; 
        cout << l << endl;
        
    }
}