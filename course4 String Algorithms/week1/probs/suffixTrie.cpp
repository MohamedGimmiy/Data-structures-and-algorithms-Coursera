#include<iostream>
#include<vector>
using namespace std;

const int ALPHABET_SIZE = 26;
struct suffixTrie
{   
    suffixTrie * children[ALPHABET_SIZE];
    bool isEndOfWord;
};


// present a Trie Node as NULL pointers
suffixTrie * createNode(void){
    suffixTrie * node = new suffixTrie;
    node->isEndOfWord = false;
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

// If the key is prefix of trie node, just
suffixTrie * constructSuffixTrie(string text, suffixTrie *& root){
    suffixTrie * currentNode = root;

        for (size_t j = 0; j < text.length(); j++)
        {
            // Attach each node to our trie as a Trie (instead of NULL pointer)
            int index = text[j] - 'a';

            // If not present, inserts key into trie (WE not init a trie node -> init it)
            if(!currentNode->children[index]){
                currentNode->children[index] = createNode();
            }
            currentNode = currentNode->children[index];
        }
        // marks leaf node
        currentNode->isEndOfWord = true;
        currentNode = root;
        
    
    
    return root;
}

void buildSuffixTrie(string text, suffixTrie *& root){

    // we remove the first letter from our text and continue
    // to generate the suffix trie
    while (!text.empty())
    {
        constructSuffixTrie(text, root);
        text.erase(0, 1);
    }
    
}

/*----------- TODO make a suffixTree ----------------*/

//////////////

/*---------------------------------------------------*/

int main(){


    suffixTrie * root = createNode();
    string text = "banana";
    buildSuffixTrie(text, root);

    return;
}