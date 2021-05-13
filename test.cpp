#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x, Node *n = NULL) {
        data = x;
        next = n;
    }
};

int main() {
    Node *a = new Node(1);
    Node *b = new Node(2, a);
   
    if(b->next == NULL) {
        cout << "b->next is NULL\n";
    } else {
        cout << "b->next is not NULL\n";
    }
}