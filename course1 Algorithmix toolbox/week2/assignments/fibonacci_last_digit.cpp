#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n){
    if(n <=1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for(int i = 0;i<n-1;i++){
        long long tmp_previous = previous;
        previous = current;
        current = (((tmp_previous%10) + (current%10))%10);
    }

    return current;

}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);

    //std::cout << c << '\n';

    int d = get_fibonacci_last_digit_fast(n);
    std::cout << d << '\n';
}
