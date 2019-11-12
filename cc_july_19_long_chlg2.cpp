#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    cin>>T;

    while( T-- )
    {
        int N , rem , S2;
        string K;
        cin>>N>>K;

        rem = 0;            // since k is extremetly large of order 10^10000
        // we find remainder using the following code 
        for( int i = 0; i< K.length(); i++ )
            rem = (rem*10 + static_cast<int>(K[i]) - '0' ) % N;

        // remaining conditions are based on pattern observed 
        if( rem == N/2 )
            S2 = N-1;
        else
        if( rem < N/2 )
            S2 = rem*2;
        else
        if( rem > N/2 )
            S2 = ( N - rem )*2;
            
        cout<<S2<<endl;
    }
}