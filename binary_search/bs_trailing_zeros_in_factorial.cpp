/*  
    Find min x such that x! contains z zeroes 
    https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Trailing 0s in x! = Count of 5s in prime factors of x!
    = floor(x/5) + floor(x/25) + floor(x/125) +
*/
// returns trailing zeroes in x!
int trailingZeros(long long int x) {
    long long int p = 5;
    int z = 0;
    while(x/p > 0) {
        z += x/p;
        p *= 5;
    }
    return z;
}

int findNum(int k) {
    // the minimum value whose factorial contain n trailing zeroes is 5*n.
    int low = 5, high = 5*k, ans = high;

    while(low <= high) {
        int mid = low + (high - low)/2;
        int z = trailingZeros(mid);
        if(z >= k) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    cout << findNum(12) << endl;
}