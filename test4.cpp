#include <bits/stdc++.h> 
using namespace std; 

int* ans = NULL; 

void countSieve(int arr[], int n) 
{ 
	int MAX = *max_element(arr, arr + n); 
	int cnt[MAX + 1]; 

	ans = new int[MAX + 1]; 
 
	memset(cnt, 0, sizeof(cnt)); 
	memset(ans, 0, (MAX + 1) * sizeof(int)); 

	for (int i = 0; i < n; ++i) 
		++cnt[arr[i]]; 
 
	for (int i = 1; i <= MAX; ++i) 
		for (int j = i; j <= MAX; j += i) 
			ans[i] += cnt[j]; 
	return; 
} 

int countMultiples(int k) 
{ 
	
	return ans[k]; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2 ,2 ,3 ,3 ,3 ,4 ,6 ,6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// pre-calculate all multiples 
	countSieve(arr, n); 

	for(int i=0; i<n; i++) {
        cout << countMultiples(arr[i]) << " ";
    }
} 
