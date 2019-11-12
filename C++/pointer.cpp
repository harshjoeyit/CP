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
return 0;

}
