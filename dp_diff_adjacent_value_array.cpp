
/*
given n, k, x
construct an array with no adjacent values same

n - size 
1 <= a[i] <= k
a[n-1] = x
a[0] = x

find total possible arrays
*/

const int MOD = 1000000007;

long countArray (int n, int k, int x) 
{
   vector<long long> b (n), a (n);              // b[i] - total number of arrays ending in x at i
                                                // a[i] - total number of arrays not ending in x at i
   a[0] = x == 1 ? 1 : 0; // ends in x
   b[0] = x == 1 ? 0 : 1; // doesn't end in x
   
   for (int i = 1; i < n; ++i) {
      a[i] = b[i - 1] % MOD;
      b[i] = (a[i - 1] * (k - 1) + b[i - 1] * (k - 2)) % MOD;
   }

   return a[n - 1];
}