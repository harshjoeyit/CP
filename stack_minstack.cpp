#include<bits/stdc++.h>
using namespace std;

// 1) a simple implementation is using a pair of stack 

// 2) another solution is using a single stack 
/*
main logic is 

Min element - current minimum element in the stack is stored in minEle var and can be accesed in O(1)

Push (x) -
    when x >= minEle, push(x),             minEle unchanged
    when x <  minEle, push (2*x - minEle), minEle = x

Pop (x) - 
    when x >= minEle,                      minEle unchanged
    when x <  minEle, return minELe,       minEle = 2*minEle - x

............................................................

Why we choose 2 as a factor 
consider case 

push(x), x < minEle

x < minEle
2*x < 2*minEle

2*x - minEle < minEle

this works as a condition for us to check while popping 
while popping we check if popped is < minEle or not 

Also,

x < minEle
x - minEle < 0

2*x - minEle < x

this x value is always less than the actual x value 

*/


struct MyStack {
    stack<int> s;
    int minEle;

    void getMin() {
        if(s.empty()) {
            cout << "stack is empty!\n";
            return;
        } 
        cout << "min: " << minEle << "\n";
    }

    void peek() {
        if(s.empty()) {
            cout << "stack is empty!\n";
            return;
        } 
        int t = s.top();
        cout <<"top: ";
        (t < minEle) ? cout << minEle: cout << t;
        cout << "\n";
    }

    void pop() {
        if(s.empty()) {
            cout << "stack is empty!\n";
            return;
        }
        cout << "rem: ";
        int t = s.top();
        s.pop();
        
        if(t < minEle) {
            cout << minEle << "\n";
            minEle = 2*minEle - t;
        } else {
            cout << t << "\n";
        }
    }

    void push(int x) {
        if(s.empty()) {
            minEle = x;
            s.push(x);
            cout << "push: " << x << "\n";
            return;
        }

        if(x < minEle) {
            s.push(2*x - minEle);
            minEle = x;
        } else {
            s.push(x);
        }
        cout << "push: " << x << "\n";
    }
};


int main() {
    MyStack s;
    s.push(3); 
    s.push(5); 
    s.getMin(); 
    s.push(2); 
    s.push(1); 
    s.getMin(); 
    s.pop(); 
    s.getMin(); 
    s.pop(); 
    s.peek();
}

