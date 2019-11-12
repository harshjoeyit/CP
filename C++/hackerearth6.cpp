// to separately print the odd indexed and even index characters
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;


int main()
{
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
cout<<"enter"<<endl;
    int T;
    cin>>T;
    vector<string> vstr;
    string str;

    for(unsigned int i=0; i<T; i++)
    {
        cin>>str;   // getline makes all the problems
        vstr.push_back(str);
    }

    char odd[10000],even[10000];
    long int c1,c2;
    for(int i=0; i<T; i++)
    {
        c1=0; c2=0;

        for(size_t j=0; j<vstr[i].length(); j++)
        {
            if((j%2)==0)
            {
                even[c1]=vstr[i][j];
                c1++;
            }
            else
            {
                odd[c2]=vstr[i][j];
                c2++;
            }
        }
        for(size_t i=0; i<c1; i++)
        cout<<even[i];
        cout<<" ";
        for(size_t i=0; i<c2; i++)
        cout<<odd[i];
        cout<<endl;
    }

    return 0;
}
