#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
 
int power(int val , int n)
{
    val = val%mod;

    if(n < 0)
        return 0;
    if(n == 0)
        return 1 ;
    if (n % 2)
        return  (val*power((val*val)%mod, n/2)) % mod;
    else
        return power((val*val)%mod, n/2);
}
 
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int max_ans = 0 ;
    int k = n;
    for(int i = 0 ; i < n ; i++)
    {
        k--;
        if(s[i] == '1')
            max_ans = (max_ans + power(2,k)) % mod;
    }

    k = n; 
    int curr = max_ans;
    int i = 0;
    int val = power(2, n-1);
    while(i < n)
    {
        if(s[i] == '1') {
            curr = curr - val;
            curr = (curr << 1)%mod + 1; 
        } else {
            curr = (curr << 1)%mod;
        }
        max_ans = max(curr, max_ans);
        i++;
    }
 
    cout<<max_ans<<endl;
    return 0;
}