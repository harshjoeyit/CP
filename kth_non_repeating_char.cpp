#include<bits/stdc++.h>
using namespace std;

int first_non_repeating_char(string &s)
{
    //        counter, index
    vector<pair<int, int>> v(256);
    int min_index = INT_MAX;

    for(int i = 0; i < s.length(); i++)
    {
        int j = s[i] - 'a';
        ++v[j].first;
        v[j].second = i;
    }
    
    for(auto &x: v)
        if(x.first == 1)
            min_index = min(min_index, x.second);
    
    return min_index;               // return the min_index of all the characters that have frequency = 1 
}

int kth_non_repeating_char(string &s, int k)
{
    //        counter, index
    vector<pair<int, int>> v(256);
    vector<int> freq_one;

    for(int i = 0; i < s.length(); i++)
    {
        int j = s[i] - 'a';
        ++v[j].first;
        v[j].second = i;
    }
    
    for(auto &x: v)
        if(x.first == 1)
            freq_one.push_back(x.second);

    sort(freq_one.begin(), freq_one.end());
    for(int i = 0; i < freq_one.size(); i++)
    {
        if(i+1 == k)
            return freq_one[i];
    }
    return -1;
}

int main()
{
    int k;
    string s;
    cin >> s;
    cin >> k;
    int i = first_non_repeating_char(s);
    cout << i << endl;

    i = kth_non_repeating_char(s, k);
    cout << i << endl;
}