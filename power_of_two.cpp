#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;

    while(n > 1)
    {
        if( (n & 1) == 0)
            n = n >> 1;
        else
            break;
    }

    if(n > 1)
        cout << "not" << endl;
    else
        cout << "power" << endl;


    /*
    int m = n-1;
    if((m & n) == 0 && n != 0)       n = ...00010000....   m = ....000001111
        cout << "YES\n";
    else
        cout << "NO\n";
    */



   /*
        Compute the biggest power of 2 that is a divisor of x. Example: f(12) = 4

        1 << __builtin_ctz(x)



        Compute the smallest power of 2 that is not smaller than x. Example: f(12) = 16

        1 << (32 - __builtin_clz (x - 1))
   */
}