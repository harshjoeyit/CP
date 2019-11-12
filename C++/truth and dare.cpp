#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool truthdare(int Ramt[],int cnt1,int Shyamt[],int cnt2)
{
    // for each member of shyam
    for(int s=0; s<cnt2; s++)
    {
        // for each member of ram
        for(int r=0; r<cnt1; r++)
        {
            if(Shyamt[s] != Ramt[r])
            {
                if(r==cnt1-1)
                    return false;
                else
                    continue;
            }
            else
                break;
        }
    }
    return true;
}


int main()
{
    int testcase;
    cout<<"enter th no. of cases : ";
    cin>>testcase;
    vector<string> coll;  // for storing answers

      // loop for test cases

for(int start=0; start<testcase; start++)
    //  truth:
{
    int ramt[105],shyamt[105],sst,srt;
    int c1=0;
    int ramd[105],shyamd[105],ssd,srd;
    int c2=0;

    cout<<"enter size of ramt: ";
    cin>>srt;

    for(int i=0; i<srt; i++)
    {
        int n;
        cin>>n;
        ramt[i]=n;
    }

    cout<<"enter size of ramd: ";
    cin>>srd;

    for(int i=0; i<srd; i++)
    {
        int n;
        cin>>n;
        ramd[i]=n;
    }

    cout<<"enter size of shyamt: ";
    cin>>sst;

    for(int i=0; i<sst; i++)
    {
        int m;
        cin>>m;
        shyamt[i]=m;
    }

    cout<<"enter size of shyamd: ";
    cin>>ssd;

    for(int i=0; i<ssd; i++)
    {
        int m;
        cin>>m;
        shyamd[i]=m;
    }

    if(truthdare(ramt,srt,shyamt,sst))  // checking truth
        c1=1;
    if(truthdare(ramd,srd,shyamd,ssd))  // checking the dare
        c2=1;

    if(c1 && c2)
        coll.push_back("yes");
    else
        coll.push_back("no");

}
//printing the output

    for(int i=0; i<coll.size(); i++)
        cout<<coll[i]<<endl;


    return 0;
}
//successful submission on codechef
