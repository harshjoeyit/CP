

int ans = INT_MIN;

int getAns(Node *root) {
    if(root == NULL)
        return 0;
    
    int rd = root->data;
    int ls = getAns(root->left);
    int rs = getAns(root->right);
    
    if(root->left == NULL && root->right == NULL)
        return rd;
    
    else if(root->left == NULL)
        return rd + rs;
    
    else if(root->right == NULL)
        return rd + ls;
        
    if(ls+rs+rd > ans)
        ans = ls+rs+rd;
    
    return rd + max(ls, rs);
}

int maxPathSum(Node *root) {
    ans = INT_MIN;
    getAns(root);
    return ans;
}