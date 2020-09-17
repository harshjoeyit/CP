
#include<bits/stdc++.h>
using namespace std;

struct Node  { 
    char data; 
    Node *left, *right;
    Node(char _data) : data(_data), left(NULL), right(NULL) {};
}; 

/*
Idea is that we traverse a string make first character as root and do following step recursively .

1.  If we see Symbol ‘?’
    then we add next character as the left child of root.
2.  If we see Symbol ‘:’
    then we add it as the right child of current root.

do this process until we traverse all element of “String”.
*/

Node *convertToBST(string &expr, int &i) {

    Node *n = new Node(expr[i]);
    if(i == expr.length() - 1) {
        return n;
    }

    // skip char 
    i += 1;
    if(expr[i] == '?') {
        // skip '?'
        i += 1;
        n->left = convertToBST(expr, i);
        // Notice after the below recursive call i will point to ':' 
        // just before the right child of current node since we pass i by reference
        // skip ':' 
        i += 1;
        n->right = convertToBST(expr, i);
    }

    return n;
}

void print(Node *root) {
    if(root) {
        cout << root->data << " ";
        print(root->left);
        print(root->right);
    }
}

int main() {
    string expr;
    cin >> expr;    
    int i = 0;
    auto root = convertToBST(expr, i);
    print(root);
}