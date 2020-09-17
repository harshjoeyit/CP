
/*
finding median or 
sum of middle elements 

for 2 sorted array of size n
*/


#include<bits/stdc++.h>
using namespace std;

int median(int a[], int n);


int getMedian(int a[], int b[], int n) {

    if(n <= 0) {
        return -1;
    }
    // 2 elements only 
    if(n == 1) {
        // returning sum
        return (a[0] + b[0]);
    }
    // 4 elements remaining
    if(n == 2) {
        // returning sum rather than median, for undestanding
        return (max(a[0], b[0]) + min(a[1], b[1]));
    }
    
    int ma = median(a, n);  
    int mb = median(b, n);

    if(ma < mb) {
        // median is in later part of a and earlier part of b
        if(n%2 == 0) {
            return getMedian(a+n/2-1, b, n-n/2+1);
        }
        // for odd n, pass the middle element for next interation
        return getMedian(a+n/2, b, n-n/2);
    }

    // ma >= mb
    // median is in later part of b and earliar part of a
    if(n%2 == 0) {
        return getMedian(b +n/2-1, a, n-n/2+1);
    }
    // for odd n, pass the middle element for next interation
    return getMedian(b+n/2, a, n-n/2);
}


int median(int a[], int n) {
    if(n%2 == 0)
        return (a[n/2]+a[n/2-1])/2;

    return a[n/2];
}

int main() {
    int a[] = {1,11,13,16,19}; 
    int b[] = {4,7,10,12,20}; 

    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);

    if (n1 == n2) 
        cout << "Median is "
             << getMedian(a, b, n1); 
    else
        cout << "Doesn't work for arrays " 
             << "of unequal size"; 
    
}