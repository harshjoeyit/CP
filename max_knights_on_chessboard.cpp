
/*
Find maximum number of knights(ghoda) that can be placed on the given 
chessboard such that no two knights attack each other 

Logic: knight always attcks the opposite colored block

https://www.geeksforgeeks.org/maximum-non-attacking-knights-that-can-be-placed-on-an-nm-chessboard/
*/


#include <bits/stdc++.h> 
using namespace std; 

int max_knight(int n, int m) { 

	// Check for corner case #1 
	// If row or column is 1 
	if (m == 1 || n == 1) {             // every block is valid position
		return max(m, n); 
	} 

	// Check for corner case #2 
	// If row or column is 2 
	else if (m == 2 || n == 2) { 

		// If yes, then simply calculate 
		// consecutive 2 rows or columns 
		int c = 0; 
		c = (max(m, n) / 4) * 4; 

		if (max(m, n) % 4 == 1) { 
			c += 2; 
		} 
		else if (max(m, n) % 4 > 1) { 
			c += 4; 
		} 
		return c; 
	} 

	// For general case, just print the 
	// half of total blocks 
	else {                                      // for 3*3 ans = 5 not 4, generally the max(black, white) blocks
		return (((m * n) + 1) / 2); 
	} 
} 

// Driver code 
int main() 
{ 
	int n = 4, m = 5; 

	cout << max_knight(n, m); 

	return 0; 
} 
