#include <bits/stdc++.h>
using namespace std;

bool findk(TreeNode *one, TreeNode *two, int k) {
      if (one == NULL || two == NULL) {
            return false;
      }
      if (one->val + two->val == k) {
            if (one == two) {
                  return findk(one->left, two->right, k);
            } else {
                  return true;
            }
      }
      else if (one->val + two->val < k) {
            if (one == two) {
                  return findk(one, two->right, k);
            } else {
                  return findk(one, two->right, k) || findk(one->right, two, k);
            }
      } else {
            if (one == two) {
                  return findk(one, two->left, k);
            } else {
                  return findk(one, two->left, k) || findk(one->left, two, k);
            }
      }
}

// find if there exist two distinct nodes in BST such that their sum is k
bool findTarget(TreeNode *root, int k) {
      // call with same tree but two different pointers 
      return findk(root, root, k);
}

int main()
{
}