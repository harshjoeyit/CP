
/*
    https://www.spoj.com/problems/DIEHARD/

    If you step into air, your health increases by 3 and your armor increases by 2
    If you step into water, your health decreases by 5 and your armor decreases by 10
    If you step into fire, your health decreases by 20 and your armor increases by 5
    
    If your health or armor becomes <=0, you will die instantly
    Find the maximum time you can survive, if you change your position every second
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

// DP Solution O(n*n), where 1 <= a,h <= n
vector<vector<int>> rules = {{3,2},{-20,5},{-5,-10}};
int dp[4][1050][1050];

int go(int i, int h, int a) {
    if(h == 0 || a == 0) {
        return 0;
    }
    int &ans = dp[i][h][a];
    if(ans != -1) {
        return ans;
    }
    ans = 0;
    for(int j=0; j<3; j++) {
        if(i != j) {
            int H = h + rules[j][0];
            int A = a + rules[j][1];
            if(H > 0 && A > 0) {
                ans = max(ans, 1 + go(j, H, A));
            }
        }
    }
    return ans;
}

void solve() {
    int h, a;
    cin >> h >> a;
    memset(dp, -1, sizeof(dp));
    cout << go(3, h, a) << "\n";
}


/*
    Greedy Approach: Why does it work?
    From Air we have only 2 choices => Water, Fire 
    From Water/Fire only 1 choice => Air
*/
int cnt;
int air(int, int);
void water(int, int);
void fire(int , int);

int air(int x,int y) {
    cnt++;
    int h = x+3, a = y+2;

    // we prefer water over air because the reduction is divided 
    // in both whereas in fire only reduction is in health
    if (h-5 > 0 && a-10 > 0) {
        water(h,a);
    }
    else if(h-20 > 0) {
        fire(h,a);
    }
    return cnt;
}

void water(int x,int y) {
    cnt++;
    int h = x-5, a = y-10;
    air(h, a);
}

void fire(int x,int y) {
    cnt++;
    int h = x-20, a = y+5;
    air(h, a);
}

void solveGreedy() {
    int a, h;
    cnt = 0;
    cin >> h >> a;
    k = air(h,a);
    cout << cnt << endl;
}


signed main() {
    solve();
}