#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;

int computeFibonacci(int n){

    vector<int>myvector(n+1,0);

    myvector[0] = 0;
    myvector[1] = 1;

    for(int i=2; i<= n;i++){
        myvector[i] = myvector[i-1] + myvector[i-2];
    }
    return myvector[n];
}

int computeFibonacciRec(int n){

    if(n <= 1)
        return n;
    
    return computeFibonacciRec(n - 1) + computeFibonacciRec(n - 2);
}
int main(){


    cout<< computeFibonacci(30) << std::endl;
    cout<< computeFibonacciRec(30) << std::endl;

    return 0;
}