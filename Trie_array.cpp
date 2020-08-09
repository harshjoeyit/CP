/*    Trie
Trie uses less memory as compared to hash table 
We cam do a prefix based search in a trie 
*/

#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

class TrieNode {
public:
      TrieNode *children[ALPHABET_SIZE];
      bool endOfWord;
      
      TrieNode() {
            this->endOfWord = false;
            for(int i=0; i<ALPHABET_SIZE; i++) {
                  this->children[i] = NULL;
            }
      }
};

void insert(TrieNode *root, string key) {
      TrieNode *ptr = root;

      for(int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if(ptr->children[index] == NULL) {
                  ptr->children[index] = new TrieNode();
            }
            ptr = ptr->children[index];
      }

      ptr->endOfWord = true;
}

bool search(TrieNode *root, string key) {
      TrieNode *ptr = root;
      
      for(int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if(ptr->children[index] == NULL) {
                  return false;
            }
            ptr = ptr->children[index];
      }

      // there should be a node attached to the ending character 
      // of the word that says the end of the word is true 
      return (ptr != NULL && ptr->endOfWord);       
}

bool hasNoChildren(TrieNode *root) {
      for(int i = 0; i < ALPHABET_SIZE; i++) {
            if(root->children[i]) {
                  return false;
            }
      }
      return true;
}

TrieNode *remove(TrieNode *root, string key, int depth = 0) {
      if(root == NULL) {
            // if key is not found
            return NULL;
      }       

      if(depth == key.length()) {
            // string has ended , we are working on the last node 
            // remove the end of the word tag
            if(root->endOfWord) {
                  root->endOfWord = false;
            }

            if(hasNoChildren(root)) {
                  delete(root);
                  root = NULL;
            }
            return root;
      }

      // 1. go to children first 

      int index = key[depth] - 'a';
      root->children[index] = remove(root->children[index], key, depth + 1);
      // if root->children[index] == NULL, key is not found in the trie

      // 2. processing the current node if child is deleted 
      
      // If root does not have any child (its only child got deleted), 
      // and it is not end of any other word. 
      if(hasNoChildren(root) && root->endOfWord == false) {
            delete(root);
            root = NULL;
      }

      return root;
}

void displayContent(TrieNode *root, vector<string> &arr, string s) {
      TrieNode *temp = root;
      char ch;
      
      if(root->endOfWord) {
          arr.push_back(s);
      }

      for(int i = 0; i < ALPHABET_SIZE; i++) {
            if(root->children[i] != NULL) {
                  ch = (char)(i + (int)'a');
                  // calling recursively with appended child 
                  displayContent(root->children[i], arr, s + ch);         
            }
      }
}


void disp(TrieNode *root) {
      vector<string> arr;
      string s = ""; 
      displayContent(root, arr, s);
      
      cout << "lexiographical order: \n";
      for(auto s: arr) {
            cout << s << endl;
      }
}



int main() {
      string keys[] = {"the", "a", "there", 
	      		"answer", "any", "by", 
	      		"bye", "their" }; 
      
      int n = sizeof(keys)/sizeof(keys[0]);

      TrieNode *root = new TrieNode();

      for(int i = 0; i < n; i++) {
          insert(root, keys[i]);
      }

      // Search for different keys 
	search(root, "the")? cout << "Yes\n" : cout << "No\n"; 
	search(root, "these")? cout << "Yes\n" : cout << "No\n";
      search(root, "ans")? cout << "Yes\n" : cout << "No\n";
      search(root, "answer")? cout << "Yes\n" : cout << "No\n";
      search(root, "a")? cout << "Yes\n" : cout << "No\n";

      disp(root);

      // Search for different keys 
	search(root, "the")? cout << "\nYes\n" : cout << "\nNo\n"; 
	search(root, "these")? cout << "Yes\n" : cout << "No\n";
      
      root = remove(root, "ans", 0);
      root = remove(root, "a", 0);
      root = remove(root, "bye", 0);
      root = remove(root, "an", 0);
      root = remove(root, "by", 0);

      search(root, "bye")? cout << "Yes\n" : cout << "No\n";
      search(root, "any")? cout << "Yes\n" : cout << "No\n";

      disp(root);
}