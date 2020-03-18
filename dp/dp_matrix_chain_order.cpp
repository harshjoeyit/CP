#include<bits/stdc++.h> 
using namespace std; 

// Matrix Ai has dimension p[i-1] x p[i] 
// for i = 1..n 
int MatrixChainOrder(int p[], int i, int j) 
{ 
	if(i == j)              // sungle matrix - 0 operations 
		return 0; 
	int k; 
	int min = INT_MAX; 
	int count; 

	// place parenthesis at different places 
	// between first and last matrix, recursively 
	// calculate count of multiplications for 
	// each parenthesis placement and return the 
	// minimum count 
	for (k = i; k < j; k++)             // left matrix - taking product of first k matrix recursively + 
                                        // right matrix - product of k+1 tp n-1 matrix recursively + 
	{                                   //  p[i - 1] * p[k] * p[j] operation for left and right matrix formed currently
		count = MatrixChainOrder(p, i, k) + 
				MatrixChainOrder(p, k + 1, j) + 
				p[i - 1] * p[k] * p[j]; 

		if (count < min) 
			min = count; 
	} 
	// Return minimum count 
	return min; 
} 



int MatrixChainOrder_dp(int p[], int n) 
{ 
  
    /* For simplicity of the program, one  
    extra row and one extra column are  
    allocated in m[][]. 0th row and 0th 
    column of m[][] are not used */
    int m[n][n]; 
  
    int i, j, k, L, q; 
  
    /* m[i,j] = Minimum number of scalar  
    multiplications needed to compute the 
    matrix A[i]A[i+1]...A[j] = A[i..j] where 
    dimension of A[i] is p[i-1] x p[i] */
  
    // cost is zero when multiplying 
    // one matrix. 

    for (i = 1; i < n; i++)                     // all single matrices have zero operations
        m[i][i] = 0; 
  
    // L is chain length.                       // for array of size n there are n - 1 total matrices 
    for (L = 2; L < n; L++)                     // L = number of matrix multplied L = 2 - all pairs, L = 3 - all triplets, L = 4 ... 
    {                   
        cout << "L: " << L << endl;

        for (i = 1; i < n - L + 1; i++)        // i = starting matrix number 
        { 
             j = i + L - 1;                    // j = ending matrix number + 1    
            m[i][j] = INT_MAX;                                                  // i and j decide the range of the matrices to be multiplied 
            cout <<"i: "<<i << endl;
            cout <<"j: "<< j << endl;
            for (k = i; k <= j - 1; k++)        // k works as intermediate matrix number 1...k * k+1...j
            { 
                cout << i << "-" << k << "*" << k+1 << "-" << j << endl; 
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k + 1][j] +  
                    p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1];                 // represents the product of matrix - [1.2.3.4.....n-1]
} 



// Driver Code 
int main() 
{ 
    // matrices are - n-1 for size n of the array 
            // [1*2], [2*3], [3*4], [4*3]
	int p[] = {1, 2, 3, 4, 3}; 
	int n = sizeof(p)/sizeof(p[0]); 

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(p, 1, n - 1) << endl; 

    
	cout << "Minimum number of multiplications is \n"
		<< MatrixChainOrder_dp(p, n) << endl;
} 

 
