#include<bits/stdc++.h>
using namespace std;

#define int long long int 

const int N = 10000;
vector<int> G[N];
int vis[N];
int Euler[2*N];

void eulerTree(int u, int &indx) 
{ 
    vis[u] = 1; 
    Euler[indx++] = u; 
    for(auto it : G[u]) { 
        if (!vis[it]) { 
            eulerTree(it, indx); 
            Euler[indx++] = u; 
        } 
    } 
}	

void printEulerTour(int root, int n) 
{ 
    int index = 0;   
    eulerTree(root, index); 
    for(int i = 0; i < (2*n-1); i++) 
        cout << Euler[i] << " "; 
} 
  

signed main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

    printEulerTour(1, n); 
}