#include<bits/stdc++.h>
using namespace std;

void printDetails(vector<int> &v) {
      for(auto x: v) {
            cout << x << " ";
      }cout << endl;
      cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
}

void Push(vector<int> &v, int n) {
      while(n--) {
            v.push_back(n);
      }
} 

void assignMethod() {
      vector<int> v;
      // hover and read about method
      v.assign(10, -1);
      printDetails(v);
      Push(v, 2);
      printDetails(v);
}

void reserveMethod() {
      vector<int> v;
      // hover and read
      v.reserve(5);
      printDetails(v);
      Push(v, 2);
      printDetails(v);
      Push(v, 6);
      printDetails(v);
}

void resizeMethod() {
      vector<int> v;
      // hover and read
      Push(v, 5);
      printDetails(v);
      v.reserve(20);
      printDetails(v);
      v.resize(3);
      printDetails(v);
}

int main() {
      // assignMethod();
      // reserveMethod();
      resizeMethod();
}