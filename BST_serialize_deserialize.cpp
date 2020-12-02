

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    void makeString(TreeNode *root, string &s) {
        if(!root) {
            return;
        }
        s += to_string(root->val) + " ";
        makeString(root->left, s);
        makeString(root->right, s);
    }
    
    TreeNode * build(queue<int> &q, int low, int high) {
        if(q.empty()) {
            return NULL;
        }
        
        int val = q.front();
        if(val < low || val > high) {
            // this condition means that val does not belong to this subtree
            return NULL;
        }
        // pop if val belongs to this subtree 
        q.pop();
        
        TreeNode *root = new TreeNode(val);
        
        root->left = build(q, low, val);
        root->right = build(q, val, high);
        
        return root;
    }
    
public:    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        makeString(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        string num;
        ss << data;
        queue<int> q;
        while(ss >> num) {
            q.push(stoi(num));
        }
        return build(q, INT_MIN, INT_MAX);
    }
};

// https://www.geeksforgeeks.org/amazon-interview-set-117-campus-internship/?ref=rp

// Similar Problem 
// Serialize Deserialize a n-ary tree

// Appriach 

// Serialize 
// For each node, store its value, number of children 
// in array pass index by refernce

// Deserialize 
// Traverse array pass index by reference, call the 
// resursion as many times are number of children