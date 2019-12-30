// The awkwardness of this configuration of students
// is defined as the sum of pairwise distances between
// each boy and girl. The distance between the i-th and
// j-th student in the line is |i−j|. Formally, the awkwardness is

// summation(1 to n (summation(i+1 to n)(j-i)))
                            // s[i] != s[j]
// ith and jth items are different 


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        ll size = str.size();
        ll countb = 0ll;
        ll countg = 0ll;
        
        for(ll i=0ll;i<size;i++)
        {
            if(str[i]=='g')
                countg++;
            else
                countb++;
        }
    //    cout << countb << " " << countg << "\n";
        if(countg<countb)
        {
            ll temp = countb;
            countb = countg;
            countg = temp;
        }
        str = "";
        ll temp = countg-countb;
        ll temp1 = temp/2;
        ll temp2 = temp-temp1;
        for(ll i=0;i<temp1;i++)
            str += "g";
        for(int i=0;i<countb;i++)
            str += "gb";
        for(ll i=0;i<temp2;i++)
            str += "g";
        ll ans = 0ll;
        ll Nb = 0ll;
        ll Ng = 0ll;
        for(ll i=0ll;i<size;i++)
        {
            if(str[i]=='g')
            {
                ans += i*Nb - i*(countb-Nb);
                Ng++;
            }
            else
            {
                ans += i*Ng - i*(countg-Ng);
                Nb++;
            }
        }
        cout << ans << "\n";
    }
}