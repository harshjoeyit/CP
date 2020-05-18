
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


bool mirror(Node *r1, Node *r2) {
    if(r1 == NULL && r2 == NULL)
        return 1;
    if(r1 == NULL || r2 == NULL)
        return 0;
    
    return(r1->data == r2->data && mirror(r1->left, r2->right) && mirror(r1->right, r2->left));
}

// return true/false if the is Symmetric or not
bool isSymmetric(struct Node* root)
{
	if(root == NULL)
	    return 1;
	 
	if(root->left == NULL && root->right == NULL)
	    return 1;
	 
	if(root->left == NULL || root->right == NULL)
	    return 0;
	   
	return mirror(root->left, root->right);
}
