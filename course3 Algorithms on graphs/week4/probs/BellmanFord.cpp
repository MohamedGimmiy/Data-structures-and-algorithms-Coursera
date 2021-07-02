#include <iostream>
#include <vector>
#include<queue>
#include<numeric>
#include<algorithm>
#include <map>
#include <set>


#define NIL -1
#define INF  INT32_MAX
using namespace std;

/**
 * @brief Adjacency List (that will be used)
 * note: all nodes are sorted from a to z
 * 
 */
struct nodepair{
    int num;
    int weight;
    nodepair(){}
    nodepair(int num, int weight): num(num), weight(weight){}
};

struct nodesPeriority
{
    bool operator()(const nodepair &n1,const nodepair &n2){
        return n1.weight > n2.weight;
    }
};

class GraphAdjList
{
    vector<nodepair> nodes;

    int nodesNum;
    int src=0, dist=0;
    // node and its neighbors
    map<int, vector<nodepair>> neighbors;

public:
    GraphAdjList()
    {
        int edges;
        cin >> nodesNum >> edges;

        nodes.resize(nodesNum);

        for (size_t i = 0; i < nodesNum; i++)
        {
            nodes[i].num = i;
            nodes[i].weight =  INF;
        }
        
        int node1, node2, weight;
        for (int i = 0; i < edges; i++)
        {
            cin >> node1 >> node2 >> weight;
            nodepair n(node2-1, weight);
            neighbors[(node1-1)].push_back(n);
        }
        cin >> src >> dist;
        src--;
        dist--;
    }
public:
        /**
     * @brief Dikistra searching of a graph
     * used to find the shortest path of unWeighted graph
     * Running time is O(n log n)
     */
    vector<int> BellmanFord(int src){

        //TODO construct shortest path tree
        vector<int>prev(nodes.size(), NIL);
        nodes[src].weight = 0;

        for (size_t i = 0; i < nodes.size()-1; i++)
        {
            // for all edges
            for (auto &&u : neighbors)
            {
                // relax (u,v) //TODO
                for (auto &&v : u.second)
                {
                    if(nodes[u.first].weight + v.weight < nodes[v.num].weight){
                        nodes[v.num].weight = nodes[u.first].weight + v.weight;
                        prev[v.num] = nodes[u.first].num;
                    }
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
        int src = this->src;
        int dist = this->dist;
        vector<int>prev = BellmanFord(src);

        vector<int>result;
        while (src != dist)
        {
            result.push_back(dist);
            if(prev[dist]  == NIL){
                cout << "-1";
                return result;
            }
            dist = prev[dist];
        }

        result.push_back(src);
        reverse(result.begin(), result.end());
        cout << nodes[this->dist].weight << "\n";
        return result;
    }

};

int main()
{

    // Storing a Graph as an AdjList

    GraphAdjList G;

    auto a =G.shortestPath();

    // print our path
    /*cout << "\n";
    for (auto &&i : a)
    {
        cout << i+1 << "  ";
    }*/
    
    return 0;
}