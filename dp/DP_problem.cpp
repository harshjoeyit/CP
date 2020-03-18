/*
.........DP................

You have a row of numbers. 
In every turn, you can remove either the leftmost or the rightmost number and get points equal to (turn_number * value_removed) 
What is the maximum number of points you can get?

logic : dp[i][j] = max(dp[i][j-1] + Sum(i, j-1, sum) + a[j]   ,   dp[i+1][j] + Sum(i+1, j, sum) + a[i]);
two changing states i, j so 2d array
make a tree with two options as the value in front or the value at last could be chosen

                            start
                          /      \
                       2          4
                    /    \     /    \
                  3      4    2       1
                  ..................
*/



#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 10;
int dp[10][10] = {0};

int Sum(int i, int j, vector<int> sum)
{
    if(i == 0)
        return sum[j];
    
    return sum[j] - sum[i-1];
}


int find_max_sum(int i, int j, vector<int> sum, vector<int> a)
{

    if(dp[i][j-1] == 0)
        dp[i][j-1]  = find_max_sum(i, j-1, sum, a);
    
    if(dp[i+1][j] == 0)
        dp[i+1][j] =  find_max_sum(i+1, j, sum, a);

    return max(dp[i][j-1] + Sum(i, j-1, sum) + a[j]   ,   dp[i+1][j] + Sum(i+1, j, sum) + a[i]);
}



int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> sum(n, 0);
    sum[0] = a[0];
    for(int i = 1; i < n; i++)
        sum[i] = sum[i-1] + a[i];

    for(int i = 0; i < n; i++)
        dp[i][i] = a[i];

    dp[0][n-1] = find_max_sum(0, n-1, sum, a);
    cout << dp[0][n-1] << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}