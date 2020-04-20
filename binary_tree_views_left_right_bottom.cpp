
// left View 

void leftView(Node *root)
{
   if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    Node *temp, *prev = root;
    
    cout << q.front()->data << " ";
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        
        
        if(temp == NULL) {
            if(!q.empty())
                q.push(NULL);
        } else {
            if(prev == NULL)
                cout << temp->data << " ";
                
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        prev = temp;
    }
}



// right View 

// Should print right view of tree
void rightView(Node *root)
{
    if(root == NULL)
        return;
    int prev;
    Node *temp;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
   
    while(!q.empty()) {
        temp = q.front();
        q.pop();
            
        if(temp == NULL) {
            cout << prev << " ";
            if(!q.empty())
                q.push(NULL);
        } else {
            prev = temp->data;
        
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
   }
}


// bottom View


void bottomView(Node *root) {
    if(root==NULL)
	return ;

    map<int,int>mp;                     // horizonal distance, node->data
   	queue<pair<Node *,int > >q;         // node , horizontal distance
	q.push(make_pair(root,d));
    int d=0;
	
	while(!q.empty()){
		pair<Node *,int> p = q.front();
		q.pop();
		auto *cur = p.first;
		int hd = p.second;
		mp[hd] = cur->data;
		
        if(cur->left!=NULL) {
			q.push(make_pair(cur->left,val-1));
		}
		if(cur->right !=NULL) {
			q.push(make_pair(cur->right,val+1));
		}
	}
	
    for(auto p: mp)
        cout << p.second << " ";
}
