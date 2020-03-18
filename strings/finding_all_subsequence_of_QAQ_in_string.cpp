#include<bits/stdc++.h>
using namespace std;

#define int long long int

// finding all subsequence of QAQ in string

void print_vector(vector<int> v)
{
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

signed main()
{   
    string s;
    cin >> s;
    vector<int> pre(s.length());
    vector<int> suf(s.length());

    int cnt = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'Q')
            ++cnt;
        pre[i] = cnt;
    }
    cnt = 0;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(s[i] == 'Q')
            ++cnt;
        suf[i] = cnt;
    }

    // print_vector(pre);
    // print_vector(suf);

    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'A')
            ans += pre[i] * suf[i];
    }

    cout << ans << endl;
}