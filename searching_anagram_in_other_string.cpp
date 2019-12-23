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

    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--)
    {
        string p, h;
        cin >> p >> h;
        map<char, int> m1;
        bool flag = false;

        for(int i = 0; i < p.length(); i++)
            ++m1[p[i]];

        if(p.length() <= h.length())
        {
            for(int i = 0; i <= h.length() - p.length(); i++)
            {
                map<char, int> m2;
                for(int j = 0; j < p.length(); j++)
                    ++m2[h[i + j]];

                 //cout << m1.size() << " " << m2.size() << endl;

                if(m2.size() == m1.size())
                {
                    auto it1 = m1.begin(), it2 = m2.begin(); 
                    for(; it1 != m1.end(); it1++, it2++)
                    {
                        // cout << it1->F << it2->F << endl;
                        if(it1->F != it2->F || it1->S != it2->S)
                        {
                            break;
                        }
                    }
                    if(it1 == m1.end())
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
    
}