#include<bits/stdc++.h>
using namespace std;

string LCS = "";

void print_lcs(string &s1, string &s2, vector<vector<int>> dp, int n, int m)
{
    int i = n-1, j = m-1;
    while((i > 0) && (j > 0))
    {
        //cout << s1[i-1] << " " << s2[j-1] << endl;
        if(s1[i-1] == s2[j-1])
        {
            LCS = s1[i-1] + LCS;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    cout << LCS << endl;
}

int lcs(string &s1, string &s2)
{
    int n = s1.length()+1, m = s2.length()+1;
    vector<vector<int>> dp;
    dp.assign(n, vector<int>(m));

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    print_lcs(s1, s2, dp, n, m);
    return dp[n-1][m-1];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int l = lcs(s1, s2);
    cout << l << endl;
}