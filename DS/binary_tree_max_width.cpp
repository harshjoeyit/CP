
/*
The width of one level is defined as the length between 
the end-nodes (the leftmost and right most non-null nodes 
in the level, where the null nodes between
 the end-nodes are also counted into the length calculation.
*/

int widthOfBinaryTree(TreeNode* root) {
    
    queue<pair<TreeNode*,int>>q;
    q.push(make_pair(root,1));
    
    int maxW = 0;
    
    while(!q.empty()){
    int x = q.size();
        bool first = false;
        int left = 0;
        while(x){
            
            pair p = q.front();
            q.pop();
            
            if(p.first->left) q.push(make_pair(p.first->left,(ll)p.second*2));
            if(p.first->right) q.push(make_pair(p.first->right,(ll)p.second*2+1));
            
            if(!first){
                left = p.second;
                first = true;
            }
            maxW = max(maxW,p.second-left+1);
            x--;
        }
    }
    return maxW;
}
