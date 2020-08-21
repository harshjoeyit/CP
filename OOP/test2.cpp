#include<bits/stdc++.h>
using namespace std;

class A {
public: 
      static int b;
      int a = 10;
};

int A::b = 10;


int main() {
      cout << A::b << endl;
}