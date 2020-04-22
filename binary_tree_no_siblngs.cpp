

/* 
Prints the nodes having no siblings.  

Logic : A node does not have a sibling if its parent has only one child that is itself
*/


void printSibling(Node* node)
{
    if(node == NULL) {
        cout << -1;
        return;
    }
    
    vector<int> ans;
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
                
        if(temp->left && temp->right) {
            q.push(temp->left);
            q.push(temp->right);
        }
        else if(temp->left)  {
            ans.push_back(temp->left->data);
            q.push(temp->left);
        }
        else if(temp->right) {
            ans.push_back(temp->right->data);
            q.push(temp->right);
        }
    }
    
    if(ans.size() == 0) {
        cout << -1;
        return;
    }
    
    sort(ans.begin(), ans.end());
    for(auto x: ans)
        cout << x << " ";
    
}