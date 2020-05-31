#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, zero_counter = 0;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] == 0)
            ++zero_counter;
    }

    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] > 0)
            v[k++] = v[i];
    }

    for(int i = k; i < n; i++)
        v[i] = 0;

    for(int x: v)
        cout << x << " ";
    cout << endl;
}