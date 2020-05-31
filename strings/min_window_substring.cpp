#include<bits/stdc++.h>
using namespace std;

bool search_window(int i, int j, string s, string substr)
{
    if(j - i + 1 < substr.length() )
        return false;

    unordered_map<char, bool> present;
    int cnt = 0;

    for(int k = i; k <= j; k++ )
    {
        present[s[k]] = true;
    }

    for(int i = 0; i < substr.length(); i++ )
    {
        if( present[substr[i]] )
            ++cnt;
    }

    //cout << "i: "<< i << " j: " << j << endl;

    if(cnt == substr.length() )
    {
        //cout <<"cnt = len"<<endl;
        return true;
    }
    else
    {
        
        return false;
    }
}


bool current_window(int wind_size, string s, string substr)
{
    int n1 = s.length();

    for(int i = 0; i < n1-wind_size; i++ )
    {
        if(search_window(i, i + wind_size, s, substr))
            return true;
    }

    return false;
}



int min_window_size(int l, int h, string s, string substr)
{
    int ans = -1;
    while(l <= h)
    {
        int mid = l + (h-l)/2;
        
        //cout << "mid: " << mid << endl;

        if(current_window(mid, s, substr))
        {
            ans = mid;
            h = mid - 1;
        }
        
        else
        {
            l = mid + 1;
        }
    }
    return ans+1;           // returns 0 if the if substring is not found in the string 
}



int main()
{
    string substr = "abcde";
    string s = "alllllllelcdlballllllclldl";
    cout << s.size() << endl; 
    cout << min_window_size(0, s.length()-1, s, substr )<<endl;
}