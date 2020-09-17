#include <bits/stdc++.h>
using namespace std;

// using extra space (set) to store nodes 

// We do inorder traversal since 
// a node with val = target - root->val will always be in left subtree 
// and if such a node exists then we want to visit is already so that 
// we find it in the set 
bool pairWithSum(TreeNode *root, unordered_set<int> &ust, int target) {
      if(!root) {
            return;
      }
      if(pairWithSum(root->left, ust, target)) {
            return true;
      }

      if(s.count(target - root->val)) {
            return true;
      } 
      s.insert(root->val);

      return pairWithSum(root->right, ust, target);
}

// without using set to store nodes 

bool pairWithSum(TreeNode *one, TreeNode *two, int target) {
      if (one == NULL || two == NULL) {
            return false;
      }
      
      int sum = one->val + two->val;
      
      if (sum == target) {
            if (one == two) {
                  return pairWithSum(one->left, two->right, target);
            } 
            return true;
      
      } else if (sum < target) {
            if (one == two) {
                  return pairWithSum(one, two->right, target);
            } 
            return pairWithSum(one, two->right, target) || pairWithSum(one->right, two, target);
      
      } else {
            if (one == two) {
                  return pairWithSum(one, two->left, target);
            }
            return pairWithSum(one, two->left, target) || pairWithSum(one->left, two, target);
      }
}

// find if there exist two distinct nodes in BST such that their sum is target
bool findTarget(TreeNode *root, int target) {
      // call with same tree but two different pointers 
      return pairWithSum(root, root, target);
}

int main()
{
}