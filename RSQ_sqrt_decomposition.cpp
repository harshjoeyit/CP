#include<bits/stdc++.h>
using namespace std; 

#define MAXN 10000 
#define SQRSIZE 100 

int arr[MAXN];			 // original array 
int block[SQRSIZE];		 // decomposed array 
int blk_sz;					 // block size 

// Time Complexity : O(1) 
void update(int idx, int val) 
{ 
	int blockNumber = idx / blk_sz; 
	block[blockNumber] += val - arr[idx]; 
	arr[idx] = val; 
} 

// Time Complexity : O(sqrt(n)) 
int query(int l, int r) 
{ 
	int sum = 0; 
	while (l<r and l%blk_sz!=0 and l!=0) 
	{ 
		// traversing first block in range 
		sum += arr[l]; 
		l++; 
	} 
	while (l+blk_sz <= r) 
	{ 
		// traversing completely overlapped blocks in range 
		sum += block[l/blk_sz]; 
		l += blk_sz; 
	} 
	while (l<=r) 
	{ 
		// traversing last block in range 
		sum += arr[l]; 
		l++; 
	} 
	return sum; 
} 



void preprocess(int input[], int n) 
{ 
	int blk_idx = -1; 
	blk_sz = sqrt(n); 

	for (int i=0; i<n; i++) 
	{ 
		arr[i] = input[i]; 
		if (i%blk_sz == 0)
			blk_idx++; 

		block[blk_idx] += arr[i]; 
	} 
} 


int main() 
{ 
    int n;
    cin >> n;

	int input[n];
	for(int i = 0; i < n; i++)
        cin >> input[i];

    for(int i = 0; i < n; i++)
        cout << input[i] << " ";
    cout << endl;

	preprocess(input, n); 

    int q;
	cin >> q;
    while(q--)
    {
        int type, l, r, idx, val;
        cin >> type;
        if(type == 1)
        {
            cin >> idx >> val;
            update(idx, val);
        }
        else
        {
            cin >> l >> r;
            cout << "sum : " << query(l, r) << endl;
        }

    }
} 