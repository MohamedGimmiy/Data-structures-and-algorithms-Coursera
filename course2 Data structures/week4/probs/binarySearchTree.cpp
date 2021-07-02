#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

struct Node
{
    /* data */
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
    //TODO add height
    int height = 1 + (parent != nullptr? parent->height:0);
    int key;
};

Node *createTree(Node *head, int key)
{

    if (head == nullptr)
    {
        Node *mynode = new Node;
        mynode->key = key;
        head = mynode;
        return head;
    }

    Node *current = head;

    while (current != nullptr)
    {
        if (key > current->key && current->right == nullptr)
        {
            Node *mynode = new Node;
            mynode->key = key;
            mynode->parent = current;
            current->right = mynode;
            current = current->right;
            return head;
        }
        else if (key < current->key && current->left == nullptr)
        {
            Node *mynode = new Node;
            mynode->key = key;
            mynode->parent = current;
            current->left = mynode;
            current = current->left;
            return head;
        }
        else if (key > current->key && current->right != nullptr)
        {
            current = current->right;
        }
        else if (key < current->key && current->left != nullptr)
        {
            current = current->left;
        }
    }

    return head;
}

void breadthFirstTraversal(Node *tree)
{

    if (tree == nullptr)
        return;

    queue<Node *> q;
    q.push(tree);

    while (!q.empty())
    {

        Node *node = q.front();
        q.pop();
        cout << node->key << " ";

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);
    }
}
int Height(Node *tree)
{

    if (tree == nullptr)
        return 0;

    return 1 + max(Height(tree->left), Height(tree->right));
}

void inOrder(Node *tree)
{

    if (tree == nullptr)
        return;
    inOrder(tree->left);
    cout << tree->key << "\n";
    inOrder(tree->right);
}

/**
 * @brief find the node of our key
 * 
 * @param head 
 * @param key 
 * @return Node* 
 */
Node *find(Node *head, int key)
{

    Node *current = head;
    while (current != nullptr)
    {
        if (key == current->key)
        {
            return current;
        }
        else if (key > current->key)
        {
            current = current->right;
        }
        else if (key < current->key)
        { // modification return the closest element
            if (current->left != nullptr)
                current = current->left;
            else
                return current;
        }
    }
    return nullptr;
}

// TODO implement the next function
/**
 * @brief given a node find the largest next node
 * 
 * @param N 
 * @return Node* 
 */
Node *next(Node *N)
{

    if (N != nullptr)
    { // left decendant
        if (N->right != nullptr)
        {
            N = N->right;
            // go left until you find the closest largest node
            // return the left decendant
            while (N->left != nullptr)
            {
                N = N->left;
            }
            return N;
        }
        else
        { // right ancestor
            while (N->parent != nullptr)
                if (N->key < N->parent->key)
                {
                    return N->parent;
                }
                else
                {
                    N = N->parent;
                }
        }
    }
    return nullptr;
}

/**
 * @brief Given two numbers return set of numbers between them
 * 
 * @param x 
 * @param y 
 * @param root 
 */
vector<Node *> rangeSearch(int x, int y, Node *root)
{

    vector<Node *> L;

    Node *N = find(root, x);
    while (N->key <= y)
    {
        if (N->key >= x)
        {
            L.push_back(N);
        }
        N = next(N);
    }

    return L;
}

/**
 * @brief Insert a node in our tree
 * 
 * @param k 
 * @param root 
 */
void insert(int k, Node *root)
{
    Node *p = find(root, k);

    while (p != nullptr)
    {
        if (p->right == nullptr && k > p->key)
        {
            Node *newN = new Node;
            newN->parent = p;
            p->right = newN;
            return;
        }
        else if (p->left == nullptr && k < p->key)
        {
            Node *newN = new Node;
            newN->parent = p;
            p->left = newN;
            return;
        }
        else if (p->key < k)
        {
            p = p->right;
        }
        else if (p->key > k)
        {
            p = p->left;
        }
    }
}

/**
 * @brief TODO (in-progress) not sure is it true or not
 * 
 * @param x 
 * @param root 
 */
void deleteNode(Node*N){
    if(N->right == nullptr){
        Node * NewN = N->left;
        if(N->parent->right->key == N->key){
            N->parent->right = N->left;
            N->left->parent = N->parent;
            delete N;
        }else{
            N->parent->left = N->left;
            N->left->parent = N->parent;
            delete N;
        }
    } else{
        Node*X =next(N);
        Node* Xright = X->right;
        Node* Xparent = X->parent;
        if(X->left == nullptr){
            // replace N by X , X.right will be in place of X
            Node*Nparent = N->parent;
            if(Nparent->right->key == N->key){
                Nparent->right = X;
                X->parent = Nparent;
                X->right = N->right;
                X->left = nullptr;
                delete N;
            }else{
                Nparent->left = X;
                X->parent = Nparent;
                X->right = N->right;
                X->left = nullptr;
                delete N;
            }

            // promote xright to fill x gap
            if(Xparent->key < X->key){
                Xparent->right = Xright;
                Xright->parent = Xparent;
            } else{
                Xparent->left = Xright;
                Xright->parent = Xparent;
            }

        }
    }
}

//------------------- AVL trees ------------------//
// it is a tree where all nodes N, such as |N.left.height - N.right.height| <= 1
// TODO (DONE)

/**
 * @brief AVL Rotate algorithm
 * 
 * @param X 
 * @return Node* 
 */
Node* RotateRight(Node*X){

    Node* P = X->parent;
    Node* Y = X->left;
    Node* B = Y->right;
    Y->parent = P;

    if(P->key > Y->key){
        // y is the left child of P
        P->left = Y;
    } else{
        P->right = Y;
    }
    X->parent = Y;
    Y->right = X;
    B->parent = X;
    X->left = B;

    return Y;
}

