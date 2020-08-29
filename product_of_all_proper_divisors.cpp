
/*
      Sum of product of proper divisors of all Numbers lying in range [L, R]
*/

#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 10;
const int mod = 1e9 + 7;
vector<int> ans(mxN, 1);

void productOfProperDivisors() {
      // ans[i] = product of proper divisors of i
      for (int i = 2; i < mxN / 2; i++) {
            for (int j = 2 * i; j < mxN; j = j + i) {
                  ans[j] = (ans[j] * i) % mod;
            }
      }
      // for queries 
      // Sum of product of proper divisors of all Numbers lying in range [L, R]
      // do the prefix sum 
      // and ans for query = ans[R] - ans[L-1]
}

int main() {
      productOfProperDivisors();
}