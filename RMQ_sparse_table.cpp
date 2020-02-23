#include<bits/stdc++.h>
using namespace std;

#define MAX 500
int lookup[MAX][MAX];

void preprocess(int arr[], int n)
{
    // for intervals starting at every index and having length(basically the element at index only)
    for (int i = 0; i < n; i++) 
        lookup[i][0] = i; 
    
    // incresing the interval size(2^j) from 2..4..8.
    for (int j=1; (1<<j) <= n; j++) 
    {
        // setting the boundary - max index from where the interval of length 2^j can start off 
        for (int i=0; (i+(1<<j)-1) < n; i++) 
        {
            int indx1 = lookup[i][j-1];
            int indx2 = lookup[i + (1<<(j-1))][j-1];
            if (arr[indx1] < arr[indx2]) 
                lookup[i][j] = indx1; 
            else
                lookup[i][j] = indx2;
        }
    }
}


int query(int arr[], int L, int R) 
{ 
    // 2^j is the interval length
    int j = (int)log2(R-L+1); 
  
    // For [2,10], we compare arr[lookup[0][3]] and 
    // arr[lookup[3][3]],  
    int indx1 = lookup[L][j];               // interval1 - starts at l and has max interval size possible such interval is within L-R
    int indx2 = lookup[R - (1<<j) + 1][j];  // interval2 - ends at R and starting position is manipulated to make it end at R - has same interval size as interval1 
    if (arr[indx1] <= arr[indx2])
        return arr[indx1]; 
  
   else return arr[indx2]; 
}


void RMQ(int arr[], int n, int m) 
{ 
    preprocess(arr, n); 
    for (int i=0; i<m; i++) 
    { 
        int L, R;
        cin >> L >> R;
        cout << "Minimum of [" << L << ", "
             << R << "] is "  << query(arr, L, R) << endl; 
    } 
} 


int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    RMQ(arr, n, m);
}