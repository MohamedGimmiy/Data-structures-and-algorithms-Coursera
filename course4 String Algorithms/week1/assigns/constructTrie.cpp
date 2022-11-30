#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  // write your code here
  int root = 0; // root
  int nodesNum =0;
  for (size_t i = 0; i < patterns.size(); i++)
  {
    int currentNode = root;
      /* code */
      for (size_t j = 0; j < patterns[i].length(); j++)
      {  
          char currentSymbol = patterns[i][j];
          // if node  exists 
          if(!t.empty() && currentNode < t.size() && 
          t[currentNode].find(currentSymbol) != t[currentNode].end()){
            // proceed to the next level
              currentNode = t[currentNode].at(currentSymbol);
          }
          else {
            // the most powerful line of code
            // emplace_back
                t.push_back(edges{});
                t[currentNode][currentSymbol] = ++nodesNum;
                currentNode = nodesNum;
          }
      }
      
  }
  
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}