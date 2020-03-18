#include<bits/stdc++.h>
using namespace std;

#define int long long int 
int p = 31;

int create_hash(string str, int n)
{
    int h = 0;
    for(int i = 0; i < n; i++)
    {
        h += (int)str[i] * pow(p, i);
    }
    return h;
}

bool match(string s, string pat, int st, int en)
{
    for(int i = st; i <= en; i++)
        if(s[i] != pat[i-st])
            return false;
    return true;
}

void rabin_karp(string s, string pat)
{
    int n = pat.length();
    int pat_hash = create_hash(pat, n);
    vector<int> Hash(s.length());

    Hash[0] = create_hash(s, n);

    for(int i = 1; i <= s.length() - n; i++)
    {
        Hash[i] = Hash[i-1] - (int)s[i-1];
        Hash[i] = Hash[i]/p;
        Hash[i] += (int)s[i+n-1] * pow(p, n-1);
    }

    for(int i = 0; i <= s.length()-n; i++)
        if(pat_hash == Hash[i] && match(s, pat, i, i+n-1))
            cout << i << " ";
}


signed main()
{
    string s, pat;
    cin >> s >> pat;

    //cout << create_hash(pat, pat.length());
    rabin_karp(s, pat);
}