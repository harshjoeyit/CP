#include<bits/stdc++.h>
using namespace std;

/*
    TODO : Right Angled Triangles
    !Given N points in a 2D cartesian plane, How many right angled triangles are there such that perpendicular or base is parallel to X or Y - axis?

*/

int solve(vector<pair<int, int>> points) {
    unordered_map<int, int> hx, hy;

    for(auto p : points) {
        hx[p.first]++;
        hy[p.second]++;
    }

    int ans = 0;
    for(auto p : points) {
        int n1 = hx[p.first];
        int n2 = hy[p.second];

        ans += (n1 - 1) * (n2 - 1);
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    for(auto p : points) {
        cin >> p.first >> p.second;
    }
    cout << solve(points) << endl;
 
} 