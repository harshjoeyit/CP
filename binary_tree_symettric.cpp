#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool check(Node *a, Node *b) {
    if(a && b) {
        return (a->data == b->data) && check(a->left, b->right) && check(a->right, b->left);
    } 
    if(!a && !b)  {
        return true;
    } 
    if(a || b) {
        return false;
    }
}

bool isSymmetric(struct Node* root) {
	if(!root) {
	    return true;
	}
	if ((!root->left && root->right) || (root->left && !root->right)) {
	    return false;
	}
	return check(root->left, root->right);
}