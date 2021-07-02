#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <numeric>
using namespace std;

/**
 * @brief Adjacency List (that will be used)
 * note: all nodes are sorted from a to z
 * 
 */
class GraphAdjList
{
    vector<int> nodes;
    vector<bool> visited;
    int nodesNum;

    // node and its neighbors
    map<int, unordered_set<int>> neighbors;

    map<int, pair<int, int>> clockOrder;

public:
    GraphAdjList()
    {
        int edgesNum;
        cin >> nodesNum >> edgesNum;

        vector<bool> visited(nodesNum + 1, false);
        this->visited = visited;

        nodes.resize(nodesNum + 1);
        iota(begin(nodes), end(nodes), 0);

        int node1, node2;
        for (size_t i = 0; i < edgesNum; i++)
        {
            cin >> node1 >> node2;
            neighbors[node1].insert(node2);
            neighbors[node2].insert(node1);
        }
    }

public:
    /**
     * @brief explore our neighbors of nodes
     * helper function of DFs
     * @param a 
     */
    void Explore(int a, int &label, int &clock)
    {
        visited[a] = true;
        // print each node with its group number
        for (auto &&i : neighbors[a])
        {
            if (!visited[i])
            {
                Explore(i, label, clock);
            }
        }
    }

    bool isDestinationReached()
    {
        bool v = visited[visited.size() - 1];
        visited.assign(visited.size(), false);
        return v;
    }
    /**
     * @brief Explore all nodes of our graph
     * using Depth-first-search
     * 
     */
    void DFS()
    {
        int label = 0;
        int clock = 1;
        for (auto &&i : nodes)
        {
            if (i == 0)
            {
                continue;
            }
            if (!visited[i])
            {
                Explore(i, label, clock);
                label++;
            }
        }
        cout << label << "\n";
        visited.assign(visited.size(), false);
    }
};

int main()
{

    // Storing a Graph as an AdjList
    GraphAdjList G;
    int label = 1;
    int clock = 1;

    // Solution of prob2
    G.DFS();
    return 0;
}