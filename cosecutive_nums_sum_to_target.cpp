
#include<bits/stdc++.h>
using namespace std;

/*
The idea is to represent N as a sequence of length L+1 as:
N = a + (a+1) + (a+2) + .. + (a+L)
=> N = (L+1)*a + (L*(L+1))/2
=> a = (N- L*(L+1)/2)/(L+1)
We substitute the values of L starting from 1 till L*(L+1)/2 < N
If we get 'a' as a natural number then the solution should be counted.
*/

long int countConsecutive(long int N) {
    // constraint on values of L gives us the 
    // time Complexity as O(N^0.5)
    long int count = 0;

    // since question asks use to find only those sequences 
    // where 2 or more numbers sum up to N
    // we can modify L, to start from any location we want, (see how series goes with L)
    // if L starts from 1 then there are at least 2 consecutive numbers that sum to N

    // if L starts from 2 that means 3 or more consecutive values sum up to N
    // if L starts from 0 that means 1 or more consecutive values sum op to N

    for (long int L = 1; L * (L + 1) < 2 * N; L++) {
        float a = (1.0 * N - (L*(L + 1)) / 2) / (L + 1);
        if (a - (int)a == 0.0) 
            count++;        
    }
    return count;
}

int main() {
    cout << countConsecutive(15);
}