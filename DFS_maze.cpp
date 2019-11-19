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


char Check(string a[1001], int i, int j, int r, int c)
{
    if(i >= 0 && i < r && j >= 0 && j < c)
        return a[i][j];
    return 0;
}

int Valid(int i, int j, int r, int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

void disp(pii p)
{
    cout << "Push: "<<  p.F << ", "<< p.S << endl;
}

void popd(pii p)
{
    cout << "Pop: "<<  p.F << ", "<< p.S << endl;
}

void pri(string a[1001], pii p)
{
    cout << "check: "<<  a[p.F][p.S] << endl;
}


int Search(string a[1001], int r, int c, pii source)
{

    stack<pii> s;

    s.push(source);
                                disp(source);
    a[source.F][source.S] = '*';
    int i, j;

    while(!s.empty())
    {
        pii p = s.top();
                                popd(p);
        s.pop();

        i = p.F; 
        j = p.S;


        char left = Check(a, i-1, j, r, c);
        char up = Check(a, i, j-1, r, c);
        char down = Check(a, i+1, j, r, c);
        char right = Check(a, i, j+1, r, c);

        if(left == 'T' || up == 'T' || right == 'T' || down == 'T' )
            return true;

        if( left == '.')
        {
            s.push(mp(i-1, j));
            a[i-1][j] = '*';
                                disp(s.top());
        }


        if(up == '.')
        {
            s.push(mp(i, j-1));
            a[i][j-1] = '*';
                                disp(s.top());
        }

        if(right == '.')
        {
            s.push(mp(i, j+1));
            a[i][j+1] = '*';
                                disp(s.top());
        }

        if(down == '.')
        {
            s.push(mp(i+1, j));
            a[i+1][j] = '*';
                                disp(s.top());
        }
    }

    return 0;
}

// falis in
/*

7 7
.S.****
...*.*.
.****..
.*.**.*
..T*...
***..*.
*******

*/                             

int recSearch(string a[1001], int r, int c, pii source, int turns, char dir)
{
    int i = source.F;
    int j = source.S;

    if(turns > 2 || a[i][j] == '*')
        return 0;

    cout << "At: "<<  i << ", "<< j << endl;
    cout << "turns: " << turns << endl << endl;

    if(a[i][j] == 'T')
        return true;

    if(a[i][j] == '.')
    {
        a[i][j] = '*';
        int x = 0, y = 0, z = 0, k = 0;

        if(Valid(i, j+1, r, c))
        {
            if(dir == 'x')
                k = recSearch(a, r, c, mp(i, j+1), turns, 'h');
            else if(dir == 'v')
                k = recSearch(a, r, c, mp(i, j+1), turns+1, 'h');
            else
                k = recSearch(a, r, c, mp(i, j+1), turns, 'h');
        }
        if(Valid(i+1, j, r, c) && (k == 0))
        {
            if(dir == 'x')
                z = recSearch(a, r, c, mp(i+1, j), turns, 'v');
            else if(dir == 'h')
                z = recSearch(a, r, c,mp(i+1, j), turns+1, 'v');
            else
                z = recSearch(a, r, c, mp(i+1, j), turns, 'v');
        }
        if(Valid(i, j-1, r, c) && (k == 0) && (z == 0))
        {
            if(dir == 'x')
                y = recSearch(a, r, c, mp(i, j-1), turns, 'h');
            else if(dir == 'v')
                y = recSearch(a, r, c, mp(i, j-1), turns+1, 'h');
            else
                y = recSearch(a, r, c, mp(i, j-1), turns, 'h');
        }
        if(Valid(i-1, j, r, c) && (k == 0) && (z == 0) && (y == 0))
        {
            if(dir == 'x')
                x = recSearch(a, r, c, mp(i-1, j), turns, 'v');
            else if(dir == 'h')
                x = recSearch(a, r, c, mp(i-1, j), turns+1, 'v');
            else
                x = recSearch(a, r, c, mp(i-1, j), turns, 'v');
        }

        return (x || y || z || k);
    }

    return 0;
}




int main()
{
    string a[1001];

    int n, m;
    cin >> n >> m;

    pii source;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'S')
            {
                source = make_pair(i,j);
                a[i][j] = '.';
            }
    }

    if(recSearch(a, n, m, source, 0, 'x'))
        cout << "found" << endl;
    else
        cout << "not" << endl;
    
}