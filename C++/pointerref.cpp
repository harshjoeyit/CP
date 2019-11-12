#include<iostream>
using namespace std;

int main()
{
int ival = 42; int *n = &ival;
cout << *n <<" "<<ival;
// p holds the address of ival; p is a pointer to ival cout << *p;     /
*n = 30;     // statement meaning: value at n (which is the address of ival indirectly meaning ival)=30
cout << *n <<" "<<ival;



int **poi;
int *po;
int pi=10;
po=&pi;
poi=&po;

cout<<"output \n "<<&pi<<" "<<po<<" "<<poi<<endl;
cout<<*&pi<<" "<<*po<<" "<<*poi<<endl;



int i=10;
double *dub;
int *ptr;
ptr=&i;

cout<<"output \n "<<&i<<" "<<ptr<<" "<<*ptr<<" "<<*&i;

int i2=9;
// const int *const p3; or int *const *p5// since it is a constant pointer i.e. it points to specific variable so we need to initialize it
const int *p4;  //however this is ok
cout<<endl<<*p4; // takes up any arbitrary integer since it a pointer to an integer

int t=11;
int *const ptr1=&t;
int *const ptr2=ptr1;
// ptr1=&i;          operation not possible since the pointer can only point to specific variable initialized
const int tr=*ptr2;
cout<<endl<<tr<<endl;

*ptr2=12;
cout<<t<<endl;  // value of t can be changed t is not of const

const int tst=8;
const int tst1=6;

const int *pp1;
pp1=&tst1;   // the condition of the pointer is that it must point to a const integer whichever it may be
// the address in the pointer can change until the another variable is of const type
cout<<*pp1<<endl;

const int &jj=2;
const auto &hk=i; //hk is bounded to i. hk has the address 0f 2;
cout<<hk<<" "<<sizeof(hk)<<endl;
char c='a';
cout<<" \n"<<sizeof(*ptr)<<endl;
return 0;

}
