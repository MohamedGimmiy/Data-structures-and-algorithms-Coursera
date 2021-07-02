#include<iostream>
#include<vector>
using namespace std;


vector<vector<double>> POintsCoverStored(vector<double>& Points){

    vector<vector<double>> R;
    int i=1;
    while(i<=Points.size()){

        // create ur segment (range) 
        // (grouping children together that at most has 1 year difference)
        double left = Points.at(i);
        double right = left+1;

        // add to the solution set
        // return a segment (range from left to right (vector))
        // R = R union {[l, r]}
        i++;
        while(i<=Points.size()&& Points.at(i) <= right){
            i++;
        }
    }

    return R;
}
int main(){






    return 0;
}