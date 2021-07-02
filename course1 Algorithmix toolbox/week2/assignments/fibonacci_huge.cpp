#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

//3
int getPissano_period(long long m){

    if(m == 2)
        return 3;

    long long prev = 0;
    long long  current = 1;
    long long  res = 0;
    long long  temp;

    for(long long i=0; i< m*m; i++){

        // assign prev to current, current to current + prev 
        // to obtain the new value
        temp = prev;
        prev = current;
        current = (current + temp) % m;

        // if sequence 01
        if(prev == 0 && current == 1)
            res = i + 1;
    }
    return res;

}


long long get_fibonacci_huge_Fast(long long n, long long m) {

    if (n <= 1)
        return n;

    long long period = getPissano_period(m);

    n = n % period;

    long long  current = 1;
    long long prev = 0;
    long long temp;

    // Calculate fibonacci
    for(int i = 0;i< n - 1; ++i){
        temp = prev;
        prev = current;
        current = current + temp;
    }
    return current % m;

}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_Fast(n, m) << '\n';
    //std::cout<< getPissano_period(3) << std::endl;
    return 0;
}
