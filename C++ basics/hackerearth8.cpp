#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    map<string, long int> phonemap;

    int n;
    string name;
    long int phno;
    vector<string> findit;
    string s;
    cout<<"enter n for no. of test cases"<<endl;
    cin>>n;
    const int N=n;


while(n > 0)
{
    cout<<"enter the string: "<<endl;
    cin>>name;

    cout<<"enter the phone no."<<endl;
    cin>>phno;

    phonemap.insert(pair<string,long int>(name,phno));
    n--;
}

    for(int i=0; i<N; i++)
    {
        cout<<"enter the search"<<endl;
        cin>>s;
        findit.push_back(s);
    }

    for(auto y: findit)
        cout<<y<<endl;

    map<string,long int>::iterator iterb=phonemap.begin(), itere=phonemap.end();
    vector<string>::iterator vsit1=findit.begin(),vsit2=findit.end();
    // error here somewhere in checking

    for(auto x=++iterb; iterb != itere; ++itere)
    {
    for(auto y=vsit1; vsit1 != vsit2; ++vsit1)
    {
        if(iterb->first==*vsit1)
        {
            cout<<"found : "<<iterb->first<<" = "<<iterb->second<<endl;
        }
        else
        {
            cout<<"not found"<<endl;
        }
    }
    }


return 0;
}
