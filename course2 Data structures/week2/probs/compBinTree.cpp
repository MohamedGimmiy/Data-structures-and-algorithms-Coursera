#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Illustrating complete binary trees,(periority queue) (max heap) that 
 * implements the periority Queue and its operations
 * all work done in it is O(log n) (getMax is O(1) )
 * @return int 
 */

/**
 * @brief Create a Max Heap
 * 
 * @param tree 
 * @param maxSize 
 * @param size 
 */
void createMaxHeap(int tree[], int maxSize, int size){
    int temp;
    for(int i=0;i<size;i++){
        cin >> temp;
        tree[i] = temp;
    }
}

/**
 * @brief Get the Parent object
 * 
 * @param tree 
 * @param index 
 * @return pair<int, int> element and its position
 */
pair<int, int> getParent(int tree[], int index){
    return pair<int , int>(tree[(index-1)/2], (index-1)/2);
}

/**
 * @brief Get the Left Child object
 * 
 * @param tree 
 * @param index 
 * @return pair<int, int> 
 */
pair<int, int> getLeftChild(int tree[], int index){
    return pair<int , int>(tree[(2*index)+1], (2*index) + 1);
}

/**
 * @brief Get the Right Child object
 * 
 * @param tree 
 * @param index 
 * @return pair<int, int> 
 */
pair<int, int> getRightChild(int tree[], int index){
    return pair<int, int>(tree[(2*index) + 2], (2*index) +2);
}

/**
 * @brief Shifting up our element to make a complete binary tree
 * 
 * @param arr 
 * @param i 
 */
void shiftUp(int arr[], int i){
    // while element not root and greater than its parent
    while (i > 0 && (arr[getParent(arr,i).second] < arr[i]))
    {
        swap(arr[getParent(arr,i).second], arr[i]);
        i = getParent(arr,i).second;
    }
}

/**
 * @brief shift down element of tree to be a 
 *        complete binary tree
 * @param arr 
 * @param i 
 * @param size 
 */
void shiftDown(int arr[], int i, int size){

    int maxIndex = i;

    int leftChildIndex = getLeftChild(arr, i).second;
    int leftChild = getLeftChild(arr, i).first;

    if(leftChildIndex <= size && leftChild > arr[maxIndex]){
        maxIndex = leftChildIndex;
    }

    int rightChildIndex = getRightChild(arr, i).second;
    int rightChild = getRightChild(arr, i).first;

    if(rightChildIndex <= size && rightChild > arr[maxIndex]){
        maxIndex = rightChildIndex;
    }

    if(i != maxIndex){
        swap(arr[i], arr[maxIndex]);
        shiftDown(arr, maxIndex, size);
    }
}

/**
 * @brief Insert an element into our binary tree (max heap)
 * 
 * @param tree 
 * @param size 
 * @param maxSize 
 * @param p 
 */
void Insert(int tree[],int size, int maxSize, int p){
    if(size == maxSize){
        cout << "Error";
        return;
    }
    size++;
    tree[size] = p;
    shiftUp(tree, size);
}

/**
 * @brief Extracting the maximum element
 * 
 * @param tree 
 * @param size 
 * @return int 
 */
int extractMax(int tree[], int size){
    int result = tree[0];
    tree[1] = tree[size];
    size--;
    shiftDown(tree, 1, size);
    return result;
}

/**
 * @brief Removing an element of a tree
 * 
 * @param tree 
 * @param i 
 * @param size 
 */
void Remove(int tree[], int i, int size){
    tree[i] = INT32_MAX;
    shiftUp(tree, i);
    extractMax(tree, size);
}

/**
 * @brief changing the periority of an element
 * 
 * @param i 
 * @param p 
 * @param tree 
 * @param size 
 */
void changePeriority(int i, int p, int tree[], int size){
    int oldPeriority = tree[i];
    tree[i] = p;
    if(p > oldPeriority)
        shiftUp(tree, i);
    else
    {
        shiftDown(tree, i, size);
    }
    
}
// TODO heap sort function
// TODO turn an array to a heap
int main(){

    int max_size;
    int size;
    int arr[max_size];
    cin >> size >> max_size;
    createMaxHeap(arr, max_size, size);


    // get parent of ith = i/2
    // get left child of ith = 2*i
    // get right child of ith = 2*i + 1
    getParent(arr,1);
    getLeftChild(arr,1);
    getRightChild(arr,1);



    return 0;
}