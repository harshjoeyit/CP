#include<bits/stdc++.h>
using namespace std;


int main()
{
    int magic_square[5][5];

    int i = 0;
    int j = 5/2;

    for( int Ai = 1; Ai <= 5*5; Ai++ )
    {
        magic_square[i--][j--] = Ai;            // i = i-1 , j = j -1 

        if( Ai % 5 == 0 )                   // we go down whenever we find that Ai % n == 0 
        {
            j++;                            // j has already been decremented so we need to increment it to give it a value present initially ++j , compensated --j
            i = ( i+2 )% 5;                 // same goes for i , also since we go down i needs to be incremented by one more 
        }
        else
        {
            i = (i<0) ? (i+5) : i;          // if the index out bound exception occurs then we go circularly 
            j = (j<0) ? (j+5) : j;
        }
    }

    for( int i = 0 ; i<5; i++ )
    {
        for( int j = 0; j<5; j++ )
            cout<<magic_square[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;

}
