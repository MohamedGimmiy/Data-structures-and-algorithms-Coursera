#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * @brief vector of pair of values and weights
 *  without memoiazation
 * @param items 
 * @param size 
 * @param W 
 * @return int 
 */
int knapsack_rec_maxWeight(vector<pair<int, int>> items, int size,  int W){


    if(W == 0 || size == 0)
        return 0;

    // mecanism is to include and exclude an item till we find the max
    if(items[size -1].second > W){
        return knapsack_rec_maxWeight(items, size-1, W);
    }
    else {
        return max(items[size-1].first + knapsack_rec_maxWeight(items,size-1,W-items[size-1].second),
        knapsack_rec_maxWeight(items, size-1, W));
    }

}


int knapsack_maxWeight(vector<pair<int, int>> items, int size,  int W){

    int K[items.size()+1][W+1];

    for (int i = 0; i <= items.size(); i++)
    {
        
        for (int w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0){
                K[i][w] = 0;
            }

            else if(items[i-1].second <= w){
                K[i][w] = max(items[i-1].first + K[i-1][w-items[i-1].second],
                 K[i-1][w]);
            }
            else{
                K[i][w] = K[i-1][w];
            }
        }
        
    }
    return K[items.size()][W];
}


int main(){

    int W, n;
    vector<pair<int, int>>items{
        pair<int, int>(60,10),
        pair<int, int>(100,20),
        pair<int, int>(120,30)
    };

    // cout<<knapsack_rec_maxWeight(items,items.size(),50);
    cout<<knapsack_maxWeight(items,items.size(),50);

    return 0;
}