#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;
const int ALPHABET_SIZE = 26;

struct TNode {
	TNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

TNode* getTNode() {
	TNode* node = new TNode;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		node->children[i] = NULL;
	}
	node->isEndOfWord = false;
	return node;
}

// insert ant, any, an
void insert(TNode* root, string str) {
	if (str.length() > 0) {
		int c = str[0] - 97;
		if (!root->children[c]) {
			root->children[c] = getTNode();
		}
		insert(root->children[c], str.substr(1));
	}
	else {
	    root->isEndOfWord = true;
		//cout << "end of string reached - endOfWordMarker being set - " << root->isEndOfWord << endl;
	}
}

// ant, an
// search(root, an),
// search (a, n)
// search (an, '')
bool search(TNode* root, string str) {
	if (str.length() > 0) {
		int c = str[0] - 97;
		if (!root->children[c]) { cout << c << " not present, returning false" << endl;   return false; }
		return search(root->children[c], str.substr(1));
	}
	else {
		//cout << "end of string reached - endOfWordMarker - " << root->isEndOfWord << endl;
		return root->isEndOfWord;
	}
}


// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    char c = '9';
    cout << int(c) << endl;
    exit(0);
 
    TNode* root = getTNode();
	//cout << &root << endl;
 
    // Construct trie
    for (int i = 0; i < n; i++) {
		//cout << keys[i] << endl;
        insert(root, keys[i]);
	}
 
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}
