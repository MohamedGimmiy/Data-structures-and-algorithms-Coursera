#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

vector<int> SelectionSort(vector<int>&a){



    for (size_t i = 0; i < a.size(); i++)
    {
        /* code */
        int minel = i;
        for(int j=i+1;j<a.size();j++){
            if(a.at(j)<a.at(minel)){
                minel =  j;
            }
        }
        swap(a.at(i),a.at(minel));
    }
    
    return a;
}

void merge(vector<int>&b, vector<int>&c, vector<int>&a){
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

void mergeSort(vector<int>& a){
    //TODO
    if(a.size() <= 1){
        return;
    }

    int m = a.size()/2;

    vector<int>b;
    vector<int>c;



    for(int i = 0; i < m; i++)
        b.push_back(a.at(i));

    for(int i = 0; i < (a.size()-m);i++)
        c.push_back(a.at(i + m));
    
    

    mergeSort(b);
    mergeSort(c);

    merge(b, c, a);
    
}


// TODO counting sort O(n)
void countingSort(vector<int>&a, int maxElement){
    vector<int>result(maxElement+1,0);
    vector<int>original;
    for(int i=0;i<a.size();i++){
        result.at(a.at(i))++;
    }

    for(int i=0;i<result.size();i++){
        if(result.at(i) != 0){
            for(int j=0;j<result.at(i);j++){
                        original.push_back(i);
            }
        }
    }
    a = original;
}

// TODO quick sort O(n^2), n(log(n))
int partition(vector<int>&a, int l, int r){
    int pivot = a.at(l);
    int j = l;
    for(int i=l+1; i<r; i++){
        if(a.at(i)<pivot){
            j++;
            swap(a.at(j), a.at(i));
        }
    }
    swap(a.at(l), a.at(j));
    return j;
}

void quickSort(vector<int>&a, int l, int r){
    if(l>=r)
        return;

    // Randomized quick sort (update 1)
    //int k = (rand() % (r+1)) + l;
    //swap(a.at(l), a.at(k));

    // Splitting into 3 regions update(2)

    int m = partition(a, l, r);

    quickSort(a, l, m-1);
    
    quickSort(a, m+1, r);
}


int main(){



    vector<int>my{2, 3, 9, 2, 2, 10, 18, 4, 1};

    //SelectionSort(my);
    quickSort(my,0 , my.size());
    for (size_t i = 0; i < my.size(); i++)
    {
        /* code */
        cout<< my.at(i) << " ";
    }


    return 0;
}