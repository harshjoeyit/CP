
/*
given n, k, x
construct an array with no adjacent values same

n - size 
1 <= a[i] <= k
a[n-1] = x
a[0] = 1

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
      a[i] = b[i - 1] % MOD;        // if a seq at i-1 did not end in x - it can end at x at i
      b[i] = (a[i - 1] * (k - 1) + b[i - 1] * (k - 2)) % MOD;
      //  if a seq at i-1 end in x - then there are k-1 numbers that can come at i (excluding the i-1th number) + 
      // if a seq end in some other than x then there are k-2 possiblities as (exclude x and i-1th number)
   }

   return a[n - 1];
}