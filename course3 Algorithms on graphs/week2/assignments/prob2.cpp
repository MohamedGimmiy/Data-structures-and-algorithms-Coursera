#include <iostream>
#include <unordered_set>
#include <vector>
#include <numeric>
#include <map>
using namespace std;

/**
 * @brief Adjacency List (that will be used)
 * note: all nodes are sorted from a to z
 * 
 */
vector<int>result;
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

        nodes.resize(nodesNum+1);
        iota(nodes.begin(), nodes.end(), 0);

        vector<bool> visited(nodesNum + 1, false);
        this->visited = visited;

        int node1, node2;
        for (int i = 0; i < edgesNum; i++)
        {
            cin >> node1 >> node2;
            neighbors[node1].insert(node2);
        }
    }

    void printEdges()
    {
        for (auto it = neighbors.begin(); it != neighbors.end(); ++it)
        {
            for (auto itSet = it->second.begin(); itSet != it->second.end(); ++itSet)
            {
                cout << it->first << "----->" << *itSet << "\n";
            }
        }
    }

    bool isEdge(int a, int b)
    {

        for (auto &&i : neighbors[a])
        {
            if (i == b)
            {
                return true;
            }
        }
        return false;
    }

private:
    void previsit(int v, int &clock)
    {   
        clockOrder[v].first = clock;
        ++clock;
    }

    void postvisit(int v, int &clock, bool printTopological = false)
    {
        if (printTopological){
            //cout << v << "-> ";
            result.insert(result.begin(),v);
        }
        clockOrder[v].second = clock;
        ++clock;
    }

    /**
     * @brief explore our neighbors of nodes
     * helper function of DFs
     * @param a 
     */
    void Explore(int a, int &label, int &clock,
                 bool printTopological = false, bool printGroups = false)
    {

        visited[a] = true;
        // previsit(a, clock);

        // print each node with its group number
        if (printGroups)
        {
            cout << a << label << " -> ";
        }
        for (auto &&i : neighbors[a])
        {
            if (!visited[i])
            {
                Explore(i, label, clock, printTopological, printGroups);
            }
        }
        postvisit(a, clock, printTopological);
    }

public:
    /**
     * @brief Explore all nodes of our graph
     * using Depth-first-search
     * 
     */
    void DFS(bool printTopological = false, bool printGroups = false)
    {
        int label = 1;
        int clock = 1;
        for (auto &&i : nodes)
        {
            if (i == 0)
            {
                continue;
            }
            if (!visited[i])
            {
                Explore(i, label, clock, printTopological, printGroups);
                label++;
            }
        }
        //cout << "\n";
        visited.assign(visited.size(), false);
    }
    /**
     * @brief Topological sorting of our graph
     * find a sink an print it
     */
    void TopologicalSortOrder()
    {
        DFS(true);
    }
    void printGroups()
    {
        DFS(false, true);
    }
    void printPrePostVisitClockOrder()
    {
        for (auto it = clockOrder.begin(); it != clockOrder.end(); ++it)
        {
            cout << it->first << '(' << it->second.first << ", "
                 << it->second.second << ')' << " ";
        }
        cout << endl;
    }

    void strongConnectedComponents()
    {
        // TODO
    }
};

int main()
{

    // Storing a Graph as an AdjList
    GraphAdjList G;
    //cout << G.DFS();
    G.TopologicalSortOrder();
    for (auto &&i : result)
    {
        cout << i << " ";
    }
    
    //G.printGroups();
    //G.printPrePostVisitClockOrder();

    return 0;
}