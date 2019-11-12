// codechef 
// july 29 - long challenge 
// problem
/*

 */
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;

    while( T-- )
    {
        long int N;
        long long int Ai , sum=0;
        cin>>N;

        multimap< long long int , int > coins;

        for( int i = 0; i<N; i++ )
        {
            cin>>Ai;
            coins.insert({Ai , i+1 });
            sum += Ai;
        }

        long double d_mean = static_cast<long double>(sum)/N;
        long long int i_mean = sum/N;

        if( (d_mean - i_mean) == 0)
        {
            auto it = coins.find(i_mean);
            if( it != coins.end() )
                cout<<it->second<<endl;
            else
                cout<<"Impossible"<<endl;
        }
        else
            cout<<"Impossible"<<endl;
        
    }
}