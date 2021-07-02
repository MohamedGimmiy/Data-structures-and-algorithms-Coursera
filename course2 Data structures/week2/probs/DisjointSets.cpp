#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief implementing  Disjoint sets as an array
 * (Naive apprach)
 */
class ArrayDisjointSet
{

    vector<int> smallest;
    int size;
public:
    ArrayDisjointSet(){
        cin >> size;
        smallest.resize(size);
    }
    void makeSet(int x)
    {
        smallest[x] = x;
    }

    int findID(int x)
    {

        return smallest[x];
    }

    void Union(int x, int y)
    {
        int x_id = findID(x);
        int y_id = findID(y);
        if (x_id == y_id)
            return;

        int m = min(x_id, y_id);
        for (int i = 0; i < smallest.size(); i++)
        {
            if (smallest[i] == x_id || smallest[i] == y_id)
            {
                smallest[i] = m;
            }
        }
    }
};

// TODO implementing Disjoint sets as a list

/**
 * @brief How to use? Ans: is by creating an object and enter its size of parent 
 * then use makeset to assing each element to its parent indxes are children
 * and elements are parents
 * Rank : is the height of the subtree
 */
class ListDisjointSet
{
    /**
     * @brief Parent indexes : are childern and elements are parent of them
     * Rank : is the height of the sub tree
     */
    vector<int> parent;
    vector<int>rank;
    int size;
public:
    ListDisjointSet(){
        cin >> size;
        parent.resize(size);
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
        if(x != parent[x]){
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
        if(rank[x_id] > rank[y_id]){
            parent[y_id] = x_id;
        } else
        {
            parent[x_id] = y_id;
            // we merge the two trees and update the 
            // height of the rank
            if(rank[x_id] == rank[y_id]){
                rank[y_id] = rank[y_id] + 1;
            }
        }
        
    }
};



int main()
{
    ArrayDisjointSet D;

    return 0;
}