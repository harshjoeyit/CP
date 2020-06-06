#include<iostream>
using namespace std;

int main()
{
    int a[3*3 -4]={1,2,3,4,5};                 // IMPORTANT: initialization
    int (*p)[5]=&a;                     /*array must be initialized with a brace -enclosed initializer*/
    int (&refer)[5]=a;                     // and &a[0] not required

    for(int i=0; i<5; i++)
        cout<<a[i]<<", ";
    cout<<endl;

    for(int i=0; i<5; i++)
        cout<<(*p)[i]<<", ";          // garbage value on *p[i] , (*p)[i] correct way to do this
    cout<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<&a[i]<<" = "<<(p)[i]<<", ";   // not printing the same values
        cout<<endl;
    }

    cout<<(p)[0]<<" "<<(p)[1]<<" "<<(p)[2]<<" "<<(p)[3]<<" "<<(p)[4]<<endl;

    for(int i=0; i<5; i++)
        cout<<refer[i]<<", ";  //prints corresponding value referred to
    cout<<endl;

    for(int i=0; i<5; i++)
        cout<<&refer[i]<<", ";  // prints address of corresponding array element
    cout<<endl;

    for(int i=0; i<5; i++)
        cout<<&p[i]<<", ";

return 0;
}
