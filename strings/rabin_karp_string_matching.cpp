#include<bits/stdc++.h>
using namespace std;
#define int long long int 

/* 
string hashes are sure to collide since there are exponential strings and 2^64 hashes only 
p = 31 is a good choice if the chars are lowercase letters only 
if string has bith lowercase and uppercase letters then p = 53 is a good choice 
p is roughly equal to the number of distinct chars in string
*/

const int mod = 1e9+9;
int p = 31;

int create_hash(string s, int n) {
    int hash_value = 0;
    int p_pow = 1;
    for(int i = 0; i < n; i++) {
        hash_value += ((s[i]-'a'+1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
    }
    return hash_value;
}

bool match(string s, string pat, int st, int en) {
    for(int i = st; i <= en; i++) {
        if(s[i] != pat[i-st]) {
            return false;
        }
    }
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