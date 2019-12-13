#include<bits/stdc++.h>
using namespace std;

// Value of Counter            Subset
//     000                    -> Empty set
//     001                    -> a
//     010                    -> b
//     011                    -> ab
//     100                    -> c
//     101                    -> ac
//     110                    -> bc
//     111                    -> abc

void power_set(string s)
{
    int n = s.length();

    for(int i = 0; i < pow(2, n); i++)
    {
        int j = i, k = n-1;
        string ans = "";
        cout << "[";

        while(j > 0)                // finding the set bits in j 
        {
            if(1 & j)
                ans = s[k] + ans; 
            j = j >> 1;
            k--;
        }
        cout << ans << "]" << endl;
    }
}

int main()
{
    string s = "abc";
    power_set(s);
}