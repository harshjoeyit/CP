
// must read 
// https://leetcode.com/problems/binary-tree-cameras/solution/
// Place cameras on the nodes 

#include<bits/stdc++.h>
using namespace std;

vector<int> go(TreeNode *root) {
    if(!root) {
        // camera should not be placed at null node, that is why large number  
        return {0,0,9999};
    }
    
    auto L = go(root->left);
    auto R = go(root->right);
    int minL12 = min(L[1], L[2]);
    int minR12 = min(R[1], R[2]);
    
    // root in state 0
    int d0 = L[1] + R[1];
    // root in state 1
    int d1 = min(L[2] + minR12, R[2] + minL12);
    // root in state 2
    int d2 = 1 + min(L[0], minL12) + min(R[0], minR12);
    
    return {d0, d1, d2};
}

int minCameraCover(TreeNode* root) {
    auto ans = go(root);
    return min(ans[1], ans[2]);
}



// greedy solution 

int minCameraCover(TreeNode* root) {
    int sum=0;
    if(dfs(root,sum)==0)   sum++;// if root is not monitored, we place an additional camera here
    return sum;
}

int dfs(TreeNode * tr, int& sum){
    if(!tr) return 1;
    
    int l=dfs(tr->left,sum), r=dfs(tr->right,sum);
    
    if (l==0 || r==0) {
       // if at least 1 child is not monitored, we need to place a camera at current node 
       sum++;
       return 2;
    } else if (l==2 || r==2) {
        // if at least 1 child has camera, the current node is monitored. 
        // Thus, we don't need to place a camera here 
        return 1;
    } else {
        // if both children are monitored but have no camera, we don't need to place 
        // a camera here. We place the camera at its parent node at the higher level. 
        return 0;
    }
    // this return statement won't be triggered
    return -1;
}