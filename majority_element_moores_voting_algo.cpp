#include<bits/stdc++.h>
using namespace std;

#define int long long 

int findCandidate(int a[], int size)  {              /* Function to find the candidate for Majority */ 
	int maj_index = 0, count = 1; 
	for (int i = 1; i < size; i++) { 
		if (a[maj_index] == a[i]) 
			count++; 
		else
			count--; 
		if (count == 0) { 
			maj_index = i; 
			count = 1; 
		} 
	} 
	return a[maj_index]; 
} 

bool isMajority(int a[], int size, int cand) {      /* Function to check if the candidate 
                                                        occurs more than n/2 times */
	int count = 0; 
	for (int i = 0; i < size; i++) 
	
	if (a[i] == cand) 
	    count++; 
	if (count > size/2) 
	    return 1; 
	else
	    return 0; 
} 

/* Function to print Majority Element */
void printMajority(int a[], int size) 
{ 
    /* Find the candidate for Majority*/
    int cand = findCandidate(a, size); 

    /* Print the candidate if it is Majority*/
    if (isMajority(a, size, cand)) 
        cout << cand <<"\n"; 
    else
        cout << "-1\n"; 
} 

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    printMajority(a, n);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}