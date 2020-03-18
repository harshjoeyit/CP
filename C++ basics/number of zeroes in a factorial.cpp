// NUMBER OF ZEROES IN A FACTORIAL
// TIP: NEED NOT FIND THE FACTORIA; FIND THE MULTIPLE OF 5

#include<bits/stdc++.h>
using namespace std;
main()
{
    long long int T;
    vector<long long int>  ans;
    cin>>T;
    while(T--)
    {
        long long int N,zeroes=0;
        cin>>N;

        while(N != 0)  // can also be done using recursion but IS 10 TIMES MORE TIME CONSUMING
        {
            zeroes += N/5;
            N = N/5;
        }
        ans.push_back( zeroes );
    }
    for(auto it= ans.begin(); it != ans.end(); it++)
        cout<<*it<<endl;
}
