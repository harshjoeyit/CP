#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<int> give;
    vector<int> rec;
    vector<bool> used(n+1);
    used.assign(n+1, false);
    vector<int> v(n+1);

    for(int i = 1; i <= n; i++)                 // initially given who gifts to whom
    {
        cin >> v[i];
        used[v[i]] = true;
        if(v[i] == 0)                           // 0 if he cannot dicide whom to gift 
            give.push_back(i);
        
    }
    for(int i = 1; i <= n; i++)
        if(!used[i])
            rec.push_back(i);
    
    for(int i = 0; i < give.size(); i++)
    {
        if(give[i] == rec[i])                       // logic: swapping if similar val found in both the arrays 
        {
            if(i == 0)
                swap(give[i], give[i+1]);                          
            else
                swap(give[i], give[i-1]);
        }
    }

    for(int i = 0; i < give.size(); i++)
        v[give[i]] = rec[i];

    for(int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
}