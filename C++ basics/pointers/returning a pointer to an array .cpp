#include<iostream>
using namespace std;

typedef int arrT[10];

//arrtT = int[10];
arrT* func(int (*p)[10])  // return a pointer to an array using type alias
{
    return p;
}

int (*func2(int (*p)[10]))[10]  //returns a pointer to an array another method
{
    return p;
}
int main()
{
    int a[10]={1,2,3,4,5};
    int (*poi)[10]=&a;// declaring a pointer to an array
    // poi=&a;
    int (*ptr)[10]=func(poi);
    int (*ptr2)[10]=func2(poi);

    for(int i=0; i<10; i++)
        cout<<(*ptr)[i]<<" ,";
    cout<<endl;

    for(int i=0; i<10; i++)
        cout<<(*ptr2)[i]<<" ,";


    return 0;
}
