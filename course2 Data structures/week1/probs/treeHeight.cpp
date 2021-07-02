#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    /* data */
    Node* left = nullptr;
    Node* right = nullptr;
    int key;
};

Node* createTree(Node* head, int key){

    if(head == nullptr){
        Node * mynode = new Node;
        mynode->key = key;
        head = mynode;
        return head;
    }

    Node* current = head;

    while(current != nullptr){
        if(key > current->key && current->right == nullptr){
            Node * mynode = new Node;
            mynode->key = key;
            current->right = mynode;
            current = current->right;
            return head;
        } else if(key < current->key && current->left == nullptr){
            Node * mynode = new Node;
            mynode->key = key;
            current->left = mynode;
            current = current->left;
            return head;
        } else if(key > current->key && current->right != nullptr){
                current = current->right;
        } else if(key < current->key && current->left != nullptr){
            current = current->left; 
        }
    }

    return head;
}

void breadthFirstTraversal(Node*tree){

    if(tree == nullptr)
        return;

    queue<Node*>q;
    q.push(tree);

    while (!q.empty())
    {

        Node* node = q.front();
        q.pop();
        cout << node->key << " ";

        if(node->left != nullptr)
            q.push(node->left);

        if(node->right != nullptr)
            q.push(node->right);
    }

}
int Height(Node * tree){

    if(tree == nullptr)
        return 0;

    return 1 + max(Height(tree->left), Height(tree->right));
}


void inOrder(Node*tree){

    if(tree == nullptr)
        return;
    inOrder(tree->left);
    cout << tree->key << "\n";
    inOrder(tree->right);
}
int main(){

    int n, node;
    Node * head = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> node;
        head = createTree(head, node);
    }
    
    cout << "done\n";
    inOrder(head);





    return 0;
}