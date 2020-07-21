#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    const int j = i;
    ++i;
    const int k = i;
    cout << j << " " << k << endl;
    const int &b = i;
    ++i;
    // b is bound to i
    cout << b << endl;
    // ++b;
    // not valid 


    double dval = 3.14;
    const int &ri = dval;
    // the above two statement suggest
    // const int temp = dval;   
    // create a temporary const int from the double 
    // bind ri to that temporary
    // const int &ri = temp;
    dval += 10;
    // ri is bound to that temp not dval, so unchanged
    cout << "ri: " << ri << endl;
    


    const double *cptr = &dval; 
    // can point to an object that is not a pointer. but can not change its value.
    dval += 10;
    // *cptr += 1;
    // invalid
    cout <<*cptr << endl;


    
    int errNumb = 0;  
    // constant pointer 
    int *const curErr = &errNumb;     
    // this is a constant pointer: meaning that it points to errNumb 
    // but can change its value since the variable errnumb is not const
    int newVal = 10;
    *curErr = newVal;
    // curErr = &newVal;
    // invalid 

    cout << errNumb << endl;

    // pointer to constants 
    const int cval = 10;
    const int *consPtr = &cval;
    // *consPtr = 50;
    // invalid - a pointer to constant value

    const int newConst = 20;    
    consPtr = &newConst;
    cout << *consPtr << endl;


    // constant pointer to constants 
    const int *const cpc = &cval;
    // *cpc = -1;
    // invalid 
    // cpc = &newConst;
    // invalid

}
