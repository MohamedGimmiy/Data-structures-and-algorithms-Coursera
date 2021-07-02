#include<iostream>

using namespace std;



int changeMoney(int n){
    int pieces=0;
    while(n != 0){
    if(n - 10 >= 0){
        n-=10;
        pieces++;
    } else if(n - 5 >= 0){
        n-=5;
        pieces++;
    } else if(n - 1>= 0){
        n-=1;
        pieces++;
    }
    }
    return pieces;

}
int main(){


    int n;
    cin>>n;
    cout<< changeMoney(n);


    return 0;
}