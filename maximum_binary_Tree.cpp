
/*
Construct maximum binary tree 

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

inorder traversal of maxmimum binary tree gives the array 
*/

#include<bits/stdc++.h>
using namespace std;


// O(n*n)
class Solution {
public:
    
    TreeNode *construct(vector<int> &nums, int st, int en) {
        if(st > en) {
            return NULL;
        }
        
        int mx = nums[st];
        int j = st;
        
        for(int i=st+1; i<=en; i++) {
            if(nums[i] > mx) {
                mx = nums[i], j = i;
            }
        }
        
        TreeNode *root = new TreeNode(mx);
        root->left = construct(nums, st, j-1);
        root->right = construct(nums, j+1, en);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return construct(nums, 0, nums.size() - 1);
    }
};

// O(n)
class Solution {
public:
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode *> st;
        
        for(auto num: nums) {
            TreeNode *curr = new TreeNode(num);

            while(!st.empty() && st.back()->val < num) {
                curr->left = st.back();
                st.pop_back();
            }
            
            if(!st.empty()) {
                st.back()->right = curr;
            }
            st.push_back(curr);
        }
        
        return st.front();
    }
};