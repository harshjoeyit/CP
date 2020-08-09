// C++ program to find Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;

int maxProduct(int A[], int n) {
	if (n == 0)
		return 0;
	int maxProduct = A[0];
	int minProduct = A[0];
	int maxRes = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] >= 0) {
			maxProduct = max(maxProduct * A[i], A[i]);
			minProduct = min(minProduct * A[i], A[i]);
		} else {
			int temp = maxProduct;
			maxProduct = max(minProduct * A[i], A[i]);
			minProduct = min(temp * A[i], A[i]);
		}
		maxRes = max(maxRes, maxProduct);
	}
	return maxRes;
}

// Driver code
int main()
{
}
