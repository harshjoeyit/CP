/*
There are n blocks arranged in a row and numbered from left to right, starting from one. Each block is either black or white.

You may perform the following operation zero or more times: choose two adjacent blocks and invert their colors 
(white block becomes black, and vice versa).

You want to find a sequence of operations, such that they make all the blocks having the same color. 
You don't have to minimize the number of operations, 
but it should not exceed 3⋅n. If it is impossible to find such a sequence of operations, you need to report it.
*/


#include<bits/stdc++.h>
using namespace std;

#define ll                    long long int
#define ld                    long double
#define mid(s,e)              (s+(e-s)/2)
#define MOD                   1000000007
#define F                     first
#define S                     second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>


char Opp(char c)
{
    if(c == 'W')
        return 'B';
    return 'W';
}

void print_ans(vi &ans)
{
    cout << ans.size() << endl;
    if(ans.size() > 0)
    {
        for(auto &x: ans)
            cout << x << " ";
        cout << endl;
    }
}   
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vi ans;
    string s, ss;
    cin >> n;
    cin >> s;

    ss = s;

    for(int i = 0; i < n-1; i++)
    {
        if(s[i] == 'B')
        {
            s[i] = Opp(s[i]);
            s[i+1] = Opp(s[i+1]);
            ans.pb(i+1);
        }
    }        

    if(s[n-1] == 'B')
    {
        ans.clear();
        for(int i = 0; i < n-1; i++)
        {
            if(ss[i] == 'W')
            {
                ss[i] = Opp(ss[i]);
                ss[i+1] = Opp(ss[i+1]);
                ans.pb(i+1);
            }
        }  

        if(ss[n-1] == 'W')
            cout << -1 << endl;
        else
            print_ans(ans);
    }
    else
        print_ans(ans);
}