#include<stdio.h>

void f1(void);
void f2();

void f1()
{
    printf("hello\n");
}

void f2()
{
    printf("hello\n");
}

int main()
{
    f1();  // if arguments are given , error is shown
    f2(1,'a',3.34);   // in C++  even this shows an error
    return 0;
}
