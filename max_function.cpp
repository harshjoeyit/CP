#include<bits/stdc++.h>
using namespace std;


bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    
    return (p1.first < p2.first);
}


void disp(pair<int, int> p)
{
    cout<<p.first<<","<<p.second<<endl;
}


int main()
{
    pair<int, int> p[] = {{1,2},{5,6},{5,4},{1,1}};

    pair<int, int> q = max(p[0], p[1], comp);
    disp(q);
    q = max(p[1], p[3], comp);
    disp(q);
    q = max(p[0], p[3], comp);
    disp(q);
    q = max(p[1], p[2], comp);
    disp(q);

    cout << max('a', 'b') << endl;
}