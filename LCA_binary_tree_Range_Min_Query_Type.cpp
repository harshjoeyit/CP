#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n;
int euler[2*N -1];
int level[2*N -1];
int firstOcc[N+1];
int vis[N+1];
vector<int> G[N+1];

// dfs - euler tour, level of every node.


void eulerTree(int u, int &indx, int lev) 
{ 
    vis[u] = 1; 
    level[indx] = lev;                          // filling up the level array at each index
    euler[indx++] = u; 
    for(auto v : G[u]) 
    { 
        if (!vis[v]) 
        { 
            eulerTree(v, indx, lev+1);          // calling recursive on one of the subtress of u
            level[indx] = lev;
            euler[indx++] = u;                  // after call the path comes back to the parent node so print again 
        }                                       // any parent node is printed 1+number of children times 
    } 
}

void findFirstOcc()
{
    memset(firstOcc, -1, sizeof(firstOcc));
    for(int i=0; i < 2*n-1; i++)
    {
        int v = euler[i];
        if(firstOcc[v] == -1)
            firstOcc[v] = i;
    }
}



// log base 2 of x 
int Log2(int x) 
{ 
    int ans = 0 ; 
    while (x>>=1) ans++; 
    return ans ; 
} 


/*  A recursive function to get the minimum value in a given range 
     of array indexes. The following are parameters for this function. 
  
    st    --> Pointer to segment tree 
    index --> Index of current node in the segment tree. Initially 
              0 is passed as root is always at index 0 
    ss & se  --> Starting and ending indexes of the segment represented 
                  by current node, i.e., st[index] 
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtil(int index, int ss, int se, int qs, int qe, int *st) 
{ 
    // If segment of this node is a part of given range, then return 
    //  the min of the segment 
    if (qs <= ss && qe >= se) 
        return st[index]; 
  
    // If segment of this node is outside the given range 
    else if (se < qs || ss > qe) 
        return -1; 
  
    // If a part of this segment overlaps with the given range 
    int mid = (ss + se)/2; 
  
    int q1 = RMQUtil(2*index+1, ss, mid, qs, qe, st); 
    int q2 = RMQUtil(2*index+2, mid+1, se, qs, qe, st); 
  
    if (q1==-1) return q2; 
  
    else if (q2==-1) return q1; 
  
    return (level[q1] < level[q2]) ? q1 : q2; 
} 


// Return minimum of elements in range from index qs (query start) to 
// qe (query end).  It mainly uses RMQUtil() 
int RMQ(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return RMQUtil(0, 0, n-1, qs, qe, st); 
} 
  


// A recursive function that constructs Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
void constructSTUtil(int si, int ss, int se, int arr[], int *st) 
{ 
    // If there is one element in array, store it in current node of 
    // segment tree and return 
    if (ss == se)
        st[si] = ss; 
  
    else
    { 
        int mid = (ss + se)/2; 
        constructSTUtil(si*2+1, ss, mid, arr, st);          // 0 index based tree constructed
        constructSTUtil(si*2+2, mid+1, se, arr, st); 
  
        if (arr[st[2*si+1]] < arr[st[2*si+2]]) 
            st[si] = st[2*si+1]; 
        else
            st[si] = st[2*si+2]; 
        // st[si] = min(st[2*si+1], st[2*si+2]);
    } 
} 



int *constructST(int arr[], int n) 
{ 
    // Height of segment tree 
    int x = Log2(n)+1; 
    // Maximum size of segment tree 
    int max_size = 2*(1<<x) - 1;  //  2*pow(2,x) -1 
  
    int *st = new int[max_size]; 
  
    constructSTUtil(0, 0, n-1, arr, st);        // Fill the allocated memory st 

    return st;              // Return the constructed segment tree 
} 


// Returns LCA of nodes n1, n2 (assuming they are 
//  present in the tree) 
int findLCA(int root, int u, int v) 
{ 
    int indx = 0;
    eulerTree(root, indx, 0); 
    findFirstOcc();         
  
    /* construct segment tree on level array */
    int *st = constructST(level, 2*n-1); 
  
    /* If v before u in Euler tour.  For RMQ to work, first 
       parameter 'u' must be smaller than second 'v' */
    if(firstOcc[u] > firstOcc[v]) 
        swap(u, v); 
  
    // Starting and ending indexes of query range 
    int qs = firstOcc[u]; 
    int qe = firstOcc[v]; 
  
    // index is ind in the array level in the range qs, qe for whilch the level is minimum - 
    // this is the very logic of this approach
    int index = RMQ(st, 2*n-1, qs, qe);         
  
    // return the node from the index obtained form euler tour
    return euler[index]; 
} 
  



int main()
{
    cin >> n;

    for(int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

    int root = 1, u, v, q;

    // for(int i = 0; i < 2*n-1; i++)
    //      cout << euler[i] << " ";
    // cout << endl;

    // for(int i = 0; i < 2*n-1; i++)
    //      cout << level[i] << " ";
    // cout << endl;

    // for(int i = 0; i <= n; i++)
    //      cout << firstOcc[i] << " ";
    // cout << endl;
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        cout << "LCA: " << findLCA(1, u, v) << endl;
    }

}