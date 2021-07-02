#include<iostream>

using namespace std;

// Euclidean algorithm
int gcd(int a, int b){

    if(b == 0)
        return a;

    return gcd(b , a % b);
}
int main(){

    cout << gcd(1, 1);

    return 0;
}