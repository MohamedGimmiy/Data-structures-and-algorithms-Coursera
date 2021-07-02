#include <iostream>
#include <vector>

using namespace std;
int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

long knapsack_maxWeight(vector<long> items, long size,  long W){

    vector<vector<long>>K(items.size()+1, vector<long>(W+1));


    for (int i = 0; i <= items.size(); i++)
    {
        
        for (int w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0){
                K[i][w] = 0;
            }
            else if(items[i-1] <= w){
                K[i][w] = max(items[i-1] + K[i-1][w-items[i-1]],
                 K[i-1][w]);
            }
            else{
                K[i][w] = K[i-1][w];
            }
        }
        
    }
    return K[items.size()][W];
}




int main() {
  long n, W;
  std::cin >> W >> n;
  vector<long> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  //std::cout << optimal_weight(W, w) << '\n';
  std::cout << knapsack_maxWeight(w, w.size(), W) << '\n';
}
