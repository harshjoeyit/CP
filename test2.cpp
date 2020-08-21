#include<bits/stdc++.h>
using namespace std;

class Demo {
public:
      static int x;
      static void print() {
            cout << "static function called\n";
      }
      Demo() {
            cout << "const called\n";
      }
      Demo(int x) {
            x = 2;
            cout << "p c cla";
      }
};

int Demo::x = 19;

int main() {
      Demo::print();
      cout << Demo::x << endl;
      Demo *d = new Demo[10];
}

