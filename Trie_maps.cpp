// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 


struct trie_node {
    map<char, trie_node*> children;         // map pointing to similar trie_nodes
    bool end_of_word;                       // marked true if the word is ending here 
};

typedef struct trie_node t_node;

t_node *new_node(void) {
    t_node *t = new t_node;        
    t->end_of_word = false;
    return t;
}

void insert(t_node *root, string key) {
    t_node *temp = root;
    
    for(int i = 0; i < key.length(); i++) {
        char x = key[i];
		if (temp->children[x] == nullptr)           // if there is no reference for key[i], make a new node 
			temp->children[x] = new_node(); 
		temp = temp->children[x];                   // go to node pointed by key[i] of this node
    }
    temp->end_of_word = true;
}

bool search(t_node *root, string key) {
	if (root == NULL) {
        return false;
    } 

	t_node *temp = root; 
	for (int i = 0; i < key.length(); i++)  { 
		temp = temp->children[key[i]]; 
		if (temp == nullptr) {
            return false;
        } 
	} 
	return temp->end_of_word; 
}

// check if node has 0 children
bool no_children(t_node *root) {
     return (root->children.begin() == root->children.end());               // root->childern.size() == 0   
}

t_node *Remove(t_node *root, string key, int depth = 0) {                   // depth is actually the index of the key
    if(root == NULL) {
        return NULL;
    }        
    if(depth == key.length()) {                                              // string has ended , we are working on the last node 
        // Remove the end of the word tag
        if(root->end_of_word)
            root->end_of_word = false;

        if(no_children(root)) {
            delete(root);
            root = NULL;
        }
        return root;
    }
    //1. go to children first 

    char ch = key[depth];
    root->children[ch] = Remove(root->children[ch], key, depth + 1);
    /*if root->children[index] == NULL, key is not found in the trie

    processing the current node for children remining after the opereation
    If root does not have any child (its only child got 
	deleted), and it is not end of any other word. 

    had there been > 0 children remaining then we cannot delete node as children are lost then
    had this node been the end of some word - we cannot delete it as the word is lost then 
    */
    if(no_children(root) && root->end_of_word == false) {           
        delete(root);
        root = NULL;
    }
    return root;
}

void display_content(t_node *root, vector<string> &arr, string s) {               
    if(root->end_of_word) {
        arr.push_back(s);
    }
    for(auto p: root->children) {
        display_content(p.second, arr, s + p.first);
    }
}

void disp(t_node *root) {
    vector<string> arr;
    string s = "";
    display_content(root, arr, s);
    
    for(auto word: arr) {
        cout << word << " ";
    }cout << endl;
}


int main() {
    string keys[] = {"hate", "a", "rise", 
					"above", "nobody", "nyy", 
					"mamba", "their" }; 
    
    int n = sizeof(keys)/sizeof(keys[0]);
    
    trie_node *root = new_node();
    for(int i = 0; i < n; i++) {
        insert(root, keys[i]);
    }

    disp(root);

	search(root, "yyy")? cout << "Yes\n" : cout << "No\n"; 
    search(root, "mamba")? cout << "Yes\n" : cout << "No\n";
    search(root, "no")? cout << "Yes\n" : cout << "No\n";
    search(root, "nobody")? cout << "Yes\n" : cout << "No\n";

    root = Remove(root, "hate", 0);
    root = Remove(root, "ans", 0);
    root = Remove(root, "above", 0);

    search(root, "hate")? cout << "Yes\n" : cout << "No\n";

}