#include<iostream>
using namespace std;

class demo {
      string s;
      int a, b;
public: 
      // demo() = default;
      demo(int pa, int pb, string ps) : a(pa), b(pb), s(ps) {
      }
      demo(): demo(0, 0, "demo") {
      }
      void print() {
            cout << s << " " << a << " " << b <<  endl;
      }
};

int main() {
      demo obj = demo();
      obj.print();
}