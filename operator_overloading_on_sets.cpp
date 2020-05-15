#include<bits/stdc++.h>
using namespace std;

// operator overloading on sets 
struct comp {
    
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {

        int lena = a.second - a.first + 1;
        int lenb = b.second - b.first + 1;
        // if segment lengths are equal then 
        // choose the one with lower start index
        if(lena == lenb) {
            return a.first < b.first;
        }
        // else choose the segment with larger length
        return lena > lenb;
    }
};

int main() {

    // custom comparitor for sorting segments  
    set<pair<int, int>> segs;
    segs.insert({1, 4});
    segs.insert({5, 5});
    segs.insert({7, 8});
    segs.insert({6, 6});
    segs.insert({9, 10});

    for(auto x: segs) {
        cout << x.first << " " << x.second << endl;
    }
}