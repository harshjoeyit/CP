#include<bits/stdc++.h>
using namespace std;

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


/*
For elemenets >= 0

int _stack :: getMin()
{
    if(s.empty()) {
        return -1;
    } else {
        return minEle;
    }
}

int _stack ::pop()
{
   if(s.empty()) {
       return -1;
   }
   if(s.top() >= 0) {
       int temp = s.top();
       s.pop();
       return temp;
   } else {
       int temp = minEle;
       minEle = minEle - s.top();
       s.pop();
       return temp;
   }
   
}

void _stack::push(int x)
{
    if(s.empty()) {
        minEle = x;
        s.push(x);
        return;
    }
    
    if(x >= minEle) {
        s.push(x);
    } else {
        int temp = x - minEle;
        s.push(temp);
        minEle = x;
    }
}

*/