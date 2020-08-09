#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *inorderPred(TreeNode *root)
{
      root = root->left;
      while (root->right)
      {
            root = root->right;
      }
      return root;
}
TreeNode *inorderSucc(TreeNode *root)
{
      root = root->right;
      while (root->left)
      {
            root = root->left;
      }
      return root;
}

// O(n.log(n)) - since we traverse each node in O(n) and
// then its inorder succesor and predecessor in O(logn)
bool isValidBST(TreeNode *root)
{
      // null root is a valid binary search tree
      if (root == NULL)
      {
            return true;
      }

      auto leftValid = isValidBST(root->left);
      if (leftValid == false)
      {
            return false;
      }

      auto rightValid = isValidBST(root->right);
      if (rightValid == false)
      {
            return false;
      }

      if (root->left)
      {
            // if root is less than equal to its predecessor - invalid
            auto inPre = inorderPred(root);
            if (inPre->val >= root->val)
            {
                  return false;
            }
      }

      if (root->right)
      {
            // if root is greater or equal to its succ - invalid
            auto inSucc = inorderSucc(root);
            if (root->val >= inSucc->val)
            {
                  return false;
            }
      }

      return true;
}

// O(n) time O(1) space approach 
// we pass a lower limit and and a upper limit to a node
// the node's value should be between the uppper and lower limits
bool isValidBST(TreeNode *root, long long int low = -1e17, long long int high = 1e17)
{
      if (root == NULL)
      {
            return true;
      }

      if (root->val <= low || root->val >= high)
      {
            return false;
      }

      // go to left - upper limit is this node itself
      if (!isValidBST(root->left, low, root->val))
      {
            return false;
      }
      // go to right the lower limit is the root iteself
      if (!isValidBST(root->right, root->val, high))
      {
            return false;
      }

      return true;
}

vector<int> inorder;
void go(TreeNode *root)
{
      if (root)
      {
            go(root->left);
            inorder.push_back(root->val);
            go(root->right);
      }
}

// O(n) time O(n) space
bool isValidBST(TreeNode *root)
{
      inorder.clear();
      go(root);
      int n = inorder.size();
      for (int i = 1; i < n; i++)
      {
            if (inorder[i] <= inorder[i - 1])
            {
                  return false;
            }
      }
      return true;
}

// Can also be done by inorder travesal using stack 

int main()
{
}