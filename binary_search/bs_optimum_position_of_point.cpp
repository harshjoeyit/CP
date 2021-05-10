
/*
    Given a set of points and a line, find the optimum position of point 
    on the line so that total distance to all the points is minimized
    
    https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/

    Sol - Ternary Search
*/

#include <bits/stdc++.h>
using namespace std;

const double precision = 1e-6;

struct point {
    int x, y;
    point() {}
    point(int _x, int _y): x(_x), y(_y) {}
};

struct line {
    int a, b, c;
    line() {}
    line(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
};

double sq(double x) {
    return x * x;
}
double dist(double x, double y, point p) {
    return sqrt(sq(x - p.x) + sq(y - p.y));
}

double totalDist(vector<point> &pts, line l, double x) {
    double totDis = 0;
    double y = -1 * (l.c + l.a * x)/l.b;
    for(auto p: pts) {
        totDis += dist(x, y, p);
    }
    return totDis;
}

double findOptimumDistanceUtil(vector<point> &pts, line l) {
    double low = -1e6, high = 1e6;  // range of x coordinate

    while((high - low) > precision) {
        double mid1 = low + (high - low)/3;
        double mid2 = high - (high - low)/3;

        double dist1 = totalDist(pts, l, mid1);
        double dist2 = totalDist(pts, l, mid2);
    
        if(dist1 < dist2) {
            high = mid2;
        } else {
            low = mid1;
        }
    }

    return totalDist(pts, l, (low + high)/2);
}

void findOptimumDistance() {
    vector<point> pts = {{ -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }};
    line l(2, -1, -4);
    cout << findOptimumDistanceUtil(pts, l) << endl;
}

int main() {
    findOptimumDistance();
}