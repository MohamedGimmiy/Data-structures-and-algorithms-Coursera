#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include<map>
using namespace std;

/*
int const Letters =    4;
int const NA      =   -1;
*/

/* struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
}; */

/*
int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}
*/

// if there is an a final edge we add a flage as true
typedef map<char, pair<int,bool>> edges;
typedef vector<edges> trie;


trie build_trie(const vector<string> & patterns) {
  trie t;
  // write your code here
  int root = 0; // root
  int nodesNum = 0;
  for (size_t i = 0; i < patterns.size(); i++)
  {
    int currentNode = root;

      for (size_t j = 0; j < patterns[i].length(); j++)
      {  
          char currentSymbol = patterns[i][j];
          // if node  exists 
          if(!t.empty() && currentNode < t.size() && 
          t[currentNode].find(currentSymbol) != t[currentNode].end()){
                if(j == patterns[i].length()-1){
                    // we add the position as a stater pattern
                    t[currentNode][currentSymbol].second = true;
                }
            // proceed to the next level
              currentNode = t[currentNode].at(currentSymbol).first;
          }
          else {
                // the most powerful line of code
                // emplace_back
                t.push_back(edges{});
                // before updating the path we check if node is a final node

                t[currentNode][currentSymbol].first = ++nodesNum;
                if(j == patterns[i].length()-1){
                    // we add the position as a stater pattern
                    t[currentNode][currentSymbol].second = true;
                }
                currentNode = nodesNum;
          }
      }
      
  }
  
  return t;
}


vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;

    //TODO construct a trie
	trie myTrie = build_trie(patterns);

	// write your code here
    for (int i = 0; i < text.length(); i++)
    {
        int current_vertex = 0, current_symbol_index = i;
        char symbol = text[current_symbol_index];

        while (true) {
			// if 𝑣 exists and is an end of a pattern :
			// return the pattern spelled by the path from the root to v

            if (myTrie[current_vertex].empty() ||
                (myTrie[current_vertex].find(symbol) != myTrie[current_vertex].end()
                && myTrie[current_vertex][symbol].second == true)
                ) {
                result.push_back(i);
                break;
            }
			// else if there is an edge (𝑣, 𝑤) in Trie labeled by symbol :
            else if (myTrie[current_vertex].find(symbol) != myTrie[current_vertex].end()) {
                //symbol ← next letter of Text
				// 𝑣 ← 𝑤
				current_vertex = myTrie[current_vertex][symbol].first;
                symbol = text[++current_symbol_index];
            }
            else {
                break;
            }
        }
    }
    
	return result;
}

int main (void)
{
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (text, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}