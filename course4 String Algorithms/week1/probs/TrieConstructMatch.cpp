#include<iostream>
#include<vector>
#include<string>
using namespace std;

//---------------------- part 1 constructing tries -------------------//
const int ALPHABET_SIZE = 26;

struct Trie{
    Trie * children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// present a Trie Node as NULL pointers
Trie * createNode(void){
    Trie * node = new Trie;
    node->isEndOfWord = false;
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}


// If the key is prefix of trie node, just
Trie * constructTrie(vector<string>patterns){
    Trie * root = createNode();
    Trie * currentNode = root;
    for (size_t i = 0; i < patterns.size(); i++)
    {   
        for (size_t j = 0; j < patterns[i].length(); j++)
        {
            // Attach each node to our trie as a Trie (instead of NULL pointer)
            int index = patterns[i][j] - 'a';

            // If not present, inserts key into trie (WE not init a trie node -> init it)
            if(!currentNode->children[index]){
                currentNode->children[index] = createNode();
            }
            currentNode = currentNode->children[index];
        }
        // marks leaf node
        currentNode->isEndOfWord = true;
        currentNode = root;
    }
    
    return root;
}

//--------------------- part 2 searching in tries ------------------//
void searchContText(string text, Trie * root, int index){

        int textIndex = 0;
        char symbol = text[textIndex];

        Trie * v = root;
        string pattern ="";
    while (true)
    {   
        if(v->isEndOfWord){
            cout << "found in position: " << index << " " << pattern << " \n";
            return;
        }
        else if(v->children[symbol-'a']){
            // next char of pattern tree
            v = v->children[symbol - 'a'];
            // constructing the pattern
            pattern += symbol;
            // next char of text
            textIndex++;
            symbol = text[textIndex];
        }
        else{
            cout << "No match found"<<"\n";
            return;
        }
    }
    
    
}

void TrieMatching(string text, Trie* root){
    int i = 0;

    while (!text.empty())
    { 
        searchContText(text, root, i);
        text.erase(0,1);
        i++;
    }
    
}
int main(){

    
    vector<string>patterns = {
        "banana",
        "pan",
        "and",
        "nab",
        "antenna",
        "bandana",
        "ananas",
        "nana"
    };
    string text = "panamabananas";

    Trie * root = constructTrie(patterns);

    
    
    TrieMatching(text, root);
    return 0;
}