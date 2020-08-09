
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      int ps = 0;
      return create(preorder, inorder, ps, 0, inorder.size() - 1);
}

// do not use static int since it causes problem for multiple test cases 
TreeNode *create(vector<int> &preorder, vector<int> &inorder, int &ps, int is, int ie) {
      // find example for the case when ps >= preorder.size()
      if (ps >= preorder.size() || is > ie) {
            return nullptr;
      }
      TreeNode *node = new TreeNode(preorder[ps]);
      int pos;
      for (int i = is; i <= ie; i++) {
            if (inorder[i] == node->val) {
                  pos = i;
                  break;
            }
      }
      ps++;
      node->left = create(preorder, inorder, ps, is, pos - 1);
      node->right = create(preorder, inorder, ps, pos + 1, ie);
      return node;
}

int main()
{
      vector<int> v = {};
}