#include<bits/stdc++.h>
using namespace std;

// variations 
// bridges 
// maximum sum subsequence 
// maximmum chain length - elements are pairs (a, b), (c, d) chain is formed when b < c , given a < b and d > c alwauys 

// similar problem 
// find largest bitonic sequence, (first increasing and then decreasing or only inc or only dec)
// Solution 
// find lis array from left 
// find list array from right 
// find max(left[i] + right[i] - 1)

int main()
{
    
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> dp(n, 1);

    int maxlen = 1;
    for(int i = 1; i < n; i++)
    {   
        int max = 0;
        for(int j = 0; j < i; j++)
            if((v[j] < v[i]) && (dp[j] > max))
                max = dp[j];
        
        dp[i] = max + 1;
        if(dp[i] > maxlen)
            maxlen = dp[i];
    }   

    // for(auto &x: dp)
    //     cout << x << " ";
    // cout << endl;

    cout << maxlen << endl;
}

// printing the longest bitonic sequence 
void printBitonic() {
        int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    vector<int> incPath(n, 0);
    auto decPath = incPath;

    for(int i=0; i<n; i++) {
        incPath[i] = i;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(a[i] > a[j] && inc[j] + 1 > inc[i]) {
                inc[i] = inc[j] + 1;
                incPath[i] = j;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if(a[i] > a[j] && dec[j] + 1 > dec[i]) {
                dec[i] = dec[j] + 1;
                decPath[i] = j;
            }
        }
    }

    int ans = 1, j = 0;
    for (int i = 0; i < n; i++) {
        int curr = inc[i] + dec[i] - 1;
        if(curr > ans) {
            ans = curr;
            j = i;
        }
    }

    cout << ans << endl;
    stack<int> temp;

    int st = j;
    while (incPath[st] != st) {
        temp.push(a[st]);
        st = incPath[st];
    }
    vector<int> res;
    
    while(!temp.empty()) {
        res.push_back(temp.top());
        temp.pop();
    }
    res.pop_back();

    st = j;
    while(decPath[st] != st) {
        res.push_back(a[st]);
        st = decPath[st];
    }

    for(auto val: res) {
        cout << val << " ";
    }
}