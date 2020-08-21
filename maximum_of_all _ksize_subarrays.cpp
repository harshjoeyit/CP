#include<bits/stdc++.h>
using namespace std;
#define int long long int

// O (n log n) using sets 

void printKmax1() {
    int n, k;
    cin >> n >> k;
    int a[n+1];
    
    // value, index pair is inserted 
    set<pair<int, int>> s;
    
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i <= k)
            s.insert({a[i], i});
    }
    cout << s.rbegin()->first << " ";
    for(int i=k+1; i<=n; i++) {
        // window is shifted 
        s.erase({a[i-k], i-k});
        s.insert({a[i], i});
        cout << s.rbegin()->first << " ";
    }
    cout << endl;
}

// O (n) using deque 
void printKmax() {
    int n, k;
    cin >> n >> k;   
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    deque<int> dq;
    int i;

    for(int i=0; i<k; i++) {
        while((!dq.empty()) && (a[i] > a[dq.back()]))
            dq.pop_back();

        dq.push_back(i);
    }

    for(; i<n; i++) {
        cout << a[dq.front()] << " ";

        // remove elements that are out of current window
        while((!dq.empty()) && dq.front() <= i-k)           
            dq.pop_front();
        
        // remove the lesser elements that this element 
        while(!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
    }
    
    cout << a[dq.front()] << "\n";
}

void solve() {
    printKmax1();       //O(nlogn);
    printKmax();        //  O(n)
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}


