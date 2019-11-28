#include <bits/stdc++.h> 
using namespace std; 

/* For a given array arr[], 
returns the maximum j – i such that 
arr[j] > arr[i] */

/*

explanation for the solution 

let an array be  2, 4, 1, 0, 5, 1, 3 

here if consider 4 and find max j - i i.e. for 4 and 3
this j - i will still be smaller then  max j - 1 for 2 & 3
because for 4 there still exists a number less than 4 and it would always give the distance j - i greater than whatever is given by 4 
simply, if 4 can be a starting point , then 2 can be even a better starting point 
so the starting points jave to be chosen in the decreasing order fashion 

same goes for the ending points 

max j - i for 1 & 1  will always be less than max of 1 & 3 
simply if 1 can be an ending point then 3 can be a better ending point 

*/
int maxIndexDiff(int arr[], int n) 
{ 
	int maxDiff; 
	int i, j; 

	int *LMin = new int[(sizeof(int) * n)]; 
	int *RMax = new int[(sizeof(int) * n)]; 

	// this array contains all the possible starting points for indexes
	LMin[0] = arr[0]; 
	for (i = 1; i < n; ++i) 
		LMin[i] = min(arr[i], LMin[i - 1]); 			// imp

	// we work backwards in increasing order
	RMax[n - 1] = arr[n - 1]; 								// this array contains all the possible ending points
	for (j = n - 2; j >= 0; --j) 
		RMax[j] = max(arr[j], RMax[j + 1]); 

	/* Traverse both arrays from left to right 
	to find optimum j - i. This process is similar to 
	merge() of MergeSort */

	i = 0, j = 0, maxDiff = -1; 
	
	for(int i = 0; i < n; i++)
		cout << LMin[i] << " ";
	cout << endl;

	for(int i = 0; i < n; i++)
		cout << RMax[i] << " ";
	cout << endl;

	while (j < n && i < n) 
	{ 
		if (LMin[i] < RMax[j]) 
		{ 
			maxDiff = max(maxDiff, j - i); 
			j = j + 1; 
		} 
		else
			i = i + 1; 
	} 

	return maxDiff; 
} 

 
int main() 
{ 
	int arr[] = //{6,5,4,3,2,1};
	{5, 5, 3, 4, 5, 1, 4, 3, 2, 0}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int maxDiff = maxIndexDiff(arr, n); 
	cout << maxDiff; 
	return 0; 
} 

// This code is contributed by rathbhupendra 
