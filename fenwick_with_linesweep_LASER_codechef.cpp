#include<bits/stdc++.h>
using namespace std;

#define int long long int

struct query{
    int x1;
    int x2;
    int y;
    int ans;
    int pos;
};

struct Point{
    int x;
    int y;
    int start;
};

bool comp(Point p1, Point p2){
    return p1.y < p2.y;
}

bool comp2(query q1, query q2){
    return q1.y < q2.y;
}

bool comp3(query q1, query q2){
    return q1.pos < q2.pos;
}

void add(vector<int> &tree, int idx, int val) {
    while(idx < tree.size()) {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

int get(vector<int> &tree, int idx) {
    int result = 0;
    while(idx) {
        result += tree[idx];
        idx -= idx & (-idx);
    }
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> y(n+1, 0);
        vector<int> mapy;       // vector for line sweeping u coordinates

        for(int i = 1; i <= n; i++) {
            cin >> y[i];
            mapy.push_back(y[i]);
        }

        // for all the queries 
        vector<query> qr(q);
        for(int i = 0; i < q; i++) {
            cin >> qr[i].x1 >> qr[i].x2 >> qr[i].y;
            qr[i].pos = i;
            // since we want line sweep wherever query is given.
            mapy.push_back(qr[i].y);                
            qr[i].ans = 0;
        }

        sort(mapy.begin(), mapy.end());
        // all duplicated removed from mapy
        // mapy stores y where line sweep is done
        mapy.erase(unique(mapy.begin(), mapy.end()), mapy.end());

        // coordinate compression 
        // y <= 10^9 , n <= 10^5
        // now all the y are in range of 10^5; 
        for(int i = 1; i <= n; ++i) {
            int p = lower_bound(mapy.begin(), mapy.end(), y[i]) - mapy.begin();
            y[i] = p+1;     // 1 based indexing 
        }
        // y for all the queries are changed to new values of y
        for(int i=0; i<q; ++i) {
            int p = lower_bound(mapy.begin(), mapy.end(), qr[i].y) - mapy.begin();
            qr[i].y = p+1;
        }

        // finding the start(one with lower y) of the line segement between i, y(i) ans i+1, y(i+1)
        vector<Point> p;
        for(int i =2 ; i <= n; ++i) {
            Point p1, p2;
            p1.x = i-1;
            p2.x = i-1;
            p1.y = y[i-1];
            p2.y = y[i];
            if(p1.y < p2.y) {
                p1.start = true;
            }
            else
                p1.start = false;
            p2.start = !p1.start;
            p.push_back(p1);
            p.push_back(p2);
        }

        // points and queries sorted in increasing order of y
        sort(p.begin(), p.end(), comp);   
        sort(qr.begin(), qr.end(), comp2);  

        vector<int> active(n+10, 0);
        int i = 0, j = 0;
        for(int cy=0; cy<=mapy.size(); ++cy) {              // cy = current line sweep coordinates of y 
            int ti = i;
            while(ti < p.size() && p[ti].y <= cy) {
                if(p[ti].start) {
                    add(active, p[ti].x, 1);                // line segment starting at current y added 
                }
                ++ti;
            }
            while(j < qr.size() && qr[j].y <= cy) {
                if(qr[j].y == cy) {                         // query with y coordinate = current y found
                    int l = get(active, qr[j].x1-1);
                    int r = get(active, qr[j].x2-1);
                    qr[j].ans = r - l;                      // all active x in range l, r are found 
                }
                ++j;
            }
            while(i < p.size() && p[i].y <= cy) {           // line segment ending at current y removed
                if(!p[i].start) {
                    add(active, p[i].x, -1);
                }
                ++i;                                        // these line segement have no use further 
            }
        }

        sort(qr.begin(), qr.end(), comp3);                  // sorted in the order asked 
        for(int i=0; i<q; ++i)
            cout<<qr[i].ans<<endl;
    
    }
}