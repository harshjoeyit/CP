/*
    https://practice.geeksforgeeks.org/problems/sort-a-stack/1
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

// ITERATIVE
// smallest element is on the top
stack<int> sortStack(stack<int> &s) {
    stack<int> tmpStack;

    while(!s.empty()) {
        int tmp = s.top();
        s.pop();

        while(!tmpStack.empty() && tmpStack.top() < tmp) {
            s.push(tmpStack.top());
            tmpStack.pop(); 
        }

        tmpStack.push(tmp);
    }
    return tmpStack;
}


// RECUSRSIVE 
// Variant of Reverse stack using recursion.

// function to place the value at correct place (maintaing the sort order)
// example - 5, 4, 2, 1  =>  sortedInsert(3) gives  =>  5, 4, 3, 2, 1
void sortedInsert(stack<int> &s, int val) {
    if(s.empty() || s.top() <= val) {
        s.push(val);
    }
    else {
        int t = s.top();
        s.pop();
        sortedInsert(s, val);
        s.push(t);
    }
}

void sortStackRec(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    // remove the top most element 
    int t = s.top();
    s.pop();
    // sort the remaining stack 
    sortStackRec();
    // place the removed element in its correct place
    sortedInsert(s, t);
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    s.push(5);
    s.push(1);
    s.push(8);
    s.push(3);

    stack<int> ss = sortStack(s);

    while(!ss.empty()) {
        cout << ss.top() << " ";
        ss.pop(); 
    }

}