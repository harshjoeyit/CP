
/*
https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/discuss/636332/cpp-O(N3)-solution-with-pictures.

given some points on a 2D plane 
find max number of points in a circle of radius r
*/

#include<bits/stdc++.h>
using namespace std;

const double tol = 1e-6;
double R;
struct Point {
    double x, y;
};

vector<Point> point;

double dis(const Point& a, const Point& b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

pair<Point, Point> getCenter(const Point& a, const Point& b) {
	Point mid;
	pair<Point, Point> res;
	mid.x = (a.x + b.x) / 2, mid.y = (a.y + b.y) / 2;
	double theta = atan2(a.y - b.y, b.x - a.x);
	double tmp = dis(a, b) / 2;
	double d = sqrt(R * R - tmp*tmp);
	res.first.x = mid.x - d*sin(theta);
	res.first.y = mid.y - d*cos(theta);
	res.second.x = mid.x + d*sin(theta);
	res.second.y = mid.y + d*cos(theta);
	return res;
}
int numPoints(vector<vector<int>>& points, int r) {
	int n = points.size();
	R = (double)r;
	point.resize(n);
	for (int i = 0; i < n; ++i) {
		point[i].x = points[i][0];
		point[i].y = points[i][1];
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || dis(point[i], point[j]) - 2 * R > tol) continue;
			int cnt = 0;
			auto p = getCenter(point[i], point[j]);
			for (int k = 0; k<n; k++) {
				if (dis(point[k], p.first) - R <= tol) 
					cnt++;
			}
			ans = max(ans, cnt);
			cnt = 0;
			for (int k = 0; k<n; k++) {
				if (dis(point[k], p.second) - R <= tol) 
					cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	return ans;
}

int main() {
        // stdin
        // stdout
}