#include <iostream>
#include <vector>

using namespace std;

int numOfCoins = INT32_MAX;

int RecursiveChange(int money, vector<int> &coins)
{
    //TODO fix it
    if (money == 0)
        return 0;

    int minNumberOfCoins = INT32_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        if (money >= coins.at(i))
        {
            numOfCoins = RecursiveChange(money - coins.at(i), coins);

            if (numOfCoins + 1 < minNumberOfCoins && numOfCoins != INT32_MAX)
            {
                minNumberOfCoins = numOfCoins + 1;
            }
        }
    }
    return minNumberOfCoins;
}

int DPChange(int money, vector<int> coins)
{

    int *table = new int[money+1];
    table[0]=0;

    for(int i=1;i<=money;i++){
        table[i] = INT32_MAX;
    }

    for (size_t i = 1; i <= money; i++)
    {
        for (size_t j = 0; j < coins.size(); j++)
        {
            if(coins[j] <= i){
                int sub_res = table[i-coins[j]];
                if(sub_res != INT32_MAX && sub_res + 1 < table[i]){
                    table[i] = sub_res + 1;
                }
            }
        }
        
    }
    return table[money];
}
int main()
{
    int t;
    vector<int> coins{1, 3, 4};
    cin >>t;
    //cout << RecursiveChange(3, coins) << "\n";
    cout << DPChange(t, coins);
    return 0;
}