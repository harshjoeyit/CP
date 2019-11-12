#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={10,0,2,8,6,7,4,3,5,2,1,9};
    set<int> s;
    int  c=0,sizeofa = sizeof(a)/sizeof(int),n=10;

    for(int i=0; i<sizeofa; i++)
    {
        s.insert(a[i]);
        if(s.find(n-a[i]) != s.end())  // this does not work in the case when a[i]==5 since 10-5=5 is already
        {                               // inserted so it shows 2 5's are present which is not o
            cout<<a[i]<<"+"<<(n-a[i])<<"="<<n<<endl;
            ++c;
        }
    }
    cout<<c;
}
