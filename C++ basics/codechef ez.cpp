// take input infinitely and stop processing input after 42 appears
#include<bits/stdc++.h>
using namespace std;

main()
{
    vector<int> out;
    int x;
    while(cin>>x)
            out.push_back(x);
    for(int i=0; out[i] != 42; i++)
        cout<<out[i]<<endl;
}
