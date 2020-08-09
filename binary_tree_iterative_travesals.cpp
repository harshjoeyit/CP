#include <bits/stdc++.h>
using namespace std;

// READ MORRIS TRAVERRSALS
// IMP solve in space complexity of O(1)

struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// vertical Traversal
vector<vector<int>> verticalTraversal(TreeNode *root)
{
      if (root == NULL)
      {
            return {};
      }
      map<int, vector<int>> axis;
      int x = 0;
      TreeNode *node;
      queue<pair<TreeNode *, int>> q;
      q.push(make_pair(root, 0));

      while (!q.empty())
      {
            unordered_map<int, vector<int>> ump;
            for (int sz = q.size(); sz >= 1; sz--)
            {
                  auto p = q.front();
                  q.pop();
                  x = p.second;
                  node = p.first;

                  ump[x].push_back(node->val);

                  if (node->left)
                  {
                        q.push(make_pair(node->left, x - 1));
                  }
                  if (node->right)
                  {
                        q.push(make_pair(node->right, x + 1));
                  }
            }
            for (auto p : ump)
            {
                  x = p.first;
                  sort(p.second.begin(), p.second.end());
                  for (auto y : p.second)
                  {
                        axis[x].push_back(y);
                  }
            }
      }

      vector<vector<int>> ans;
      for (auto p : axis)
      {
            ans.push_back(p.second);
      }
      return ans;
}

vector<int> postorderTraversal(TreeNode *root)
{
      vector<int> ans;
      stack<TreeNode *> st;
      TreeNode *last = NULL;

      while (root || !st.empty())
      {
            if (root)
            {
                  st.push(root);
                  root = root->left;
            }
            else
            {
                  TreeNode *node = st.top();
                  if (node->right && last != node->right)
                  {
                        root = node->right;
                  }
                  else
                  {
                        ans.push_back(node->val);
                        last = node;
                        st.pop();
                  }
            }
      }

      return ans;
}

// preorder traversal
vector<int> preorderTraversal(TreeNode *root)
{
      vector<int> ans;
      if (!root)
      {
            return ans;
      }
      stack<TreeNode *> s;
      s.push(root);
      while (!s.empty())
      {
            TreeNode *curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            if (curr->right)
            {
                  s.push(curr->right);
            }
            if (curr->left)
            {
                  s.push(curr->left);
            }
      }
      return ans;
}

// preorder traversal
vector<int> ans;
stack<TreeNode *> st;

void pushLeft(TreeNode *root)
{
      while (root)
      {
            ans.push_back(root->val);
            st.push(root);
            root = root->left;
      }
}

vector<int> preorderTraversal(TreeNode *root)
{
      ans.clear();

      pushLeft(root);
      while (!st.empty())
      {
            root = st.top();
            st.pop();
            pushLeft(root->right);
      }

      return ans;
}

// inorder traversal
stack<TreeNode *> st;

void pushLeft(TreeNode *root)
{
      while (root)
      {
            st.push(root);
            root = root->left;
      }
}

vector<int> inorderTraversal(TreeNode *root)
{
      vector<int> ans;
      pushLeft(root);

      while (!st.empty())
      {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            pushLeft(root->right);
      }

      return ans;
}

int main()
{
}