#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
    int T;
    cin>>T;
    vector<string> vstr;
//input strings in a vector
    while(T--)
    {
        string str;
        cin>>str;     // problem in input by getline function ; takes one less input
        vstr.push_back(str);
    }
// taking string one by one
    for(auto x=vstr.begin(); x!=vstr.end(); x++)
    {
        int alphacount[26]={};  // setting every element to 0;
        string check=*x;
// checking every char of the string
        for(unsigned int y=0; y<check.length(); y++)
        {
            for(int ch=97; ch<=122; ch++)
            {
                char alpha=ch;
                int index=0;
                if(check[y]==alpha)  // comparing each element with with lower case alphabets
                {
                    ++alphacount[ch-97];  // storing in an array pf 26 elements at corresponding position
                }
            }
        }
        //find the max of the array which becomes LHS value in the fibonnaci sequence
        //  calculate max value
        int maxx=-9999,pos=0,sum=0,c=0;
        for(int j=0; j<26; j++)
        {
            if(alphacount[j]>maxx)
            {
                maxx=alphacount[j];
                pos=j;
            }
        }
        //sum of est elements other than max
        for(int k=0; k<26; k++)
        {
            if(alphacount[k] != 0)
                 ++c;
            if(k!=pos)
                sum=sum+alphacount[k];
        }
        // condition
        if(maxx==sum || c<3)
            cout<<"Dynamic"<<endl;
        else
            cout<<"Not"<<endl;
    }

}
