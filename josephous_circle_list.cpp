#include<bits/stdc++.h>
using namespace std;

// Helper function for finding position of kth element 
list<int>::iterator kthAfter(list<int> &lst, list<int>::iterator it, int k) {
    for(int i=0; i<k-1; i++) {
        it++;
        // move circularly 
        if(it == lst.end()) {
            it = lst.begin();
        }
    }
    return it;
}

int findTheWinner(int n, int k) {
    list<int> lst;
    for(int i=1; i<=n; i++) {
        lst.push_back(i);
    }
    auto it = lst.begin();
    while(lst.size() > 1) {
        auto del = kthAfter(lst, it, k);
        // erase() works in O(1)
        it = lst.erase(del);
        // move circularly
        if(it == lst.end()) {
            it = lst.begin();
        }
    }
    return *lst.begin();
}

int main(){
    return 0;
}