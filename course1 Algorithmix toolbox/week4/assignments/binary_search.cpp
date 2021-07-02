#include <iostream>
#include <cassert>
#include <vector>
#include<math.h>
using std::vector;

long long  binary_search(const vector<long long> &a, long long x) {
  long long  left = 0, right = (int)a.size(); 
  //write your code here
  long long mid =0;

  while (left <= right)
  {
    /* code */
    mid = left + floor((right - left)/2);

    if(x  == a[mid]){
      return mid;
    } else if(x < a[mid]){
      right = mid-1;
    } else if(x > a[mid]){
      left = mid+1;
    }
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<long long> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
