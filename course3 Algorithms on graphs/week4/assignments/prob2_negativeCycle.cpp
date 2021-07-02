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
    long num;
    long weight;
    nodepair(){}
    nodepair(long num, long weight): num(num), weight(weight){}
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

    long nodesNum;
    long src=0;
    // node and its neighbors
    map<long, vector<nodepair>> neighbors;

public:
    GraphAdjList()
    {
        long edges;
        cin >> nodesNum >> edges;

        nodes.resize(nodesNum);

        for (size_t i = 0; i < nodesNum; i++)
        {
            nodes[i].num = i;
            nodes[i].weight =  INF;
        }
        
        long node1, node2, weight;
        for (long i = 0; i < edges; i++)
        {
            cin >> node1 >> node2 >> weight;
            nodepair n(node2-1, weight);
            neighbors[(node1-1)].push_back(n);
        }
    }
public:
        /**
     * @brief Dikistra searching of a graph
     * used to find the shortest path of unWeighted graph
     * Running time is O(n log n)
     */
    void BellmanFord(){
        src = this->src;
        //TODO construct shortest path tree
        vector<long>prev(nodes.size(), NIL);
        nodes[src].weight = 0;

        for (long i = 0; i < nodes.size(); i++)
        {
            // for all edges
            for (auto &&u : neighbors)
            {
                // relax (u,v) //TODO
                for (auto &&v : u.second)
                {
                    if(nodes[u.first].weight + v.weight < nodes[v.num].weight){
                        if(i == nodes.size()-1){
                            cout << 1;
                            return;
                        }
                        nodes[v.num].weight = nodes[u.first].weight + v.weight;
                        prev[v.num] = nodes[u.first].num;
                    }
                }
            }
        }
        cout << 0;
        return;
    }
    

};

int main()
{
    GraphAdjList G;
    G.BellmanFord();
    return 0;
}