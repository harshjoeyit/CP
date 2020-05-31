#include<bits/stdc++.h>
using namespace std;

#define int long long 

void medianInStream(vector<int> arr, int n) {
    priority_queue<int> s; 
    priority_queue<int,vector<int>,greater<int> > g; 
  
    int med = arr[0]; 
    s.push(arr[0]); 
  
    cout << med << endl; 
  
    // reading elements of stream one by one 
    /*  At any time we try to make heaps balanced and 
        their sizes differ by at-most 1. If heaps are 
        balanced,then we declare median as average of 
        min_heap_right.top() and max_heap_left.top() 
        If heaps are unbalanced,then median is defined 
        as the top element of heap of larger size  */

    for (int i=1; i < n; i++) { 
        int x = arr[i]; 

          // case1(left side heap has more elements) 
         if(s.size() > g.size()) {  
            if (x < med) { 
                g.push(s.top()); 
                s.pop(); 
                s.push(x); 
            } 
            else {
               g.push(x);
            } 
  
            med = (s.top() + g.top())/2.0; 
        } 
  
        // case2(both heaps are balanced) 
         else if (s.size()==g.size()) { 
            if (x < med) { 
                s.push(x); 
                med = (int)s.top(); 
            } 
            else { 
                g.push(x); 
                med = (int)g.top(); 
            } 
        } 
  
        // case3(right side heap has more elements) 
         else { 
            if (x > med) { 
                s.push(g.top()); 
                g.pop(); 
                g.push(x); 
            } 
            else {
               s.push(x);
            } 
  
            med = (s.top() + g.top())/2.0; 
        } 
        cout << med << endl; 
    } 
} 

void solve() {
   int n;
   cin >> n;
   vector<int> a(n);

   for(int i=0; i<n; i++)
      cin >> a[i];

   medianInStream(a, n);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}