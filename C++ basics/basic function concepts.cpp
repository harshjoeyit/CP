#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int>::iterator iter(vector<int> ivec, int ser)
{
    auto it1=ivec.begin(),it2=ivec.end();
    for(auto y=it1; y!=it2; it1++)
    {
        if(*it1==ser)
            return it1;
    }

}

void fx(const int *start, const int *finish)  //  nice method to print an array
{
    cout<<endl;
    while(start != finish)
    cout<<*(start++)<<" ";
}

void fx(const char *start, const char *finish)  //  nice method to print an array
{
    cout<<endl;
    while(start != finish)
    cout<<*(start++)<<" ";
}

void change(int A[],string &S)
{
    for(auto i=0; i<5; i++)
        A[i] += 2;

    for(auto i=0; i<5; i++)
        cout<<A[i]<<" ";
    cout<<endl;
    for(auto x=0; x<6; x++)
        S[x]=toupper(S[x]);
    cout<<S<<endl;
}
void f1(const char *p)
{
    if((p))
        while(*(p))
            cout<<*(p++);  // but the last value printed is garbage value.
}

void arrprint(const int a[],size_t sz)
{
    cout<<"\nsize: "<<sz<<"\n array : ";
    for(int x=0; x<sz; x++)
        cout<<a[x]<<" ";
}
int f(const string & ,int a)
{
    return a;
}
int main()
{
    int a[5]={0,50,40,60,70};
    string s("Sangam");
    for(auto x: a)
        cout<<x<<" ";
    cout<<endl;
    cout<<s<<endl;
    change(a,s);
    for(auto x: a)
        cout<<x<<" ";
    cout<<endl<<s;

    vector<int> vec{10,20,30,40,50};
    cout<<endl<<*(iter(vec,50));

    cout<<endl<<f(s,10)<<endl;  // f(10)  not valid , we have to pass all the arguments to all the parameter present in the function
    char arr[25],ar[]={'a','b','c','d'},ch;
    cout<<"value: ";
    gets(arr);  // since null char is present so only required char are printed
    cout<<endl;
    f1(arr);
    cout<<endl;
    f1(ar); // does not have null character so an extra char is printed
    // also if the values are inputted char by char then also no null char
    cout<<endl;
    fx(begin(a),end(a)); // calling the fx function
    fx(begin(ar),end(ar));
    arrprint(a,begin(a)-end(a));

}
