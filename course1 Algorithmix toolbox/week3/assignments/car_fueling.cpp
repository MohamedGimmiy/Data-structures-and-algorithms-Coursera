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
int numOfRefills(vector<int> &GasStationsStops,
 int numberOfRefills,
 int AllowedDistance,
 int destination)
{

    int ResultNumOfRefills(0), currentRefill(0);
    int lastRefill(0);


    while (currentRefill <= numberOfRefills)
    {
        lastRefill = currentRefill;

        while (currentRefill <= numberOfRefills &&
               GasStationsStops.at(currentRefill+1) - GasStationsStops.at(lastRefill)
                <= AllowedDistance)
        {
            currentRefill++;
        }
        if (currentRefill == lastRefill)
        {
            return -1;
        }
        if (currentRefill <= numberOfRefills)
        {
            ResultNumOfRefills++;
        }
    }

    return ResultNumOfRefills;
}
int main()
{

    int numberOfRefills_n, AllowedDistance_m, destination_d;
    int gasStop;
    vector<int> GasStations;

    cin>>destination_d>>AllowedDistance_m>>numberOfRefills_n;
    GasStations.push_back(0);
    for(int i=0;i<numberOfRefills_n;i++){
        cin>>gasStop;
        GasStations.push_back(gasStop);
    }
    GasStations.push_back(destination_d);
    // call function here
    cout << numOfRefills(GasStations, 
        numberOfRefills_n, 
        AllowedDistance_m, 
        destination_d);

    return 0;
}