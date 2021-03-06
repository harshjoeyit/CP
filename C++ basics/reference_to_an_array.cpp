#include<iostream>
using namespace std;

using arrtT = int[5];  // arrtT is used as an array of five integers
arrtT &func(int (&r)[5])  // returns reference to array of 5 int (arrtT) after receiving an argument of type of reference to an array
{
    return r;
}

int main() {
    int a[]={1,2,3,4,5};
    int arr[]={10,20,30,40,50};
    // reference to an array. without using arrtT
    int (&r)[5] = a;  

    for(int i=0; i<5; i++) {
        cout << r[i] << " ";
    }cout << endl;

    //  int &ref[5];
    // an array of refernce is not allowed 
    // why ??

    // declaring reference to an array
    arrtT &refer = arr;   

    for(int i=0; i<5; i++) {
        cout << refer[i] << " ";
        refer[i] += 5;
    }cout << endl;

    // declaring another variable to hold the reference to array returned in the function call.
    arrtT &r2 = func(refer);  

    for(int i=0; i<5; i++) {
        cout << r2[i] << " ";
        r2[i] += 3;
    }cout << endl;
    
    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }cout << endl;
    
}
