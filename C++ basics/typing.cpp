#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int T;
    cout<<"test cases: ";
    cin>>T;

    while(T--)
    {
        vector<string> all;
        int N,time=0;
        const int n=N;
        cout<<"no. of words: ";
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
            cout<<"cnt = "<<++cnt <<" word - "<<*it <<" "<<all[cnt]<<" ,len = "<<(*it).length()<<" ,time= "<<t<<endl;
int c=0;
            for(int m=0 ; m!= cnt-1; m++)   // checking every word with current word for repetition
            {
                if(all[m]==*it)
                    {
                        c=1;
                        if(c==1)
                            t=t/2;
                        break;
                    }   // the time taken buy the word which is repeated should be half of that time taken to type word for the FIRST time
            }

            time = time + t;
        }
        cout<<"\ntotal time:"<<time;
    }
    return 0;
}
