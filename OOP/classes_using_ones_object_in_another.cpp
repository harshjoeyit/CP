#include<bits/stdc++.h> 
using namespace std;

class Box {
      int l, b, h;
public: 
      Box(int l=0, int b=0, int h=0) {
            this->l = l;
            this->b = b;
            this->h = h;
      }
      int volume() {
            return l*b*h;
      }     
};

class Elements {
      Box *bx;
public: 
      Elements(int l=0, int b=0, int h=0) {
            bx = new Box(l, b, h);
      }
      int ret_vol() {
            return bx->volume();
      }
      int ret_ret_vol() {
            return ret_vol();
      }
};

int main() {
      Box b = Box(3, 3, 2);
      Elements el = Elements(10,2,3);
      cout << el.ret_ret_vol();
}