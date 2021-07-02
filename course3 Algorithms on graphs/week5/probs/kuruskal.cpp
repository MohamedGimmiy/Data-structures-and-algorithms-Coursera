#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>

#define NIL -1
#define INF INT32_MAX
using namespace std;
// TODO debugging

/**
 * @brief Adjacency List (that will be used)
 * note: all nodes are sorted from a to z
 * 
 */
struct nodepair
{
    int num;
    int weight;
    nodepair() {}
    nodepair(int num, int weight) : num(num), weight(weight) {}
};

struct nodesPeriority
{
    bool operator()(const nodepair &n1, const nodepair &n2)
    {
        return n1.weight > n2.weight;
    }
};
class ListDisjointSet
{
    /**
     * @brief Parent indexes : are childern and elements are parent of them
     * Rank : is the height of the sub tree
     */
    vector<int> parent;
    vector<int> rank;
    int size;

public:
    ListDisjointSet()
    {
        cin >> size;
        parent.resize(size);
    }

    ListDisjointSet(int x) : size(x)
    {
        parent.resize(x);
        rank.resize(x);
        for (size_t i = 0; i < size; i++)
        {
            makeSet(i);
        }
        
    }

    void makeSet(int x)
    {
        parent[x] = x;
        rank[x] = 0;
    }

    int findID(int x)
    {
        // implementing path compression
        // by attaching all nodes directly to the root parent
        // path compression technique  log * n
        if (x != parent[x])
        {
            parent[x] = findID(parent[x]);
        }
        return parent[x];
        //while (x != parent[x])
        //{
        //    x = parent[x];
        //}
        //return x;
    }

    void Union(int x, int y)
    {
        int x_id = findID(x);
        int y_id = findID(y);
        if (x_id == y_id)
            return;
        // if the height of the first tree is larger than the second
        // merge the smaler of height to the larger
        if (rank[x_id] > rank[y_id])
        {
            parent[y_id] = x_id;
        }
        else
        {
            parent[x_id] = y_id;
            // we merge the two trees and update the
            // height of the rank
            if (rank[x_id] == rank[y_id])
            {
                rank[y_id] = rank[y_id] + 1;
            }
        }
    }
};

struct Edge
{
    int node1, node2, weight;

    Edge(int node1, int node2, int weight) : node1(node1),
                                            node2(node2),
                                            weight(weight) {}
};
class GraphAdjList
{
    vector<nodepair> nodes;

    int nodesNum;
    // node and its neighbors
    map<int, vector<nodepair>> neighbors;
    vector<Edge> Edges;

public:
    static bool sortEdge(const Edge &e1, const Edge &e2)
    {
        return e1.weight < e2.weight;
    }

    struct setComparator
    {
        bool operator()(const Edge &e1, const Edge &e2)
        {

             if(e1.node1 == e2.node1 && e1.node2 == e2.node2){
                 return false;
             } else if(e1.node1 == e2.node2  && e1.node2 == e2.node1){
                 return false;
             } else{
                 return true;
             }
        }
    };

    GraphAdjList()
    {
        int edges;
        cin >> nodesNum >> edges;

        nodes.resize(nodesNum);

        for (size_t i = 0; i < nodesNum; i++)
        {
            nodes[i].num = i;
            nodes[i].weight = INF;
        }

        int node1, node2, weight;
        for (size_t i = 0; i < edges; i++)
        {
            cin >> node1 >> node2 >> weight;

            // Constructing undirected graph
            neighbors[(node1 - 1)].push_back(nodepair(node2 - 1, weight));
            neighbors[(node2 - 1)].push_back(nodepair(node1 - 1, weight));

            // Adding edges pairs
            Edges.push_back(Edge(node1 - 1, node2 - 1, weight));
        }
    }
    /**
     * @brief Dikistra searching of a graph
     * used to find the shortest path of unWeighted graph
     * Running time is O(n log n)
     */
    set<Edge, setComparator> Kruskal()
    {

        //TODO construct shortest path tree
        ListDisjointSet Disj(nodes.size());

        set<Edge, setComparator> X;

        // sorting our edges
        sort(Edges.begin(), Edges.end(), sortEdge);

        for (auto &&edge : Edges)
        {
            if (Disj.findID(edge.node1) != Disj.findID(edge.node2))
            {
                X.insert(edge);
                Disj.Union(edge.node1, edge.node2);
            }
        }
        return X;
    }
};

int main()
{

    // Storing a Graph as an AdjList

    GraphAdjList G;

    for (auto &&i : G.Kruskal())
    {
        cout << i.node1 << "-> " << i.node2 << " ";
    }

    return 0;
}