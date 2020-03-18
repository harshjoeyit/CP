#include<bits/stdc++.h>
using namespace std;

bool checkprime(long long int N) 
{
        int count = 0;
        for( int i = 1;i * i <=N;++i ) {
             if( N % i == 0) {
                 if( i * i == N )
                         count++;
                 else       // i < sqrt(N) and (N / i) > sqrt(N)
                         count += 2;
              }
        }
        if(count == 2)
            return true;
        else
            return false;
}

bool checkprime2(long long int N)
{
    int count = 0;
        for( int i = 2; i * i <=N;++i )
             if( N % i == 0) 
                            count++;
        
        if(count == 0)
            return true;
        else
            return false;
}

int main( ) 
{
    for(auto i = 0; i<= 50; i++ )
     {   
         if(checkprime(1000000000 + i))
            cout<<1000000000 + i<<endl;
   // checkprime2(101);
     }
    return 0;   
}
