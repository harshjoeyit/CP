#include<bits/stdc++.h>
using namespace std;

// Longest_Subarray_with_Sum_>=0

void naive(vector<int> v)
{
    for(int i = 1; i <= n; i++)
        v[i] += v[i-1];

    
    int lmax = 0;
    for(int i = 1; i <= n; i++)      // starting index subarray
    {
        for(int j = i; j <= n; j++)      // ending index of subarray
        {
            if(v[j] -  v[i-1] >= 0)
                lmax = max(lmax, j-i+1);

            //cout << v[i-1] << " " << v[j] << endl;
        }
    }
    cout << lmax << endl;
}


void eff()
{

}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1);

    for(int i = 1; i <= n; i++)
        cin >> v[i];

    naive(v);

}
