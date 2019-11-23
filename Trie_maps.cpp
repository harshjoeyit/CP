// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 


struct trie_node
{
    unordered_map<char, trie_node*> children;
    bool end_of_word;
};

typedef struct trie_node t_node;

t_node *get_node(void)
{
    t_node *p_node = new t_node;
    p_node->end_of_word = false;
    return p_node;
}


void insert(t_node *root, string key)
{
    t_node *temp = root;

    for(int i = 0; i < key.length(); i++)
    {
        char x = key[i];

		if (temp->children[x] == nullptr) 
			temp->children[x] = get_node(); 

		temp = temp->children[x];
    }
    temp->end_of_word = true;
}


bool search(t_node *root, string key)
{
	if (root == NULL) 
		return false; 

	t_node *temp = root; 
	for (int i = 0; i < key.length(); i++) 
    { 
		temp = temp->children[key[i]]; 
		if (temp == nullptr) 
			return false; 
	} 

	return temp->end_of_word; 
}


bool no_children(t_node *root)
{
     return (root->children.begin() == root->children.end());
}


t_node *Remove(t_node *root, string key, int depth = 0)
{
    if(root == NULL)
        return NULL;        // when the key is not found

    if(depth == key.length())               // string has ended , we are working on the last node 
    {
        // Remove the end of the word tag
        if(root->end_of_word)
            root->end_of_word = false;

        if(no_children(root))
        {
            delete(root);
            root = NULL;
        }
        return root;
    }
    //1. go to children first 

    char ch = key[depth];
    root->children[ch] = Remove(root->children[ch], key, depth + 1);
    // if root->children[index] == NULL, key is not found in the trie

    // processing the current node is child is deleted 
    // If root does not have any child (its only child got 
	// deleted), and it is not end of another word. 

    if(no_children(root) && root->end_of_word == false)
    {
        delete(root);
        root = NULL;
    }
    
    return root;
}



void display_content(t_node *root, string arr[], int &count, string s)
{
    t_node *temp = root;
    char ch;
    
    if(root->end_of_word)
    {
        arr[count++] = s;
    }

    auto st = root->children.begin();
    auto en = root->children.end();
    for(auto i = st; i != en; i++)
    {
        ch = i->first;
        display_content(i->second, arr, count, s + ch);         // calling recursively woth appended child 
    }
}



void disp(t_node *root)
{
    string arr[40];
    string s = "";
    int count = 0; 
    display_content(root, arr, count, s);
    
    cout << "-> ";              // for dictionary order change the unordered map to map
    for(int i = 0;  i < count; i++)
        cout << arr[i] << " ";
}



int main()
{
    string keys[] = {"hate", "a", "rise", 
					"above", "nobody", "nyy", 
					"mamba", "their" }; 
    
    int n = sizeof(keys)/sizeof(keys[0]);

    trie_node *root = get_node();

    for(int i = 0; i < n; i++)
    {
        insert(root, keys[i]);
    }

    disp(root);

	search(root, "yyy")? cout << "\nYes\n" : cout << "\nNo\n"; 
    search(root, "mamba")? cout << "Yes\n" : cout << "No\n";
    search(root, "no")? cout << "Yes\n" : cout << "No\n";
    search(root, "nobody")? cout << "Yes\n" : cout << "No\n";

    root = Remove(root, "hate", 0);
    root = Remove(root, "ans", 0);
    root = Remove(root, "above", 0);

    search(root, "hate")? cout << "Yes\n" : cout << "No\n";

}