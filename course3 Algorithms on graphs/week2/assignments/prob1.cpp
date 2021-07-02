#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * @brief move a node from one set to another
 * 
 * @param vertex 
 * @param src 
 * @param dest 
 */

void moveVertex(int vertex, unordered_set<int> &src, unordered_set<int> &dest)
{
    //TODO
    src.erase(vertex);
    dest.insert(vertex);
}

/**
 * @brief 
 * 
 * @param a the element to start from
 * @param adj the graph
 * @param white : white set
 * @param grey : grey set (visited set)
 * @param black : black set (blocked paths)
 * @return true if we found a cycle
 * @return false if we did not
 */
bool Explore(int a, vector<vector<int>> &adj,
             unordered_set<int> &white,
             unordered_set<int> &grey,
             unordered_set<int> &black)
{
    // mark as visited
    moveVertex(a, white, grey);

    for (auto &&i : adj[a])
    {   
        if (black.find(i) != black.end())
        {
            continue;
        }

        if (grey.find(i) != grey.end())
        {
            return true;
        }

        if (Explore(i, adj, white, grey, black))
        {
            return true;
        }
    }
    // mark as finished processed
    moveVertex(a, grey, black);
    return false;
}
bool DFS(vector<vector<int>> &adj, unordered_set<int> &whiteSet)
{

    unordered_set<int> greySet;
    unordered_set<int> blackSet;

    while (whiteSet.size() > 0)
    {
        int current = *whiteSet.begin();
        if (Explore(current, adj, whiteSet, greySet, blackSet))
        {
            return true;
        }
    }

    return false;
}
int acyclic(vector<vector<int>> &adj, unordered_set<int> &whiteSet)
{ //write your code here
    return DFS(adj, whiteSet);
}
int main()
{
    size_t n, m;
    std::cin >> n >> m;
    unordered_set<int> whiteSet;

    for (size_t i = 0; i < n; i++)
    {
        whiteSet.insert(i);
    }

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << acyclic(adj, whiteSet);
}