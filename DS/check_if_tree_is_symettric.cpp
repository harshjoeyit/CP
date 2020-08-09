
/*
             5
           /   \                symettric                     
          1     1
         /       \
        2         2

        5
      /    \
    10      20                  not symettric
  /    \      \
20     20      30 

              100
            /     \                     symettric
          10       10
         /   \    /   \
       30     20 20    30
*/

bool go(TreeNode *a, TreeNode *b) {
      if (!a && !b) {
            return true;
      }
      else if (!a || !b) {
            return false;
      }
      else if (a->val != b->val) {
            return false;
      }

      if (a == b) {
            return go(a->left, b->right);
      }

      return go(a->left, b->right) && go(a->right, b->left);
}

bool isSymmetric(TreeNode *root) {
      return go(root, root);
}

public
boolean isSymmetric(TreeNode root) {
      if (root == null) {
            return true;
      }

      stack<TreeNode *> st;
      st.push(root.left);
      st.push(root.right);

      while (!st.empty()) {
            // just as in recursion 
            TreeNode a = st.pop(), b = st.pop();
            
            if (!a && !b) {
                  // go on, correct till now
                  continue;
            } if (!a || !b) {
                  return false;
            } else if(a.val != b.val) {
                  return false;
            }
            
            // left and right
            st.push(a.left);
            st.push(b.right);
            
            // right and left 
            st.push(a.right);
            st.push(b.left);
      }
      
      return true;
}