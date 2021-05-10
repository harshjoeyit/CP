
#include <bits/stdc++.h>
using namespace std;

// Brute Forces - Recurision

// Otimized - Dp approach
// Space -  O(n)
vector<int> dp;
int go(int i, vector<int> &a) {
      int n = (int)a.size();
      if (i >= n) {
            return 0;
      }
      
      int &ans = dp[i];
      if (ans != -1) {
            return ans;
      }

      return ans = max(go(i + 1, a), a[i] + go(i + 2, a));
}

// Using two variables
// Space O(1) appraoch
int goNice(vector<int> &a) {
      int n = a.size();
      int inc = a[0], ex = 0, temp;

      for (int i = 1; i < n; i++) {
		temp = max(inc, ex);
		inc = ex + a[i];
		ex = temp;
	}

      return max(inc, ex);
}

// another way to write above approach, but the one above is easier to understand
int rob(vector<int>& a) {
    int inc = a[0], ex = 0;
    for(int i=1; i<a.size(); i++) {
        int temp = inc;
        inc = max(inc, ex + a[i]);
        ex = temp;
    }
    return max(inc, ex);
}



// Similar problem 
// when array is circular and we cannot choose adjacnet 
// ans =  
// max(go(1, n), go(0, n-1), since 
// 1, n cannot be together 




// Similar problems on k-ary trees
// Find greatest sum, if you cannot select nodes with a edge between them
int func(int node, int select) {

      int &ans = dp[node][select];
      if (ans != -1)
            return ans;

      ans = 0;
      // we can select this node     
      if (select) {
            ans = node;
      }
      
      //edges[i] stores children of node i
      for (int i = 0; i < edges[node].size(); i++) {
            if (select) {
                  // cannot select children, because this selected 
                  ans = ans + func(edges[node][i], 1 - select);
            } else {
                  // can either select or skip children
                  ans = ans + max(func(edges[node][i], 0), func(edges[node][i], 1));
            }
      }

      return ans;
}


// House robber -
// include exclude method 

pair<int, int> go(TreeNode *root) {
    if(!root) {
        return {0, 0};
    }
    if(!root->right && !root->left) {
        return {root->val, 0};
    }
    
    auto l = go(root->left);
    auto r = go(root->right);
    
    // include this node 
    int inc = root->val + l.second + r.second;
    
    // exclude this node 
    int ex = max(l.first, l.second) + max(r.first, r.second);

    return {inc, ex};
}

int rob(TreeNode* root) {
    auto ansp = go(root);
    return max(ansp.first, ansp.second);
}


// House Robber 
// Using normal dp

map<TreeNode *, bool> dp;

int go(TreeNode* root, bool canRob = true) {
    if(root == NULL) {
        return 0;
    }
    
    auto state = make_pair(root, canRob);
    if(dp.count(state)) {
        return dp[state];
    }
    
    int l, r, ans = 0;
    
    if(canRob) {
        // rob this house 
        l = go(root->left, false);
        r = go(root->right, false);
        ans = l + r + root->val;
    }
    
    // cannot rob this house  
    l = go(root->left, true);
    r = go(root->right, true);
    ans = max(ans, l+r);   
    
    return dp[state] = ans;
}

int rob(TreeNode* root, bool canRob = true) {
    dp.clear();
    return go(root, true);
}


int main()
{
      int n;
      cin >> n;
      vector<int> a(n, 0);
      dp.assign(n, -1);
      for (int i = 0; i < n; i++)
      {
            cin >> a[i];
      }

      // cout << go(0, a);

      // cout << goNice(a);

      // answer = max(func(root,0),func(root,1));
}