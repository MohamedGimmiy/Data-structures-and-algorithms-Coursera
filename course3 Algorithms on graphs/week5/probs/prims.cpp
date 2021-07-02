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


//TODO create a periority queue using heap

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
    int src=0;
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
        for (size_t i = 0; i < edges; i++)
        {
            cin >> node1 >> node2 >> weight;
            // undirected graph
            neighbors[(node1-1)].push_back(nodepair(node2-1, weight));
            neighbors[(node2-1)].push_back(nodepair(node1-1, weight));
        }
        cin >> src;
        src--;
    }
public:
        /**
     * @brief Dikistra searching of a graph
     * used to find the shortest path of unWeighted graph
     * Running time is O(n log n)
     */
    vector<int> Dikistra(int src){

        //TODO construct shortest path tree
        vector<int>parent(nodes.size(), NIL);
        nodes[src].weight = 0;

        priority_queue<nodepair,vector<nodepair>, nodesPeriority> p;

        p.push(nodes[src]);

        //check if processed the node before (ignore it) or not 
        vector<bool>processed(nodes.size(), false);

        
        while (!p.empty())
        {   
            //TODO ignore the extracted previously node
            nodepair u = p.top();

            if(!processed[u.num]){
                p.pop();
                processed[u.num] = true;
            } else { // ignore it (skip processing it)
                p.pop();
                continue;
            }

            // looping through all edges related to a node
            for (auto &&v : neighbors[u.num])
            {   // if (weight of destination) is greater than (u source + edge between u, v) 
                // if v is not in our minimum spanning tree
                // (not processed as a undirected graph)
                if ((nodes[v.num].weight >= u.weight + v.weight) && !processed[v.num])
                {   // done
                    nodes[v.num].weight =  v.weight;

                    parent[v.num] = u.num;

                    p.push(nodepair(v.num, nodes[v.num].weight));
                }
                
            }
        }
        return parent;
    }
    
    /**
     * @brief constructing minimum spanning tree
     * using Dikistra algorithm
     * 
     * @param src 
     * @param dist 
     * @return vector<char> 
     */
    void primsAlgorithm(){

        int src = this->src;
        vector<int>parent = Dikistra(src);

        for (int i=0;i<parent.size();i++){
            cout << i+1 << "->" << parent[i]+1 << " ";
        }

    }

};

int main()
{

    // Storing a Graph as an AdjList

    GraphAdjList G;

    G.primsAlgorithm();

    // print our path
    /*cout << "\n";
    for (auto &&i : a)
    {
        cout << i+1 << "  ";
    }*/
    
    return 0;
}