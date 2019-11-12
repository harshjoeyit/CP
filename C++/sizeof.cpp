#include<iostream>
#include<vector>
using namespace std;

class student
{
   float marks_percent;
   int roll;
   string name;

public:
    int cls;
    student()
    {
          marks_percent=0;
          roll=0;
          name="";
          cls=0;
    }
    void input()
    {
        int rm=10;
        rm=roll;
        cin>>roll;
        cin>>name;
    }
};

main()
{
    // can print without the braces too
    cout<<"size of the class:  "<<sizeof(student)<<endl;
    student obj, *p;
    cout<<"size of member function: "<<sizeof(obj.input())<<endl;
    cout<<"size of object: "<<sizeof /* space is mandatory */obj<<endl;
    cout<<"size of pointer: "<<sizeof(p)<<endl;
    cout<<"size to which pointer points: "<<sizeof(*p)<<endl;
    cout<<"size of obj.cls: "<<sizeof(obj.cls)<<" or: "<<sizeof student::cls<<endl;
    /*the above statement does not require the object since it does not fetch the variable class to know its size */

     int s[7];
     cout<<"size of an array with seven variables: "<<sizeof(s)<<endl;

     cout<<"output"<<endl;
     int x[10];   int *pp = x;
     cout << sizeof(x)/sizeof(*x) << endl;  // ????? don't know how its working
     cout << sizeof(pp)/sizeof(*pp) << endl;


     int m,y=100;
     cout<<sizeof m+y<<endl;// finds size of m and adds it to y
     cout<<sizeof(x+y)<<endl; // correctly prints the size of the integer variable
     cout<<sizeof(y>m)<<endl<<sizeof (bool);  // (y>m) returns a bool
}
