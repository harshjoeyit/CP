// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the maximum bitwise AND 
// possible among all the possible pairs 
int maxAND(int L, int R) 
{ 

	// If there is only a single value 
	// in the range [L, R] 
	if (L == R) 
		return L; 

	// If there are only two values 
	// in the range [L, R] 
	else if ((R - L) == 1) 
		return (R & L); 
	else { 
		if (((R - 1) & R) > ((R - 2) & (R - 1))) 
			return ((R - 1) & R); 
		else
			return ((R - 2) & (R - 1)); 
	} 
} 

// Driver code 
int main() 
{ 
	int L = 1, R = 632; 
	cout << maxAND(L, R); 

	return 0; 
} 
