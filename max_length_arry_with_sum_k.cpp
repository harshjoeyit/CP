#include<bits/stdc++.h>
using namespace std;

int n, k;

// naive lmax 
int max_length_arry_with_sum_k(vector<int> v)
{
    int lmax = 0;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += v[j];
            if(sum == k)
                lmax = max(lmax, j-i+1);
            
        }
    }

    return lmax;
}

int max_length_arry_with_sum_k_efficient(vector<int> v)
{
    int s = 0, lmax = 0;
    unordered_map<int, int> m;

    for(int i = 0; i < n; i++)
    {
        s += v[i];

        if(s == k)
            lmax = i+1;
        
        if(m.count(s) == 0)
            m[s] = i;
        
        if(m.count(s - k) != 0)
            lmax = max(lmax, i-m[s-k]);
    }

    return lmax;
}


int main()
{
    
    cin >> n >> k;
    vector<int> v(n);

    for(auto &x: v)
        cin >> x;
    
    cout << max_length_arry_with_sum_k(v) << endl;
    cout << max_length_arry_with_sum_k_efficient(v) << endl;
}