#include<iostream>
#include<vector>

long long MaxPairwiseProduct(const std::vector<int>& numbers){

    long long result = 0;
    for(int i=0; i< numbers.size();++i){
        for(int j=i+1;j<numbers.size();++j){
            if(numbers[i]*numbers[j] > result){
                result = ((long long)numbers[i])* (long long)numbers[j];
            }
        }
    }

return result;
}

long long MaxPairwiseProductFast(const std::vector<long long>& numbers){

    int max_index1 = -1;
    for(int i=0; i<numbers.size(); ++i){
        if(((max_index1 == -1) || (numbers[i]> numbers[max_index1]))){
            max_index1 = i;
        }
    }
    
    int max_index2 = -1;
    for(int j=0; j<numbers.size(); ++j){
        if(j != max_index1 &&
            ((max_index2 == -1) || (numbers[j]> numbers[max_index2]))){
            max_index2 = j;
        }
    }
    // std::cout<< max_index1 << " " << max_index2 <<"\n";
    return ((long long)(numbers[max_index1])) * (long long)numbers[max_index2];
}
int main(){



    //std::cout<<MaxPairwiseProduct(myvector)<<std::endl;
    // std::vector<int>myvector(10000,0);
    // std::cout<<MaxPairwiseProduct(myvector)<<std::endl;

    // while (true)
    // {
    //     int n = rand() % 10 + 2;
    //     std::cout<< n << std::endl;
    //     std::vector<int>a;
    //     for(int i=0;i<n; ++i){
    //         a.push_back(rand() % 1000);
    //     }
    //     for(int i=0;i<n;++i){
    //         std::cout<< a.at(i)<< " ";
    //     }
    //     std::cout << "\n";
    //     long long res1 = MaxPairwiseProduct(a);
    //     long long res2 = MaxPairwiseProductFast(a);
    //     if(res1 != res2){
    //         std::cout << "Wrong answer: "<< res1 << " "<< res2 << "\n";
    //         break;
    //     } else{
    //         std::cout << "Ok\n";
    //     }
    // }

    int n;
    std::cin>>n;
    std::vector<long long>myvector(n);
    for(int i=0;i<n;++i){
        std::cin>>myvector.at(i);
    }
    std::cout<< MaxPairwiseProductFast(myvector) ;
    //<< " " << MaxPairwiseProduct(myvector)<<"\n";
    
    return 0;
}