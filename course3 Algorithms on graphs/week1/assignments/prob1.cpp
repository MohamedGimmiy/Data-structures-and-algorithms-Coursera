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
    int src, dest;

    GraphAdjList()
    {
        int edgesNum;
        cin >> nodesNum >> edgesNum;

        vector<bool> visited(nodesNum, false);
        this->visited = visited;

        nodes.resize(nodesNum);
        iota(begin(nodes), end(nodes), 0);

        int node1, node2;
        for (size_t i = 0; i < edgesNum; i++)
        {
            cin >> node1 >> node2;
            neighbors[node1-1].insert(node2-1);
            neighbors[node2-1].insert(node1-1);
        }
        cin >> src >> dest;
        src --;
        dest --;
    }

public:
    /**
     * @brief explore our neighbors of nodes
     * helper function of DFs
     * @param a 
     */
    bool Explore(int a , int &label, int &clock)
    {
        visited[a] = true;
        if(a == dest){
            return true;
        }
        // print each node with its group number
        for (auto &&i : neighbors[a])
        {
            if (!visited[i])
            {
                if(Explore(i, label, clock) == true)
                    return true;
            }
        }

        return false;
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
    // Solution of prob1
    cout << G.Explore(G.src, label, clock);
    return 0;
}