#include<bits/stdc++.h>
using namespace std;

class A {
public: 
      A() {
            cout << "A constructor\n";
      }
      ~A() {
            cout << "A d\n";
      }
};

class B: public A {
public: 
      B() {
            cout << "B constructor\n";
      }
      ~B() {
            cout << "B d\n";
      }
};

class C: public B {
public: 
      C() {
            cout << "C constructor\n";
      }
      ~C() {
            cout << "C d\n";
      }
};

int main() {
      auto c = new C();
      delete c;
}