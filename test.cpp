#include<bits/stdc++.h>
using namespace std;
#define int long long int

int cutWood(vector<int> &heights, int bladeHeight) {
    int wood = 0;
    for(auto h: heights) {
        wood += max(0LL, h - bladeHeight);
    }
    return wood;
}

void solve() {
    int n, needWood;
    cin >> n >> needWood;
    vector<int> heights(n);
    
    int low = 0, high = 0;
    for(auto &val: heights) {
        cin >> val;
        high = max(val , high);
    }
    // ans = optimum blade height
    int ans = low;

    // blade can go from "low(0)" to "high" height 
    while(low <= high) {
        int bladeHeight = low + (high-low)/2;
        int wood = cutWood(heights, bladeHeight);
        if(wood >= needWood) {
            ans = max(ans, bladeHeight);
            // more wood cut than needed, raise the blade
            low = bladeHeight + 1;
        } else {
            // less wood cut than needed, lower the blade
            high = bladeHeight - 1;
        }
    }
    cout << ans << "\n";
}

signed main() {
    solve();
}