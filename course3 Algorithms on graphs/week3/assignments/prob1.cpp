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
    vector<int> nodes;
    vector<bool> visited;
    int nodesNum;
    int src, dist;
    // node and its neighbors
    map<int, unordered_set<int>> neighbors;


public:
    GraphAdjList()
    {
        int edges;
        cin >> nodesNum >> edges;
        vector<bool> visited(nodesNum, false);
        this->visited = visited;

        nodes.resize(nodesNum);
        iota(nodes.begin(), nodes.end(), 0);
        
        int node1, node2;
        for (size_t i = 0; i < edges; i++)
        {
            cin >> node1 >> node2;
            neighbors[(node1-1)].insert((node2-1));
            neighbors[(node2-1)].insert((node1-1));
        }


        
        cin >> src >> dist;
        src--;
        dist--;
    }
public:
    /**
     * @brief Breadth-first-search of a graph
     * used to find the shortest path of unWeighted graph
     * Running time is O(V + E)
     */
    vector<int> BFS(int src) {
        //TODO construct shortest path tree
        vector<int>dist(nodes.size(), INT32_MAX);
        vector<int>prev(nodes.size(), NIL);
        dist[src] = 0;
        queue<int>q;
        q.push(src);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &&v : neighbors[u])
            {   // is it discovered ?
                if (dist[v] == INT32_MAX)
                {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    prev[v] = u;
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
    vector<int> shortestPath(){

        vector<int>prev = BFS(src);
        
        vector<int>result;
        while (src != dist)
        {
            result.push_back(dist);
            if(prev[dist]  == NIL){
                cout << -1;
                result.resize(0);
                return result;
            }
            dist = prev[dist];
        }

        result.push_back(src);
        reverse(result.begin(), result.end());
        cout<<result.size()-1;
        return result;
    }
    
};

int main()
{

    // Storing a Graph as an AdjList
    GraphAdjList G;

    G.shortestPath();
    return 0;
}