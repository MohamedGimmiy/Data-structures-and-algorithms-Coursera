#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


void merge(vector<long long >&b, vector<long long>&c, vector<long long>&a){
    //TODO
    int i = 0, j=0, k =0;

    while( j < b.size() && k < c.size() ){
        if(b.at(j) < c.at(k)){
            a.at(i) = b.at(j);
            j++;
        } else {
            a.at(i) = c.at(k);
            k++;
        }
        i++;
    }
    while(k <c.size()){
            a.at(i) = c.at(k);
            k++; i++;
        }
    while(j <b.size()){
            a.at(i) = b.at(j);
            j++; i++;
    }

}

int findTheLargest(vector<long long>&a){
    int count = 0;
    long long current = a.at(0);
    for (size_t i = 0; i < a.size(); i++)
    {   
        if(a.at(i) == current){
            ++count;
            if(count > a.size()/2)
                return 1;
        } else{
            current = a.at(i);
            count = 1;
        }
    }
    return 0;
}
void mergeSort(vector<long long>& a){
    //TODO
    if(a.size() <= 1){
        return;
    }

    int m = a.size()/2;

    vector<long long>b;
    vector<long long>c;



    for(int i = 0; i < m; i++)
        b.push_back(a.at(i));

    for(int i = 0; i < (a.size()-m);i++)
        c.push_back(a.at(i + m));
    
    

    mergeSort(b);
    mergeSort(c);

    merge(b, c, a);
    
}

int get_majority_element(vector<long long> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here

  mergeSort(a);

  return findTheLargest(a);
}


int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
