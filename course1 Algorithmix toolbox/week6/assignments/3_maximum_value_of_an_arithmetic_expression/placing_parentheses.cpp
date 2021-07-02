#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::pair;
long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  return 0;
}

pair<long long, long long> MinAndMax(int i, int j){


  long long _max = INT64_MAX;
  long long _min = INT64_MIN;

  for(int k =i; k<j-1;k++){
    long long a;
    long long b;
    long long c;
    long long d;
    long long _min = min(_min, min(min(min(a, b), c), d));
    long long _max = max(_max, max(max(max(a, b), c), d));
  }



  
  
  return pair<long long, long long>{_min,_max};;
}



int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
