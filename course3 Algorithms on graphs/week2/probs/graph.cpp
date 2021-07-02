#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

/**
 * @brief Adjacency List (that will be used)
 * note: all nodes are sorted from a to z
 * 
 */
class GraphAdjList
{
    unordered_set<char> nodes;
    vector<bool> visited;
    int nodesNum;

    // node and its neighbors
    map<char, unordered_set<char>> neighbors;

    map<char, pair<int, int>> clockOrder;

public:
    GraphAdjList()
    {

        cin >> nodesNum;
        vector<bool> visited(nodesNum, false);
        this->visited = visited;

        char c;
        for (size_t i = 0; i < nodesNum; i++)
        {
            cin >> c;
            nodes.insert(c);
        }
    }

    void makeEdge(char a, char b)
    {
        if (nodes.find(a) == nodes.end() || nodes.find(b) == nodes.end())
        {
            cout << "not found!\n";
            return;
        }
        neighbors[a].insert(b);
        // Directed graph
        // neighbors[b].insert(a);
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

    bool isEdge(char a, char b)
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
    void previsit(char v, int &clock)
    {
        clockOrder[v].first = clock;
        ++clock;
    }

    void postvisit(char v, int &clock, bool printTopological = false)
    {
        if (printTopological)
            cout << v << "-> ";
        clockOrder[v].second = clock;
        ++clock;
    }

    /**
     * @brief explore our neighbors of nodes
     * helper function of DFs
     * @param a 
     */
    void Explore(char a, int &label, int &clock,
     bool printTopological = false, bool printGroups=false)
    {

        visited[a - 'a'] = true;
        previsit(a, clock);

        // print each node with its group number
        if(printGroups){
            cout << a << label << " -> ";
        }
        for (auto &&i : neighbors[a])
        {
            if (!visited[i - 'a'])
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
    void DFS(bool printTopological = false, bool printGroups=false)
    {
        int label = 1;
        int clock = 1;
        for (auto &&i : nodes)
        {
            if (!visited[i - 'a'])
            {
                Explore(i, label, clock, printTopological, printGroups);
                label++;
            }
        }
        cout << "\n";
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
    void printGroups(){
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

    void strongConnectedComponents(){
        // TODO
    }
};

int main()
{

    // Storing a Graph as an AdjList
    GraphAdjList G;
    G.makeEdge('a', 'b');
    G.makeEdge('a', 'c');
    G.makeEdge('c', 'd');
    G.makeEdge('e', 'f');
    G.printEdges();
    //G.Explore('a');
    G.DFS();
    G.TopologicalSortOrder();
    G.printGroups();
    G.printPrePostVisitClockOrder();

    return 0;
}