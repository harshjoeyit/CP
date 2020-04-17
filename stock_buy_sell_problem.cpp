

// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0/


#include<bits/stdc++.h>
using namespace std;

#define int long long 

void stock_sell_problem_sol2() {
    int n;
    cin >> n;
    int a[n+1];
    
    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    a[0] = (int)1e7;
    a[n+1] = 0;

    int minima[n], i = 0;
    int maxima[n], j = 0;
    
    for(int k=1; k<=n; k++) {
        if(a[k-1] > a[k] && a[k] < a[k+1]) {
            minima[i++] = k;
        } 
        if(a[k-1] < a[k] && a[k] > a[k+1]) {
            maxima[j++] = k;
        }
    }
    
    int p=0;
    for(int k=0; k<j; k++) {
        p = 1;
        cout << "(" << minima[k]-1 << " " << maxima[k]-1 << ") ";
    }
    if(p == 0)
        cout << "No Profit";
    cout << endl;
        
}

void stock_sell_problem_sol1() {
    int n;
    cin >> n;
    int a[n+1];
    
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    a[n] = 0;
    int i = 0, j = 0;
    int p = 0;

    while(i < n) {

        while((i < n-1) && (a[i] > a[i+1]))
            ++i;
        
        if(i == n-1) break;
        
        j = i + 1;
        
        while(j < n && a[j] < a[j+1]) 
            ++j;
        
        cout << "("<< i << " " << j << ") ";
        p += a[j] - a[i];
        
        i = j + 1;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stock_sell_problem_sol1();
    stock_sell_problem_sol1();
}