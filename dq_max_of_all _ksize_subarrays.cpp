#include<bits/stdc++.h>
using namespace std;

#define int long long int

void printKmax1() {
    int n, k;
    cin >> n >> k;
    int a[n+1];
    
    set<pair<int, int>> s;
    
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i <= k)
            s.insert({a[i], i});
    }
    cout << s.rbegin()->first << " ";
    for(int i=k+1; i<=n; i++) {
        s.erase({a[i-k], i-k});
        s.insert({a[i], i});
        cout << s.rbegin()->first << " ";
    }
    cout << endl;
}

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

        while((!dq.empty()) && dq.front() <= i-k)           // remove elements that are out of current window
            dq.pop_front();
        
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


