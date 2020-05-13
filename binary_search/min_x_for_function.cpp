
/*
least value of x for which
a*x^3 + b*x + c > d

for using binary search the function should unoformly increase of decrease 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int low = -100000;
    int high = 100000;
    long long int mid, value, ans = -1;

    while(low <= high)
    {
        mid = low + (high-low)/2;
        value = mid*mid*mid + 12*mid + 1;

        if( value > 100)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }    
    cout << ans << endl;
}