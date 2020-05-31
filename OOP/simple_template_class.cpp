#include<bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> 
class vectorPair {
      vector<pair<T1, T2> > v;
public:
      vectorPair() = default;
      vectorPair(T1 val1, T2 val2, int n = 0) {
            v.assign(n, make_pair(val1, val2));
      }
      void add(T1 val1, T2 val2) {
            v.push_back(make_pair(val1, val2));
      }
      void remove() {
            v.pop_back();
      }
      pair<T1, T2> peek() {
            return v.back();
      }
      void display() {
            for(auto x: v) {
                  cout << x.first << " " << x.second << endl;
            }
      }
      void Sort() {
            sort(v.begin(), v.end(), comp);
      }
      // comparitor for class 
      // check why we use static here and why we cannot use const after arguments in static function
      bool static comp (const pair<T1, T2> &a, const pair<T1, T2> &b) {
            if(a.second == b.second) {
                  return a.first < b.first;
            }
            return a.second < b.second;
      }
};

int main() {
      vectorPair<string, int> vp1;
      vectorPair<float, int> vp2(1.5, 1, 5);
      vp2.display();

      vp1.add("raju", 125);
      vp1.add("kishan", 23);
      vp1.add("kamli", 56);
      vp1.display();

      vp1.remove();

      auto p = vp1.peek();
      cout << "last elements: ";
      cout << p.first << " " << p.second << endl;

      vp1.add("rakesh", 125);
      vp1.add("kanahiya", 23);
      vp1.add("kaper", 56);

      vp1.Sort();
      vp1.display();
}