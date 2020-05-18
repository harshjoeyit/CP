
/*
Blog on bits
https://codeforces.com/blog/entry/73558
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    

    /*
        BASIC BIT MANIPULATIoN
    */
    int b = 26; // ...011010

    // set ith bit, let i = 0
    int i = 0;
    b = b | (1 << i);

    
    // unset the ith bit, let i = 1
    i = 1;
    b = b & (~(i << i));


    // check if the ith bit is set 
    (b & (1 << i) > 0)
    

    // toggle status of bit at pos j
    b = b ^ (1 << j)


    // first set bit from right
    bit = b & (-b);


    // turn on all bits of set of size n
    b = (1 << n) - 1;


    //  count of 1s in the binary of n
     __builtin_popcountll(n); 
	
	//  parity
    __builtin_parityll(n); 

	n = 16; 
      
    // leading zeroes 
    __builtin_clz(n)
    /*
    ------------------------------------------------------------------------------------------------------- 


    SUBSET PROBLEMS -



    Iterate through all subsets of a subset y (not including empty set):
           for ( x = b; x > 0; x = ( b & (x-1) ) )




        for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {       // for each subset, O(2^n)
                 for ( int j = 0; j < n ; ++ j ) {       // check membership, O(n)
                     i f ( ( i & ( 1 << j ) ) ! = 0 )    // test if bit ‘j’ is turned on in subset ‘i’?
                          results[i] += s [j] ;          // if yes, process ‘j’
                     }
                 }
           }
    */

}