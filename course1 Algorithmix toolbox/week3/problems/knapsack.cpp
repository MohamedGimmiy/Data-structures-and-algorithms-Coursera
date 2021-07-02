#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @brief 
 * @param things vector of pairs of(weight, value)
 * @param KnapsackWeight 
 * @return int 
 */
int knapsack(int KnapsackWeight, vector<pair<int,int>>things){

    vector<int>amounts(things.size(),0);
    int totalVal =0;

    int maxValuableElement=0;
    int selectedElement;

    for(int i=0;i<things.size();i++){
        if(KnapsackWeight == 0){
            return totalVal;
        }

    for(int i =0;i<things.size();i++){
        // if weight is not consumed (>0) and we choose the max valuable element
        // then select it
        if(things.at(i).first >0 &&
         (things.at(i).second/things.at(i).first) >= maxValuableElement){
            maxValuableElement = things.at(i).second/things.at(i).first;
            selectedElement = i;
        }
    }

    int weight = min(KnapsackWeight, things.at(selectedElement).first);
    // increase the total value by the chosen elemnt to take
    totalVal+= weight * (things.at(selectedElement).second/things.at(selectedElement).first);

    // decrease that weight from the element
    things.at(selectedElement).first -= weight;

    // add the amount taken to our bag of this element
    amounts.at(i)+=weight;

    // decrease the weight space of our bag until it reachs zero
    KnapsackWeight-= weight;

    }

    // cout amounts
    for(int i=0;i<amounts.size();i++){
        cout<<amounts.at(i) << " ";
    }
    return totalVal;

}

int main(){


    vector<pair<int, int>> myvector;
    myvector.push_back(pair<int,int>(4,20));
    myvector.push_back(pair<int,int>(3,18));
    myvector.push_back(pair<int,int>(2,14));

    knapsack(7,myvector);


    return 0;
}