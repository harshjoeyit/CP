
/*
    https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1

    We have to perform exactly k negetion operations on any element of our choice
    Find the maximum sum after ops are performed.
*/

#include<bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int a[], int n, int k) {
    // Your code goes here
    sort(a, a + n);
    int i = 0; 
    while(i < n && k > 0 && a[i] < 0) {
        a[i] = -a[i];
        i++, k--;
    }
    long long int s = accumulate(a, a+n, 0LL);
    long long int mn = *min_element(a, a+n);
    // we have used up all k operations 
    if(k == 0) {
        return s;
    }

    // k remains i.e. all elements are positive in array, so use remaining operation
    // single element (minimum element)
    if(k % 2 == 0) {
        return s;
    } else {
        return s -2*a[i];
    }
}

int main() {
      long long int a[] = {}
}