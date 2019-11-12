#include<bits/stdc++.h>
using namespace std;

//O(n) approach, works if m < 10^5
// else - lowerbound O(nlogn) aproach

int main()
{
    int n, q, m;
    cin >> n;
    
    // 1 4 5 6 10 
    vector<int> v(n);               // vector in which we find the result 
    vector<int> lessThan(100001);   // vector which stores the less than [index] values for a input 
    
    for(int i = 0; i< n; i++)
        cin >> v[i];

    cin >> q;                       // queries
    sort(v.begin(), v.end());
    int k = 0, i = 0;

    while(k < n)                    // filling the less than vector 
    {
        while((i <= v[k]) && (i <= 100000))
        {
            lessThan[i] = k;
            i++;
        }
        k++;
    }
                                    // filling stops when k = n

    //for remaining indexes in lessThan 
    int rest = lessThan[i-1] + 1;           
    for(int j = i; j <= 100000; j++)
        lessThan[j] = rest;

    // running queries 
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &m);
        printf("%d\n", lessThan[m]);
    }
    
}



