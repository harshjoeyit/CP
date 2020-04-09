#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
        int N;
	    cin>>N;
	    int *A = new int [N];
	    for(int i=0; i<N; i++)
	    {
	        cin>>A[i];
	    }
	    int *lmin = new int[N];
	    lmin[0] = 0;
	    for(int i=1; i<N; i++)
	    {
	        lmin[i] = A[i] < A[lmin[i-1]] ? i : lmin[i-1];
	    }
	    int *rmax = new int[N];
	    rmax[N-1] = N-1;
	    for(int i=N-1; i>0; i--)
	    {
	        rmax[i-1] = A[i-1] > A[rmax[i]] ? i-1 : rmax[i];
	    }
	    int diff = 0;
	    for(int i=0, j=0; i<N && j<N;)
	    {
	        if(A[lmin[i]] < A[rmax[j]])				// change condition accordingly here (a[i] < a[j])  could be (a[i] <= a[j])
	        {
	            diff = max(diff, j-i);
	            j++;
	        }
	        else
	        {
	            i++;
	        }
	    }
	    cout<<diff<<endl;
	    delete []A;
	    delete []lmin;
	    delete []rmax;
}

signed main() 
{
	int T;
	cin>>T;
	while(T--)
        solve();
}