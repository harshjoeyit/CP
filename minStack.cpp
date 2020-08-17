#include<bits/stdc++.h>
using namespace std;

// 1) a simple implementation is using a pair of stack 

// 2) another solution is using a single stack 
/*
main logic is 

Min element - current minimum element in the stack is stored in minEle var and can be accesed in O(1)

Push (x) -
    when x >= minEle, no updates in minEle
    when x < minEle, push (2*x - minEle) and minEle = x

Pop (x) - 
    when x >= minEle, no updates in minEle
    when x < minEle, return minELe, minEle = 2*minEle - x

............................................................

Why we choose 2 as a factor 
consider case - to be pushed ele < minEle

pushed < minEle
2*pushed < 2*minEle

2*pushed - minEle < minEle
>> this works as a condition for us to check while popping 
>> while popping we check if popped is < minEle or not 


Also,

pushed < minEle
pushed - minEle < 0

2*pushed - minEle < pushed
>> this pushed value is always less than the actual pushed value 

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

