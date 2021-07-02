#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <iterator>
using namespace std;

// DONE
/**
 * @brief EdgesList Graph implementation
 * 
 */
class GraphEdgesList
{

    vector<pair<char, char>> Edges;
    unordered_set<char> nodes;
    int nodesNum;

public:
    GraphEdgesList()
    {
        cin >> nodesNum;
        char temp;

        for (int i = 0; i < nodesNum; i++)
        {
            cin >> temp;
            nodes.insert(temp);
        }
    }
    //TODO check if it exist or not first
    void makeEdge(char a, char b)
    {
        if (nodes.find(a) == nodes.end() || nodes.find(b) == nodes.end())
        {
            cout << "not found\n";
            return;
        }
        //check if our edge exist or not first
        //TODO
        Edges.push_back(make_pair(a, b));
    }

    void printNodes()
    {
        for (auto it = nodes.begin(); it != nodes.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
    void printEdges()
    {
        for (size_t i = 0; i < Edges.size(); i++)
        {
            cout << Edges[i].first << "--->" << Edges[i].second;
            cout << "\n";
        }
    }
};

//DONE (implementation)
/**
 * @brief Adjacency matrix 2d matrix Graph implementation
 * 
 */
class GraphAdjMat
{

    int nodesNum;
    vector<vector<int>> adjMat;
    map<char, int> m;

public:
    GraphAdjMat()
    {
        cin >> nodesNum;
        // initializing 2d matrix 0x0
        vector<vector<int>> NewadjMat(nodesNum, vector<int>(nodesNum, 0));
        adjMat = NewadjMat;

        char temp;
        for (size_t i = 0; i < nodesNum; i++)
        {
            cin >> temp;
            m[temp] = i;
        }
    }

    void addEdges(char a, char b)
    {
        if (m.find(a) == m.end() || m.find(b) == m.end())
        {
            cout << "not found!\n";
            return;
        }

        adjMat[(a - 'a')][(b - 'a')] = 1;
    }

    void printEdges()
    {
        for (size_t i = 0; i < adjMat.size(); i++)
        {
            for (size_t j = 0; j < adjMat[i].size(); j++)
            {
                if (adjMat[i][j] == 1)
                {
                    cout << (char)('a' + i) << "---->" << (char)('a' + j) << "\n";
                }
            }
        }
    }

    bool isEdgeExist(char a, char b)
    {
        return (adjMat[m[a]][m[b]] == 1);
    }
};

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
        neighbors[b].insert(a);
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

    void postvisit(char v, int &clock)
    {
        clockOrder[v].second = clock;
        ++clock;
    }

    /**
     * @brief explore our neighbors of nodes
     * helper function of DFs
     * @param a 
     */
    void Explore(char a, int &label, int & clock)
    {

        visited[a - 'a'] = true;
        previsit(a, clock);

        // print each node with its group number
        cout << a << label << " -> ";
        for (auto &&i : neighbors[a])
        {
            if (!visited[i - 'a'])
            {
                Explore(i, label, clock);
            }
        }
        postvisit(a, clock);
    }

public:
    /**
     * @brief Explore all nodes of our graph
     * using Depth-first-search
     * 
     */
    void DFS()
    {
        int label = 1;
        int clock = 1;
        for (auto &&i : nodes)
        {
            if (!visited[i - 'a'])
            {
                Explore(i, label, clock);
                label++;
            }
        }
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
};

int main()
{
    // Storing a Graph as a list
    /*GraphEdgesList my;
    my.makeEdge('a','f');
    my.makeEdge('b','c');
    my.makeEdge('a','c');
    my.printEdges();
    my.printNodes();*/

    // Storing a Graph as an AdjMat
    /*GraphAdjMat G;
    G.addEdges('a', 'b');
    G.addEdges('a', 'z');
    G.addEdges('c', 'd');
    G.addEdges('b', 'c');
    G.printEdges();
    cout << boolalpha << G.isEdgeExist('b','c') << "\n";
    cout << boolalpha << G.isEdgeExist('f','c') << "\n";*/

    // Storing a Graph as an AdjList
    GraphAdjList G;
    G.makeEdge('a', 'b');
    G.makeEdge('a', 'c');
    G.makeEdge('a', 'e');
    G.makeEdge('b', 'c');
    G.makeEdge('b', 'e');
    G.printEdges();
    //G.Explore('a');
    G.DFS();
    G.printPrePostVisitClockOrder();
    return 0;
}