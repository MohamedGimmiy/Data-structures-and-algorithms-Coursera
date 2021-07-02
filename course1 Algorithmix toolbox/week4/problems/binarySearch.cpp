#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int BinarySearch(vector<int>&a, int low, int high, int key){

    // if low is greater than high 
    // return the largest element index
    if(high < low)
        return low-1;


    int mid = low + floor( (high - low)/2);

    if(key == a.at(mid)){
        return mid;
    } 
    else if(key < a.at(mid)){
        return BinarySearch(a, low, mid-1, key);
    } else if(key > a.at(mid)){
        return BinarySearch(a, mid+1, high, key);
    }



}
int main(){


    vector<int>a;
    a.push_back(1);
    a.push_back(11);
    a.push_back(12);
    a.push_back(15);
    a.push_back(18);
    a.push_back(20);

    cout << BinarySearch(a,0,a.size()-1,100) << "\n";

    return 0;
}