/*
	https://www.youtube.com/watch?v=co4_ahEDCho

	NOTE: After Encoding the total size of the message is not just "The Encoded Message" but we also have send the table 
	used for encoding along with the message. So, 
	"Total" size = Size of "Encoded Messsage" + Size of "Table"

	NOTE: Huffman Encoding is a GREEDY algorithm, 
    works on the principle of OPTIMAL MERGE PATTERN
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    char ch;
    int freq;
    TreeNode *l, *r;

    TreeNode(char _ch, int _freq)
    : ch(_ch), freq(_freq), l(NULL), r(NULL) { }
};

struct Comp {
    bool operator () (const TreeNode *a, const TreeNode *b) const {
        return a->freq > b->freq;
    }
};

bool isLeaf(TreeNode *root) {
    return !root->l && !root->r;
}

void getCodes(TreeNode *root, string &code,vector<string> &codes) {
    if (root->l) { 
		code.push_back('0');
		getCodes(root->l, code, codes); 
		code.pop_back();
	} 

	if (root->r) { 
		code.push_back('1');
		getCodes(root->r, code, codes);
		code.pop_back(); 
	} 

	if (isLeaf(root)) { 
		cout << root->ch << ": " << code << endl;
		codes.push_back(code); 
	}
}

vector<string> huffmanCodes(string str, vector<int> freq, int n) {
    // min heap
    priority_queue<TreeNode*, vector<TreeNode*>, Comp> pq;
    for(int i=0; i<n; i++) {
        pq.push(new TreeNode(str[i], freq[i]));
    }

    TreeNode *root;
    while(!pq.empty()) {
        if(pq.size() > 1) {
            auto l = pq.top(); pq.pop();
            auto r = pq.top(); pq.pop();
            TreeNode *newNode = new TreeNode('$', l->freq + r->freq);
            newNode->l = l;
            newNode->r = r;
            pq.push(newNode);
        }
        else {
            root = pq.top();
            pq.pop();
        }
    }

    vector<string> codes;
    string code = "";
    getCodes(root, code, codes);
    return codes;
}

int main() {
      huffmanCodes("abcdef", {5, 9, 12, 13, 16, 45}, 6);
}