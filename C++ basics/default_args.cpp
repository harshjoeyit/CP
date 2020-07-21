#include<bits/stdc++.h>
using namespace std;

// placing default arguments in the prototype  
void foo1(int a = 10,int b = 12);  

void foo1(int a, int b) {
    cout << a + b << endl;
}

int main() {
    foo1();
    foo1(50);
    foo1(4, 5);
}

