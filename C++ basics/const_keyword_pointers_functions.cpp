#include<iostream>
using namespace std;

typedef int number;

// constant as well as non constant arg
void f1(const number &n) {
    cout<<"const number &n called "<<endl;
}

// constant as well as non constant arg
void f2(const number *n) {
    cout<<"const number *n called "<<endl;
}

 // no constant arg
void f1(number &n) {
    cout<<"nunber &n called "<<endl;
}

void f2(number *n) {
    cout<<"number *n called "<<endl;
}

int main() {
    number a=10;
    number &c=a;
    number *p1=&a;

    const number x=12;
    const number &b=a;
    const number *p2=&a;
    const number *p3=&x;

    f1(a);
    f1(c);
    f1(*p1);

    f1(x);
    f1(b);
    f1(*p2);
    f1(*p3);
    cout<<endl;

    f2(&a);
    f2(&c);
    f2(p1);

    f2(&x);
    f2(&b);
    f2(p2);
    f2(p3);
}
