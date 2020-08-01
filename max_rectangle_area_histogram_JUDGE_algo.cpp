#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
void maxRecArea() {
    int a[] = {6, 2, 5, 4, 5, 1, 6}; // hieghts of the histogram bars
    int size = sizeof(a) / sizeof(int);
    int max, MAX = -9999, area, x;

    for (int i = 0; i < size; i++) {
        // we try to find the max area while including ith bar
        // later we find Max of all max areas 
        x = a[i];                      
        // x keeps the value of minimum bar height in the current iteration
        max = -9999;                   
        // max to find the max vallue of area in current iteration
        for (int j = i; j < size; j++) {
            // starting from current bar and goin to the end
            if (a[j] < x) {
                // if lesser bar height is found then x is reassigned
                x = a[j];
            }
            area = x * (j - i + 1); 
            // IMP: area is calculated as (min bar height (x) * number of bars)(till the current iteration)
            
            // changing max
            if (area > max) {
                max = area;
            }
        }
        // max is max-area while including ith bar in the rectangle formed 
        // changing MAX
        if (max > MAX) {
            MAX = max;
        }
    }
    cout << MAX;
}


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


// aternative solution

#define height first
#define index second

int maxRectangleArea(int A[], int n) {
    int mxarea = -1, left, curr;
    stack<pair<int, int>> S;

    for (int i = 0; i <= n; i++) {
        while (!(S.empty()) && (i == n || S.top().height > A[i])) {
            if (S.size() > 1) { // min 2 items
                auto t = S.top();
                S.pop();
                left = S.top().index; // 2nd item on the stack
                S.push(t);
            }
            else
                left = -1;

            curr = (i - left - 1) * S.top().height;
            cout << (i - left - 1) << " " << S.top().height << endl;
            S.pop();

            if (curr > mxarea)
                mxarea = curr;
        }
        if (i < n)
            S.push({A[i], i});
    }
    return mxarea;
}


int main()
{
    int a[] = {1,2,3,4,5,3,3,2};
    // int a[] = {5, 4, 3, 2, 3, 4, 1, 2};
    // hieghts of the histogram bars
    int size = sizeof(a) / sizeof(int);

    // cout << "max area: " << maxRectangleArea(a, size) << "\n";

    // vector<int> v = {1,2,3,4,5,3,3,2};
    vector<int> v = {5, 4, 3, 2, 3, 2, 1};
    niceMaxRectangleArea(v);
}    