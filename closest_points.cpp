
#include<bits/stdc++.h>
using namespace std;

struct pt {
    int x, y, id;
};

int n;
vector<pt> p, px, py;
double mindist;
pair<int, int> ans;



bool compY (const pt &a, const pt &b) {
    return a.x < b.x;
}
bool compX (const pt &a, const pt &b) {
        return a.y < b.y;
}

float dist(const pt &a, const pt &b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

float bruteForce(int st, int en) {
    float mn = FLT_MAX;
    for (int i = st; i < en; i++) {
        for (int j = i + 1; j <= en; j++) {
            mn = min(mn, dist(p[i], p[j]));
        }
    }
    return mn;
}

float closetPoints(int st, int en) {
    if(en - st + 1 <= 3) {
        // 3 or lesser points
        return bruteForce(st, en);
    }

    int mid = (st + en) / 2;
    pt mpt = px[mid];

    vector<int> pyl, pyr;
    for(int i=st; i<=en; i++) {
        if(py[i].x <= mpt.x && py.size() < )
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y, i});
    }
    py = px = p;

    sort(px.begin(), px.end(), compX);
    sort(py.begin(), py.end(), compY);

    closetPoints(0, n-1);
}
