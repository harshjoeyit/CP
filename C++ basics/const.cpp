#include<iostream>
using namespace std;

int main()
{
    int i=9;
    const int j=i;
    ++i;
    const int l=i;
    cout<<j<<" "<<l;
    const int &b=i;
    cout<<" \n"<<b;

    double dval = 3.14;
    const int &ri = dval;
    // the above two statement suggest
    //const int temp = dval;   // create a temporary const int from the double const int &ri = temp;
    // bind ri to that temporary
    cout<<endl<<ri<<" ";

    float f=8.25;
    const int &u=f;
    cout<<u<<" "<<f;

    const double *cptr = &dval; // can point to an object that is not a pointer. but can not change its value.
    cout<<"\n "<<*cptr;


   // const int errNumb = 0;
   // const int *const curErr = &errNumb;    // a pointer of CONST variable type (her const int ) is must to point to a const type variable (here errnumb)
   //  *curErr= 10; // illegal
   // cout<<errNumb;

    // illegal *cur = 9;
     // cout<<" \n"<<errNumb;

 /* const not present so value can change */    int errNumb = 0;  // however for variable that is  not of const type a pointer which is not of type cont would work
  /*const not requuired before */  int *const curErr = &errNumb;     // this is a constant pointer: meaning that it points to errNumb but can change its value since the variable errnumb is not const
     *curErr= 10;
    cout<<errNumb;

     return 0;
}
