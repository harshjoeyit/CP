/*
    Trie
Trie uses less memory as compared to hash table 
We cam do a prefix based search in a trie 
*/

#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 


struct trie_node
{
    struct trie_node *children[ALPHABET_SIZE];          // if only lowercase or uppercase - otherwise use a map     
    bool end_of_word;
};

typedef struct trie_node t_node;


t_node *get_node(void)
{
    t_node *p_node = new t_node;
    p_node->end_of_word = false;

    for(int i = 0; i < ALPHABET_SIZE; i++)  
        p_node->children[i] = NULL;
    
    return p_node;
}


void insert(t_node *root, string key)
{
    t_node *p_crawl = root;

    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(p_crawl->children[index] == NULL)
            p_crawl->children[index] = get_node();
        
        p_crawl = p_crawl->children[index];
    }
    
    p_crawl->end_of_word = true;
}


bool search(t_node *root, string key)
{
    t_node *p_crawl = root;

    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(p_crawl->children[index] == NULL)
        {
            return false;
        }

        p_crawl = p_crawl->children[index];
    }

    return (p_crawl != NULL && p_crawl->end_of_word);       // there should be a node attached to 
                                                            //  the ending character of the word 
                                                            // that says the end of the word is true 
}


bool no_children(t_node *root)
{
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(root->children[i])
            return false;
    }
    return true;
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

    int index = key[depth] - 'a';
    root->children[index] = Remove(root->children[index], key, depth + 1);
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

    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(root->children[i] != NULL)
        {
            ch = (char)(i + (int)'a');
            display_content(root->children[i], arr, count, s + ch);         // calling recursively woth appended child 
        }
    }
}


void disp(t_node *root)
{
    string arr[20];
    string s = "";
    int count = 0; 
    display_content(root, arr, count, s);
    
    cout << "lexiographical order: ";
    for(int i = 0;  i < count; i++)
        cout << arr[i] << " ";
}


int main()
{
    string keys[] = {"the", "a", "there", 
					"answer", "any", "by", 
					"bye", "their" }; 
    
    int n = sizeof(keys)/sizeof(keys[0]);

    trie_node *root = get_node();

    for(int i = 0; i < n; i++)
    {
        insert(root, keys[i]);
    }

    disp(root);

    // Search for different keys 
	search(root, "the")? cout << "\nYes\n" : cout << "\nNo\n"; 
	search(root, "these")? cout << "Yes\n" : cout << "No\n";
    
    root = Remove(root, "ans", 0);
    root = Remove(root, "a", 0);
    root = Remove(root, "bye", 0);
    root = Remove(root, "an", 0);
    root = Remove(root, "by", 0);

    search(root, "answer")? cout << "Yes\n" : cout << "No\n";
    search(root, "any")? cout << "Yes\n" : cout << "No\n";

    disp(root);
}