#include<iostream>
using namespace std;

void input(int *ptr);
void square(int *ptr);
void output(int *ptr);

void cinput(char *ptr);
void coutput(char *ptr);
void cupper(char *ptr);

int main()
{
//..............................array..............................
    int arr[5];
    int *p=&arr[0];
//calling input
    input(arr);  // can pass array as whole
// calling output
    output(p);   // can pass pointer
    cout<<" array : ";
    for(int i=0; i<5; i++)
    {
        cout<<(*p)<<" ";
        p++;
    }
    cout<<endl;
// transforming
    square(arr);
// calling output
    output(&arr[0]);  // can pass address
//.........................................string.......................

    char ch[5];
    char *poi=&ch[0];
//calling input
    cinput(ch);  // can pass array as whole
// calling output
    coutput(poi);   // can pass pointer
    cout<<" char array : ";
    for(int i=0; i<5; i++)
    {
        cout<<(*poi);
        poi++;
    }
    cout<<endl;
// transforming
    cupper(ch);
// calling output
    coutput(&ch[0]);  // can pass address

return 0;
}

void input(int *ptr)
{

    for(int i=0; i<5; i++)
    {
        int n;
        cout<<" enter n to input "<<(i+1)<<"st array element: ";
        cin>>n;
        *ptr=n;
        ptr++;
    }
}

void square(int *ptr)
{
    for(int i=0; i<5; i++)
    {
        (*ptr)*=(*ptr);
        ptr++;
    }
}

void output(int *ptr)
{
    cout<<" array : ";
    for(int i=0; i<5; i++)
    {
        cout<<(*ptr)<<" ";
        ptr++;
    }
    cout<<endl;
}

void cinput(char *ptr)
{

    for(int i=0; i<5; i++)
    {
        char c;
        cout<<" enter c to input "<<(i+1)<<"st char array element: ";
        cin>>c;
        *ptr=c;
        ptr++;
    }
}

void cupper(char *ptr)
{
    for(int i=0; i<5; i++)
    {
        (*ptr)=toupper(*ptr);
        ptr++;
    }
}

void coutput(char *ptr)
{
    cout<<" char array : ";
    for(int i=0; i<5; i++)
    {
        cout<<(*ptr);
        ptr++;
    }
    cout<<endl;
}
