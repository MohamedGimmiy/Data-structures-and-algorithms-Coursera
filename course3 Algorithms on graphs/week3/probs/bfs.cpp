#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
#include<queue>
#include<numeric>
#include<algorithm>


#define NIL -1
using namespace std;

/**
 * @brief Adjacency List (that will be used)
 * note: all nodes are sorted from a to z
 * 
 */
class GraphAdjList
{
    vector<char> nodes;
    vector<bool> visited;
    int nodesNum;

    // node and its neighbors
    map<char, unordered_set<char>> neighbors;

    map<char, pair<int, int>> clockOrder;

public:
    GraphAdjList()
    {
        int edges;
        cin >> nodesNum >> edges;
        vector<bool> visited(nodesNum, false);
        this->visited = visited;

        nodes.resize(nodesNum);
        iota(nodes.begin(), nodes.end(), 'a');
        
        char node1, node2;
        for (size_t i = 0; i < edges; i++)
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
     * @brief Breadth-first-search of a graph
     * used to find the shortest path of unWeighted graph
     * Running time is O(V + E)
     */
    vector<char> BFS(char src){
        //TODO construct shortest path tree
        vector<int>dist(nodes.size(), INT32_MAX);
        vector<char>prev(nodes.size(), NIL);
        dist[src - 'a'] = 0;
        queue<char>q;
        q.push(src);

        while (!q.empty())
        {
            char u = q.front();
            q.pop();
            for (auto &&v : neighbors[u])
            {   // is it discovered ?
                if (dist[v - 'a'] == INT32_MAX)
                {
                    q.push(v);
                    dist[v - 'a'] = dist[u - 'a'] + 1;
                    prev[v - 'a'] = u;
                }
                
            }
            
        }
        return prev;
    }
    
    /**
     * @brief find the shortest path between two nodes
     * and return the result
     * 
     * @param src 
     * @param dist 
     * @return vector<char> 
     */
    vector<char> shortestPath(char src, char dist){
        vector<char>prev = BFS(src);

        vector<char>result;
        while (src != dist)
        {
            result.push_back(dist);
            if(prev[dist - 'a']  == NIL){
                cout << "path ias not reacable to";
                return result;
            }
            dist = prev[dist - 'a'];
        }

        result.push_back(src);
        reverse(result.begin(), result.end());

        return result;
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

    for (auto &&i : G.shortestPath('c', 'e'))
    {
        cout << i << " -> ";
    }
    cout << "\n";
    return 0;
}