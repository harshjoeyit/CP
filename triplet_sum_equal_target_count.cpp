

#include<bits/stdc++.h>
using namespace std;


// if we want unique pairs only 
// use a set to store the triplets 
// or use this algo after removing duplicate element from original array(a)
void print(int a, int b, int c) {
      cout << a << " " << b << " " << c << endl;
}

void triplets(vector<int> &a, int target) {
      sort(a.begin(), a.end());

      for (int i = 0; i < a.size(); i++) {
            int st = i + 1;
            int en = a.size() - 1;

            while (st < en) {
                  int s = a[i] + a[st] + a[en];
                  if (s == target) {
                        print(a[i], a[st], a[en]);
                        st -= 1, en -= 1;
                  } else if(s > target) {
                        en -= 1;
                  } else {
                        st += 1;
                  }
            }
      }
}


int main() {
      int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

      // triplets(a, t);
      tripletsCount(a, t);
}