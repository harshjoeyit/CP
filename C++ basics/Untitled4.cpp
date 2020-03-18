#include<bits/stdc++.h>
using namespace std;

int start = 1;

bool compare ( int a[] , int N)
{
    for(int i=0;  i<N-2; i++)
    {
        if(a[i] != a[i+1])
            return true;
    }
    return false;
}

int main()
{
    vector<int> ans;
    int T;
    cin>>T;
    while(T--)
    {
        int N , turns;
        cin>>N;
        int a[N];

        for(int i=0; i<N; i++)
            cin>>a[i];

        sort(a,a+N);
        int ini = a[0];

        while( compare(a,N) == 1 )
        {
            for(int i = N-1; i>=start;  i--)
            {
                turns = (a[i] - a[i-1]) + 1;

                if( i==start )
                    --turns;

                for(int j=0; j<N; j++)
                {
                    if(j != i)
                        a[j] += turns;
                }
            }
            sort(a,a+N);
       }
       int fin = a[0];
       ans.push_back( fin-ini );
    }

    for(auto it = ans.begin(); it != ans.end(); it++)
        cout<<*it<<endl;

}
