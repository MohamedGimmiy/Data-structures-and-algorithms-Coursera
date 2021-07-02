#include<iostream>

#include<vector>

using namespace std;

/**
 * @brief naive ploynomial multiplication algorithm O(n2)
 * 
 * @param a 
 * @param b 
 * @param highestDegree 
 * @return vector<int> 
 */
vector<int> multPoly(vector<int>&a, vector<int>&b, int highestDegree){

    vector<int> product((2*highestDegree)-1,0);

    for(int i=0;i<(2*highestDegree)-1;i++){
        for(int j=0;j<(2*highestDegree)-1;j++){
            product[i+j] = product[i+j] + a[i]*b[j];
        }
    }

    return product;
}

vector<int>multPolyFast(vector<int>&A, vector<int>&B,
 int highestDegree, int al, int bl){

    vector<int> Result((2*highestDegree-1),0);
    if(highestDegree==1){
        Result[0]= A.at(al)*B.at(bl);
    }

    //assign a range to some values
    Result.assign(0, highestDegree-2) = multPolyFast(A, 
    B, 
    highestDegree/2, 
    al, 
    bl);

    Result.assign(0, 2*highestDegree-2) = multPolyFast(
        A, 
        B,
        highestDegree/2,
        al+(highestDegree/2),
        bl+(highestDegree/2));

    int D0E1 = multPolyFast(
        A, 
        B,
        highestDegree/2,
        al,
        bl+(highestDegree/2));

    int D1E0 = multPolyFast(
        A, 
        B,
        highestDegree/2,
        al+(highestDegree/2),
        bl);

        Result.assign(highestDegree/2, highestDegree+ (highestDegree/2)-2) += D1E0+D0E1;

        return Result;

}

int main(){

    vector<int>a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    
    vector<int>b;
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);

    vector<int>c = multPoly(a,b,3);

    for (int i = 0; i < c.size(); i++)
    {
        /* code */
        cout<<c.at(i);
         if(i!=c.size()-1){
             cout << "x^"<< c.size()-i-1;
         }
        if(i != c.size()-1){
            cout<<" + ";
        }
    }
    cout<<"\n";

    return 0;
}