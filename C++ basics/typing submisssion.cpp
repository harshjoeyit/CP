#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        vector<string> all;
        int N,time=0;
        const int n=N;
        cin>>N;

        while(N--)
        {
            string word;
            cin>>word;
            all.push_back(word);
        }
        int cnt=0;
        for(auto it= all.begin(); it != all.end(); it++)
        {
            int t=2;
            for(int k=1; k< (*it).length(); k++)  // loop works from 1 leaving the first character
            {
                if( (*it)[k]=='f' || (*it)[k]=='d')
                {
                    if( (*it)[k-1]=='k' || (*it)[k-1]=='j' )
                        t += 2;
                    else
                    if( (*it)[k-1]=='f' || (*it)[k-1]=='d' )
                        t += 4;
                }
                else
                if( (*it)[k]=='k' || (*it)[k]=='j')
                {
                    if( (*it)[k-1]=='d' || (*it)[k-1]=='f')
                        t += 2;
                    else
                    if( (*it)[k-1]=='k' || (*it)[k-1]=='j' )
                        t += 4;
                }
            }
            ++cnt;
            int c=0;
            for(int m=0 ; m!= cnt-1; m++)   // checking every word with current word for repetition
            {
                if(all[m]==*it)
                    {
                        c=1;
                        if(c==1)
                            t=t/2;
                        break;
                    }
            }

            time = time + t;
        }
        cout<<time<<endl;
    }
    return 0;
}
// successful submission
