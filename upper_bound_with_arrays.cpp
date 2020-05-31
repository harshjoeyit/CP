// CPP program to illustrate using 
// std :: lower_bound with arrays and upper_bound
#include <bits/stdc++.h> 
using namespace std; 

// Main Function 
int main() 
{ 
	int arr[] = { 10, 20, 30, 40, 50 }; 

	// Print elements of array 
	cout << "Array contains :"; 
	for (int i = 0; i < 5; i++) 
		cout << " " << arr[i]; 
	cout << "\n"; 

	// using lower_bound 
	int lower1 = lower_bound(arr, arr+5, 55) - arr; 
	int lower2 = lower_bound(arr, arr+5, 5) - arr; 

	cout << "\nlower_bound for element 55 is at position : "
			<< (lower1); 
	cout << "\nlower_bound for element 5 is at position : "
			<< (lower2); 

	// using upper_bound 
	int upper1 = upper_bound(arr, arr+5, 55) - arr; 
	int upper2 = upper_bound(arr, arr+5, 5) - arr; 

	cout << "\nupper_bound for element 55 is at position : "
			<< (upper1); 
	cout << "\nupper_bound for element 5 is at position : "
			<< (upper2); 

	return 0; 
} 
