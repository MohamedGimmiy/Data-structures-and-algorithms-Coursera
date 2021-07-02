#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>

#define NIL -1
#define INF INT32_MAX
using namespace std;

//TODO create a periority queue using heap

/**
 * @brief Adjacency List (that will be used)
 * note: all nodes are sorted from a to z
 * 
 */
struct nodepair
{
    int x, y, num;
    double weight;
    nodepair() {}
    nodepair(int x, int y, int num, double weight) : x(x), y(y), num(num), weight(weight) {}
};

struct nodesPeriority
{
    bool operator()(const nodepair &n1, const nodepair &n2)
    {
        return n1.weight > n2.weight;
    }
};

class GraphAdjList
{
    vector<nodepair> nodes;

    int nodesNum;
    // node and its neighbors
    map<nodepair, vector<nodepair>> neighbors;

public:
    GraphAdjList()
    {
        cin >> nodesNum;

        nodes.resize(nodesNum);

        int x, y;
        double weight;
        for (size_t i = 0; i < nodesNum; i++)
        {
            cin >> x >> y;
            // undirected graph
            nodes[i] = nodepair(x, y, i, INT32_MAX);
        }
    }

public:
    /**
     * @brief Dikistra searching of a graph
     * used to find the shortest path of unWeighted graph
     * Running time is O(n log n)
     */
    vector<int> Dikistra()
    {

        //TODO construct shortest path tree
        vector<int> parent(nodes.size(), NIL);
        nodes[0].weight = 0.0;

        priority_queue<nodepair, vector<nodepair>, nodesPeriority> p;

        p.push(nodes[0]);

        //check if processed the node before (ignore it) or not
        vector<bool> processed(nodes.size(), false);

        while (!p.empty())
        {
            //TODO ignore the extracted previously node
            nodepair u = p.top();
            if (!processed[u.num])
            {
                p.pop();
                processed[u.num] = true;
            }
            else
            { // ignore it (skip processing it)
                p.pop();
                continue;
            }

            // looping through all edges related to a node
            for (int i = 0; i < nodesNum; i++)
            {
                 // if (weight of destination) is greater than (u source + edge between u, v)
                    // if v is not in our minimum spanning tree
                    // (not processed as a undirected graph)
                    if (i == u.num)
                        continue;

                    if ((nodes[i].weight >=
                        sqrt(pow(nodes[i].x - u.x, 2) + pow(nodes[i].y - u.y, 2))) &&
                        !processed[i])
                    { // done
                        nodes[i].weight = sqrt(pow(nodes[i].x - u.x, 2) + pow(nodes[i].y - u.y, 2));

                        parent[i] = u.num;

                        p.push(nodes[i]);
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
    void primsAlgorithm()
    {

        vector<int> parent = Dikistra();
        double final=0.0;
        for (int i = 1; i < parent.size(); i++)
        {
            //cout << i << "->" << parent[i] << " ";
            final += sqrt(pow(nodes[i].x - nodes[parent[i]].x, 2) +
             pow(nodes[i].y - nodes[parent[i]].y, 2));
        }
        cout << fixed << setprecision(6) << final;
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