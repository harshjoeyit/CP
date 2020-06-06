#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cout<<"T: ";
    cin>>T;
    vector<int> ans;

    while( T-- )
    {
        string S;
        cin>>S; 
        int D , i , j , Att = 0 , p = 0,proxy = 0 ,diff;
        cin>>D;
        int b[D];               // array for storing indices where P occurs in S

        for( i = 0; i < D; i++ )
        {
            if( S[i] == 'P' )
                b[Att++] = i;       // inputting the indices , Att is actual present days
        }

        for( j = 0; (j < Att - 1)&&( D > 4); j++ )
        {   
            diff = b[j+1] - b[j];                           // difference between two consecutive indices where p occurs 

            if( diff == 4)                                  // PAAAP diff 4 ,1 proxy possible
                p = 1;
            else if( diff < 4 )                             // PAP  diff 2 , 1 proxy possible
                p = diff - 1;
            else                                                // PAAAAAAAAAAAP  no proxy possible
                p = 0;

            if( (diff < 4) && ( b[j] == 0 || b[j+1] == D - 1))      // making exception for cases when P occurs at 0 and size - 1 index in S  PA A PAP  // only 1 proxy possible
                p--;
           
           for( i = 1; (i <= p)&&((float)( Att + proxy)/D <0.75); i++)          // incrementing proxies , loop ,since p can be 2 and only adding 1 may fulfills condition
                ++proxy;
        }

        if( (float)( Att + proxy)/D >= 0.75 )
            ans.push_back(proxy);
        else
            ans.push_back(-1);
    }
    for( auto it = ans.begin(); it != ans.end(); it++ )
        cout<<*it<<endl;
}