#include<bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &st, int val) {
	if(st.empty()) {
		st.push(val);
		return;
	}
	int hold = st.top();
	st.pop();
	insertBottom(st, val);
	st.push(hold);
}

void reverse(stack<int> &st) {
	if(st.empty()) {
		return;
	}
	int t = st.top();
	st.pop();
	reverse(st);
	insertBottom(st, t);
}

void print(stack<int> st) {
	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main() {
    stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	
	print(st);
	reverse(st);
	print(st);
}