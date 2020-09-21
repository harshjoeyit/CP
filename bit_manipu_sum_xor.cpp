
/*
Given Xor and Sum of n numbers 
find the n numbers, n should be minimum

https://hack.codingblocks.com/app/contests/1783/1759/problem
*/


/*
Important property 

a + b = a ^ b + 2(a & b)

- conclusions 
      - if xor is odd, sum is odd
      - if xor is even, sum is even 
      - xor <= sum

Our ans array can have 3 nums at max 
since 
      if sum, xor = even 
            sum = xor + w + w
      if sum, xor = odd
            sum = xor + u + u
      
      for some w, u

CASE 1. (invalid cases) 
      xor <= sum || different types of sum and xor

CASE 2. 
      xor == sum 
      ans = xor, only 1 number in array 

CASE 3.
      xor < sum
      SUBCASE 1. array has two nums only 
      SUBCASE 2. array has three nums 
            - 
*/

#include <iostream>
using namespace std;
#define int long long


signed main() {
    int xr, sum;
    cin >> xr >> sum;
    if(xr > sum || ((xr%2 == 0) && (sum%2 == 1)) || ((xr%2 == 1) && (sum%2 == 0))) {
        cout << abs(xr - sum) << "\n";
        return 0;
    }

    if(xr == sum) {
        cout << "1\n";
        cout << xr << "\n";
        return 0;
    }

    int a = (sum - xr) / 2;
    if((a & xr) == 0) {
        cout << "2\n";
        cout << min(a, a + xr) << " " << max(a, a + xr) << "\n";
    } else {
        cout << "3\n";
        if(a < xr) {
            cout << a << " " << a << " " << xr << endl;
        } else {
            cout << xr << " " << a << " " << a << endl;
         }
    }
}