#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 
 * 
 * @param items vector or pair of weight and value
 * @param W total capacity of our bag
 * @return int max value we obtained
 */
int max_value(vector<pair<int, int>> items, int W)
{

    int value[W + 1];

    for(int i=0;i<=W;i++){
        value[i]=0;
    }

    // looping through all weights from 1 to W
    for (int w = 1; w <= W; w++)
    {
        // looping through all items and choose the suitable item
        // which can fit the max weight
        for (int j = 0; j < items.size(); j++)
        {
            if (items[j].first <= w)
            {
                int val = value[w - items[j].first] + items[j].second;
                if (val > value[w])
                {
                    value[w] = val;
                }
            }
            
        }
    }
    return value[W];
}
int main()
{

    vector<pair<int, int>> items{
        pair<int, int>{6, 30},
        pair<int, int>{3, 14},
        pair<int, int>{4, 16},
        pair<int, int>{2, 9}};

    cout << max_value(items, 10);

    return 0;
}