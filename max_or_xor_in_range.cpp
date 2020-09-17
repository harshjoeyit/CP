#include<bits/stdc++.h>
using namespace std;

// max And in range 
int maxAND(int L, int R) { 

	if(R - L >= 1) {
		// for 1 or 2 numbers only
		return L & R;
	} else { 
		return (R - ( 2 - R % 2));
		
		// OR observe the pattern
		
		// if (((R - 1) & R) > ((R - 2) & (R - 1))) 
		// 	return ((R - 1) & R); 
		// else
		// 	return ((R - 2) & (R - 1));
	}
} 

int main(){
    
    int l, r, x, c = 1;
    cin >> l >> r;
    // finding the most significant bit that mismatches B
    while(l != r) {   
        l = l >> 1LL;
        r = r >> 1LL;
        c = c << 1;
    }

    // max xor 
    // possible b/w two numbers [l, r]
    int maxXor = c - 1;

    l = l*c;
    c = c - 1;
    
    // max or 
    // possible b/w two numbers [l, r]
    int maxOr = l | c;     
}