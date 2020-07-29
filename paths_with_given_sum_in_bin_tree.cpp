#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach - consider every path as seperate array and then the problem reduces to 
// number of subarrays with a given sum 

int ans = 0;
void go(TreeNode *root, unordered_map<int, int> &ump, int sum, int currSum) {
      if (root == NULL) {
            return;
      }
      currSum += root->val;
      if (currSum == sum) {
            ans += 1;
      }
      if (ump.count(currSum - sum)) {
            ans += ump[currSum - sum];
      }

      ump[currSum] += 1;

      go(root->left, ump, sum, currSum);
      go(root->right, ump, sum, currSum);

      ump[currSum] -= 1;
      if (ump[currSum] == 0)
      {
            ump.erase(currSum);
      }
}

int pathSum(TreeNode *root, int sum) {
      ans = 0;
      unordered_map<int, int> ump;
      go(root, ump, sum, 0);
      return ans;
}



// Alternative Appraoch 
// instead of using a map 
// here we fix a node - find all path STARTING FROM THIS NODE and summing up to given sum 
// we do the same process for every node - so all sum paths are covered 

int find(TreeNode* root, int cursum, int sum){
      if(!root) return 0;
      int ans = (cursum+root->val == sum);
      // found a path(subarray)  if ans = 1
      
      return  ans + 
      // find recursively
      find(root->left, cursum+root->val, sum) + 
      find(root->right, cursum+root->val, sum);
}

int pathSum(TreeNode* root, int sum) {
      if(!root) return 0;
      
      return find(root, 0, sum) + 
      // call recursively for left and right subtrees 
      // currSum starts from zero when called upon a cetain root 
      // so dont need a map
      pathSum(root->left, sum) + 
      pathSum(root->right, sum);
}