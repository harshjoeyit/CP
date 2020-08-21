// CPP program to illustrate using 
// std :: lower_bound with arrays and upper_bound
#include <bits/stdc++.h> 
using namespace std; 

// Main Function 
int main() 
{ 
	int arr[] = { 10, 20, 30, 40, 50 }; 

	// using lower_bound 
	int lower1 = lower_bound(arr, arr+5, 55) - arr; 
	int lower2 = lower_bound(arr, arr+5, 5) - arr; 

	cout << "\nlower_bound 55 pos : "
			<< (lower1); 
	cout << "\nlower_bound 5 pos : "
			<< (lower2); 

	// using upper_bound 
	int upper1 = upper_bound(arr, arr+5, 55) - arr; 
	int upper2 = upper_bound(arr, arr+5, 5) - arr; 

	cout << "\nupper_bound 55 pos : "
			<< (upper1); 
	cout << "\nupper_bound 5 pos : "
			<< (upper2);


			
	// using lower_bound 
	lower1 = lower_bound(arr, arr+5, 25) - arr; 
	lower2 = lower_bound(arr, arr+5, 30) - arr; 

	cout << "\nlower_bound 25 pos : "
			<< (lower1); 
	cout << "\nlower_bound 30 pos : "
			<< (lower2); 

	// using upper_bound 
	upper1 = upper_bound(arr, arr+5, 25) - arr; 
	upper2 = upper_bound(arr, arr+5, 30) - arr; 

	cout << "\nupper_bound 25 pos: "
			<< (upper1); 
	cout << "\nupper_bound 30 pos : "
			<< (upper2); 
} 
