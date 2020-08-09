#include <iostream>
using namespace std;

// difference b/w array of pointers and pointer ti an array
int main() {
    int a[10] = {1, 2, 3, 4, 5};
    // an array of pointers
    // each poi[i] is capable of holding a address of a int
    int *poi[10];

    for (int i = 0; i < 10; i++) {
        // assigning to every int in array
        // poi[i] = &a[i];
        // or 
        poi[i] = (a + i);
        cout << *poi[i] << " ";
    }
    cout << endl;
        
    // p pointer points to an array of 10 integers
    // is pointer to array 
    int (*p)[10]; 
    // IMP: assigning only base address
    p = &a;      
    
    for (int j = 0; j < 10; j++) {
        cout << (*p)[j] << " ";
    }
    cout << endl;
}
