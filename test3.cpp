#include <iostream>
using namespace std;

bool is_sffld_palin(string s)
{
    int a[26] = {0}, odd_cnt = 0;
    for(int i = 0 ; i<s.length() ; i++)
        a[s[i]-'a']++;
    for(int i = 0 ; i<26 ; i++)
        if(a[i]%2 != 0)
            odd_cnt++;
    return odd_cnt <= 1;            
}

void solve(string str)
{
        int s = 0, e = str.length()-1, swaps = 0;
        if(is_sffld_palin(str))
        {
            while(s<e)
            {
                if(str[s] != str[e])
                {
                    int k = e;
                    while(k > s && str[k] != str[s])
                        k--;
                        
                    if(k == s)
                    {
                          swap(str[s], str[s + 1]);
                          swaps++;
                    }
                    else
                    {
                        while(k<e)
                        {
                              swap(str[k], str[k + 1]);
                              k++;
                              //cout<<str<<"\n";
                              swaps++;
                        }
                        s++;
                        e--;
                    }
                }
                else
                {
                    s++;
                    e--;
                }    
            }
            cout<<swaps<<endl;
        }
        else
            cout<<"Impossible"<<endl;
}

int main()
{
    string s;
    while(cin>>s)
    {
        if(s == "0")
            break;
        solve(s);        
    }
}