#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
void maxRecArea(vector<int> &a) {
	int n = a.size();
	int ans = 0, area, h;

	for (int i = 0; i < n; i++) {
		// we try to find the max area while including ith bar
		// h keeps the value of minimum bar height in the current iteration
		h = a[i];

		// go to all the bars in right
		for (int j = i; j < n; j++) {
			if (a[j] < h) {
				// if lesser bar height is found then h is reassigned
				h = a[j];
			}
			area = h * (j - i + 1);
			ans = max(ans, area);
		}
    }
    cout << ans << "\n";
}


// O(n)
int niceMaxRectangleArea(vector<int> &heights) {
    heights.push_back(0);
    int n = heights.size();
    stack<int> s;
    int area, maxArea = 0, i = 0;
    
    while (i < n) {
        
        if (s.empty() || heights[i] > heights[s.top()]) {
            s.push(i);
            i++;

        } else {
            int top = s.top();
            s.pop();
            area = heights[top] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
            // cout << i << " " << heights[top] << " " << area << endl;
        }
    }
    return maxArea;
}




int main() {
    vector<int> v = {1,2,3,4,5,3,3,2};
    vector<int> v = {2, 4, 0, 2, 3, 2, 1};
    maxRecArea(v);
}    