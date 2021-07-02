#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief find the farest refill that can car stop at to fuel
 * and calculate the number of refills that our car stops at
 * Greedy algorithm that has a safe move
 * 
 * @param GasStations 
 * @param numberOfRefills 
 * @param AllowedDistance 
 * @return int (zero if it is impossible else number of refills)
 */
int numOfRefills(vector<int> &GasStations, int numberOfRefills, int AllowedDistance)
{

    int ResultNumOfRefills(0), currentRefillDistance(0);

    int lastRefillDistance;
    while (currentRefillDistance <= numberOfRefills)
    {
        lastRefillDistance = currentRefillDistance;

        while (currentRefillDistance <= numberOfRefills &&
               GasStations.at(currentRefillDistance + 1) - GasStations.at(lastRefillDistance)
                <= AllowedDistance)
        {
            currentRefillDistance++;
        }
        if (currentRefillDistance == lastRefillDistance)
        {
            return 0;
        }
        if (currentRefillDistance <= numberOfRefills)
        {
            ResultNumOfRefills++;
        }
    }

    return ResultNumOfRefills;
}
int main()
{

    int numberOfRefills, AllowedDistance;
    vector<int> GasStations;

    return 0;
}