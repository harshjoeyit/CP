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
//indirect way of saying that address of r is same as i;
int &r=*po;

cout<<"output \n "<<&pi<<" "<<po<<" "<<poi<<endl;
cout<<*&pi<<" "<<*po<<" "<<*poi<<endl;
cout<<r<<endl;


int i=10;
double *dub;
int *ptr;
ptr=&i;
// this is a pointer variable reference to the pointer .both the pointer and the variable have same address.
int *&r1=ptr;

cout<<"output \n "<<&i<<" "<<ptr<<" "<<*ptr<<" "<<*&i<<endl;;
cout<<r1<<endl;

 //holds address of any type of variable
void *pointer;
pointer=&i;
cout<<" "<<&i<<" "<<pointer<<endl<<sizeof(pointer)<<endl;

double obj = 3.14,
*pd = &obj;
cout<<pd<<endl;
// ok: void* can hold the address value of any data pointer type void
void *pv = &obj;
// obj can be an object of any type
pv = pd;
cout<<pv<<endl<<sizeof(pv)<<endl;

return 0;
}
