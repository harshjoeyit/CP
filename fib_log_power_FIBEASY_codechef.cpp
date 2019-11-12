#include<bits/stdc++.h>
using namespace std;

vector<int> fibvec(60, 0);

void fibmod(int n = 60) 
{
    fibvec[0] = 0;
    fibvec[1] = 1;

    for(int i = 2; i < n+1; i++ )
        fibvec[i] = (fibvec[i-1] + fibvec[i-2])%10;
}

long long int power(long long int x, unsigned long long int y) 
{ 
    long long int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
} 

long long int log2n(long long int x)
{
    return (x > 1) ? 1 + log2n(x/2) : 0;
}


int main()
{
    fibmod();
    int T;
    cin >> T;
    while(T--)
    {
        long long int N;
        cin >> N;

        long long int term = log2n(N);        
        term = power(2, term) - 1;
        term = term % 60;

        cout<<fibvec[term]<<endl;
    }
}