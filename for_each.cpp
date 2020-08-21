#include<bits/stdc++.h>
using namespace std;

void printx(int a) {
    cout << a << " ";
}

class util {
    public:
    void operator() (int a) {
        cout << a << " ";
    }
}ob1;

int main() {
    int arr[6] = {1, 3, 4, 6, 7, 2};
    for_each(arr, arr+6, printx);
    cout << "\n";

    // lambda expression
    // NOTE: no functions can be called from inside lambda
    for_each(arr, arr+6, [](int &a){            // arguement is a reference - changes are reflected in the original 
        a = a+2;
        cout << a << " ";
    });
    cout << "\n";

    // NOTE: ob1 - object function 
    for_each(arr, arr+6, ob1);
    cout << "\n";

    // NOTE: for each also throws exceptions
}