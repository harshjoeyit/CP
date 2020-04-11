/*

INCLUSION - EXCLUSION principal

A union B = A + B - A intersection B
A union B union C = A + B + C - (A inter B) -(B inter C) - (C inter A) + (A inter B inter C)

INCLUSION - all the values added are said to be included
EXCLUSION - all the values subtracted are said to be excluded

The numbers that are formed by multiplication of an odd number of prime
numbers will be added and the numbers formed by multiplication of even numbers 
will thus be subtracted to get the total number of multiples in the range 1 to M.
*/

#include <bits/stdc++.h> 
using namespace std; 


// count the  
// number of numbers in range  
// 1-M that are divisible by  
// given N prime numbers 

int count(int a[], int m, int n) 
{ 
    int odd = 0, even = 0;    
  
    // Run from counter 000..0 to 111..1 
    for(int counter = 1; counter < (1 << n);  counter++) { 
        int p = 1; 
        for (int j = 0; j < n; j++) 
            if (counter & (1 << j))                         // if jth bit is set - we are dealing with jth prime in the a[]
                p *= a[j]; 
        
        if (__builtin_popcount(counter) & 1)                // INCLUSION - for odd set bits - prime numbers multiplied odd number of times 2, 2*3*5, 5*7*11*13*17,..... 
            odd += ( m / p );                                  
        else                                                // EXCLUSION - for prime number multiplied even number of times - 2, 2*3, 2*3*5*7 ..... 
            even += ( m / p ); 
    } 
    return odd - even; 
} 

int main() 
{ 
    int a[] = {2, 3, 5}; 
    int m = 10; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << count(a, m, n) << endl; 
    return 0; 
} 