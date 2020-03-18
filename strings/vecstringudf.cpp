// to change all strings of a vector to uppercase

#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

void input(vector<string> &vstr)
{
    int c=1,n=0;
    while(c!=0)
    {
       string s;
       cout<<"\nenter the "<<n<<"th string of the vector : ";
       cin>>s;  //????  find why can't use getline(cin,s)
       vstr.push_back(s);
       cout<<"\n  press 0 to stop adding and any other no. to continue : ";
       cin>>c;
       n++;
    }
}

void allcaps(vector<string> &vstr)
{
    for(unsigned int i=0; i<vstr.size(); ++i)
        {
            for(unsigned int j=0; j<vstr[i].size(); ++j)
            {
                if(islower(vstr[i][j]))
                vstr[i][j]=toupper(vstr[i][j]);
            }
        }
}

void output(vector<string> &vstr)
{
    cout<<" vector string: ";
    for(unsigned int i=0; i<vstr.size(); ++i)
        cout<<vstr[i]<<" , ";
}

int main()
{
    vector<string> vpstr;
    input(vpstr);

    cout<<"\noriginal ";
    output(vpstr);

    allcaps(vpstr);
    cout<<"\ntransformed ";
    output(vpstr);

    return 0;
}
