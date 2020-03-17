#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main(){
	int n = 5; 
    printf("Count of 1s in binary of %lld is %d]\n", 
           n, __builtin_popcountll(n)); 
	
	printf("Parity of %d is %d\n", 
           n, __builtin_parityll(n)); 

	n = 16; 
      
    printf("Count of leading zeros before 1 in %d is %d\n", 
           n, __builtin_clz(n));
}