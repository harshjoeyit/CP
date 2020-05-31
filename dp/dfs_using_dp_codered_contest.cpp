
/*
A M x N black and white chessboard is given with (1,1) being white and so on. A knight is given which can only move forward on this chessboard.

The allowed moves if the current cell is (i,j) are:

(i,j) to (i+2,j+1)
(i,j) to (i+1,j+2)
(i,j) to (i+2,j−1)
(i,j) to (i+1,j−2)
Once the knight is outside the chessboard after a move, it cannot enter inside again. Find X, the number of ways the knight can reach from any black cell in the 1st row to any cell in the Mth row such that the number of moves made is odd.

As X can be large, find it modulo 109+7 .

Help Bhide to find X.
*/


#include<bits/stdc++.h>
using namespace std;

struct st{
    int ev, odd;
};

#define int long long int
vector<vector<st>> a;
int m, n;
const int mod = 1000000007;

void disp()
{
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << "("<< a[i][j].odd << " " << a[i][j].ev << "), ";
        cout << endl;
    }
}

bool valid(int x, int y)
{
	if(x < 1 || y < 1 || x > m || y > n) 
		return false;
	return true;	
}

void calc()
{
    for(int j = 1; j <= n; j++)
    {
        int x = 0;
        if(valid(m, j-2))
            ++x;
        if(valid(m, j+2))
            ++x;
        a[m-1][j].odd = x;
        a[m-1][j].ev = 0;
    }

    for(int j = 1; j <= n; j++)
    {
        int x = 0;
        if(valid(m, j-1))
            ++x;
        if(valid(m, j+1))
            ++x;
        a[m-2][j].odd = x;
    }

    for(int j = 1; j <= n; j++)
    {
        int x = 0;
        if(valid(m-1, j-2))
            x += a[m-1][j-2].odd;
        if(valid(m, j+2))
            x += a[m-1][j+2].odd;

        a[m-2][j].ev = x;
    }

    // for all rows
    for(int r = m-3; r >= 1; r--)
    {
        // for each block
        for(int j = 1; j <= n; j++)
        {
        
            if(valid(r+1, j-2))
            {
                a[r][j].ev = (a[r][j].ev + a[r+1][j-2].odd) % mod;
                a[r][j].odd = ( a[r][j].odd + a[r+1][j-2].ev) % mod;
            }

            if(valid(r+1, j+2))
            {
                a[r][j].ev = ( a[r][j].ev + a[r+1][j+2].odd) % mod;
                a[r][j].odd = ( a[r][j].odd + a[r+1][j+2].ev) %mod;
            }

            if(valid(r+2, j-1))
            {
                a[r][j].ev = (a[r][j].ev + a[r+2][j-1].odd) % mod;
                a[r][j].odd = (a[r][j].odd + a[r+2][j-1].ev) % mod;
            }

            if(valid(r+2, j+1))
            {
                a[r][j].ev = (a[r][j].ev + a[r+2][j+1].odd) % mod;
                a[r][j].odd = (a[r][j].odd + a[r+2][j+1].ev) % mod;
            }
        }
    }
}


signed main(){
	cin >> m >> n;
    a.assign(m+1, vector<st>(n+1));

    if(m >= 2 && n >= 3)
    {
        calc();
        disp();

        int ans = 0;
        for(int j = 2; j <= n; j = j+2)
            ans = (ans + a[1][j].odd) % mod;
        cout << ans << endl;
    }
    else
        cout << 0 << endl;

}