// TODO (implementation)
Node* RotateLeft(Node* N){

    return N;
}


void RebalanceRight(Node*N){
    Node*M = N->left;
    if(M->right->height > M->left->height){
        RotateLeft(M);
    }
    RotateRight(N);


    adjustHeight(M);
    adjustHeight(N);
}

//TODO (implement)
void RebalanceLeft(Node* N){

}

void adjustHeight(Node* N){
    N->height = 1 + max(N->left->height , N->right->height);
}

/**
 * @brief Rebalance our tree after doing our operations
 * 
 * @param N 
 */
void Rebalance(Node * N){

    Node* P = N->parent;

    if(N->left->height > N->right->height){
        // rebalanceRight
        RebalanceRight(N);
    }

    if(N->right->height > N->left->height+1){
        RebalanceLeft(N);
    }

    adjustHeight(N);

    if(P != nullptr){
        Rebalance(P);
    }
}



/**
 * @brief Insert a node into an AVL tree
 * 
 * @param k 
 * @param root 
 */
void AVLInsert(int k, Node* root){
    insert(k, root);
    Node* N = find(root, k);
    Rebalance(N);
}

/**
 * @brief Delete an rebalance a node of our AVL tree
 * 
 * @param N 
 */
void AVLDelete(Node*N){

    Node* Nparent = N->parent;
    if(Nparent->right->key == N->key){
        deleteNode(N);
        Rebalance(Nparent->right);
    } else{
        deleteNode(N);
        Rebalance(Nparent->left);
    }
}

/**
 * @brief merge 2 trees with a given node and their roots (helper function)
 * such that R1 < T, R2 > T
 * @param R1 
 * @param R2 
 * @param T 
 * @return Node* 
 */
Node* mergeWithRoot(Node*R1, Node*R2, Node* T){
    T->left = R1;
    T->right = R2;
    R1->parent = T;
    R2->parent = T;
    return T;
}

/**
 * @brief merge two trees without a given node (not enhanced ersion)
 * 
 * @param R1 
 * @param R2 
 * @return Node* 
 */
Node* mergeWithoutRoot_Unimproved(Node*R1, Node*R2){

    // Find the largest element in R1
    Node*T = find(R1, INT32_MAX);
    deleteNode(T);
    mergeWithRoot(R1, R2, T);
    return T;
}

Node* AVLTreemegeWithRoot(Node*R1, Node*R2, Node*T){
    if(abs(R1->height - R2->height) <= 1){
        mergeWithRoot(R1, R2, T);
        T->height = max(R1->height, R2->height) + 1;
        return T;
    } else if(R1->height > R2->height){
        Node* Rp = AVLTreemegeWithRoot(R1->right, R2, T);
        R1->right = Rp;
        Rp->parent = R1;
        Rebalance(R1);
        // return root of our tree
        while(R1->parent != nullptr){
            R1 = R1->parent;
        }
        return R1; 
    } else if(R1->height < R2->height){
        // TODO
    }
}

pair<Node*, Node*> AVLSplit(Node* R, int x){
    if(R == nullptr){
        return make_pair(nullptr, nullptr);
    }
    if(x < R->key){
        pair<Node*, Node*> RR = AVLSplit(R->left, x);
        Node* R3 = mergeWithRoot(RR.second, R->right, R);
        return make_pair(RR.first, R3);
    }

    if(x > R->key){
        //TODO
    }
}

/*-----------------Splay trees--------------------------*/

//TODO
void splay(Node *N){
    // determine proper case 
    // Apply Zig-Zig, Zig-Zag, Zig as appropriate
    if(N->parent != nullptr){
        splay(N);
    }
}

/**
 * @brief Find a node and splay it to the top
 * 
 * @param k 
 * @param R 
 * @return Node* 
 */
Node* STFind(int k, Node*R){
    Node* N = find(R, k);
    splay(N);
    return N;
}

/**
 * @brief Insert a node and splay it to the top
 * 
 * @param k 
 * @param R 
 */
void STInsert(int k, Node*R){
    insert(k, R);
    STFind(k, R);
}

/**
 * @brief STdelete a node
 * 
 * @param N 
 */
void STDelete(Node * N){
    splay(next(N));
    splay(N);

    Node* L = N->left;
    Node*R = N->right;

    R->left = L;
    L->parent = R;
    // set R to be the root (incomplete & incorrect)
    Node*Root = R;
    R->parent = nullptr;
}

//TODO(Completed)
pair<Node*, Node*> cutLeft(Node*N){
    Node*L = N->left;
    N->left = nullptr;
    L->parent = nullptr;
    return make_pair(L,N);
}
//TODO
pair<Node*, Node*> cutRight(Node*N){
    return make_pair(nullptr, nullptr);
}

pair<Node*, Node*> STSplit(Node*R, int x){
    Node*N = find(R,x);
    splay(N);
    if(N->key > x){
        return cutLeft(R);
    } else if(N->key < x){
        return cutRight(N);
    }
    else{
        return make_pair(N->left, N->right);
    }
}

//TODO
void STmerge(Node*R1, Node*R2){
    Node*N = find(R1, INTMAX_MAX);
    splay(N);
    N->right = R2;
    R2->parent = N;
}
//-----------------------------------------------//
int main()
{

    int n, node;
    Node *head = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> node;
        head = createTree(head, node);
    }

    cout << "done\n";
    //inOrder(head);

    if (find(head, 0) == nullptr)
    {
        cout << "not found\n";
    }
    else
    {
        cout << find(head, 0)->key << "\n";
    }

    return 0;
}