#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node
{
  long long key;
  long long left;
  long long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, long long left_, long long right_) : key(key_), left(left_), right(right_) {}
};

bool find(long long num, const vector<Node> &tree)
{

  long long i = 0;
  while (i != -1)
  {
    if (tree[i].key > tree[num].key)
    {
      i = tree[i].left;
    }
    else if (tree[i].key < tree[num].key)
    {
      i = tree[i].right;
    }
    else if (tree[i].key == tree[num].key)
    {
      return true;
    }
  }

  return false;
}

// solution is O(n log n) correct but not efficiet
bool IS_BST1(const vector<Node> &tree)
{
  for (long long i = 1; i < tree.size(); i++)
  {
    // find that node
    if (!find(i, tree))
    {
      return false;
    }
  }
  return true;
}

bool IS_BST2_in_order(long long nodeNum, const vector<Node> &tree)
{

  static long long prev = INT64_MIN;

  if (nodeNum != -1)
  {

    // Finish the implementation
    // You may need to add a new recursive method to do that

    if (!IS_BST2_in_order(tree[nodeNum].left, tree))
      return false;

    if(tree[nodeNum].left != -1 && tree[nodeNum].right != -1){
      if(tree[nodeNum].key > tree[tree[nodeNum].right].key ||
       tree[nodeNum].key <= tree[tree[nodeNum].left].key){
         return false;
      }
    } else if(tree[nodeNum].left != -1 && tree[nodeNum].right == -1){
      if(tree[nodeNum].key <= tree[tree[nodeNum].left].key){
         return false;
      }
    } else if(tree[nodeNum].left == -1 && tree[nodeNum].right != -1){
      if(tree[nodeNum].key > tree[tree[nodeNum].right].key){
         return false;
      }
    }

    if (prev > tree[nodeNum].key)
    {
      return false;
    }

    prev = tree[nodeNum].key;

    return IS_BST2_in_order(tree[nodeNum].right, tree);
  }

  return true;
}

bool IsBinarySearchTree(const vector<Node> &tree)
{
  if (tree.size() == 0)
    return true;
  // Implement correct algorithm here

  // TODO find algorithms for each node till we hit the case of not finding
  // or we succeed in finding the element O(n log n)

  // solution-1 time compexity O(n log n)
  //IS_BST1(tree);

  // solution 2 using in-order traversal O(n)
  return IS_BST2_in_order(0, tree);
}

int main()
{
  long long nodes;
  cin >> nodes;
  vector<Node> tree;
  for (long long i = 0; i < nodes; ++i)
  {
    long long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree))
  {
    cout << "CORRECT" << endl;
  }
  else
  {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
