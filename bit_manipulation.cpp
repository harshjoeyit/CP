
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

    cout << b << "\n";

    // unset the ith bit, let i = 1
    i = 1;
    b = b & (~(i << i));

    cout << b << "\n";

    // check if the ith bit is set 
    i = 3;
    if(b & (1 << i) > 0) {
        cout << i << "bit is set \n";
    } else 
        cout << i << "bit is not set\n";
    

    // toggle status of bit at pos j
    // b = b ^ (1 << j)


    // value of least significant bit from left 
    // v = (b & (~b))


    // turn on all bits    of set of size n
    // b = (1 << n) - 1;




    
    /*
    ------------------------------------------------------------------------------------------------------- 


    SUBSET PROBLEMS -



    Iterate through all subsets of a subset y (not including empty set):
           for ( x = b; x > 0; x = ( b & (x-1) ) )




        for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {    // for each subset, O(2^n)
                 for ( int j = 0; j < n ; ++ j ) {       // check membership, O(n)
                     i f ( ( i & ( 1 << j ) ) ! = 0 )    // test if bit ‘j’ is turned on in subset ‘i’?
                          results[i] += s [j] ;          // if yes, process ‘j’
                     }
                 }
           }
    */

}