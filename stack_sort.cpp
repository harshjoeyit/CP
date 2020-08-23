#include<bits/stdc++.h>
using namespace std;
#define int long long int

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