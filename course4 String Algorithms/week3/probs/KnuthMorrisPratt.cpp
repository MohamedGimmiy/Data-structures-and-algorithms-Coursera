#include<iostream>
#include<vector>
using namespace std;


// O(n)
vector<int> computePrefix(string pattern){

    vector<int> s(pattern.length());

    s[0] = 0;    int border = 0; // length of current border
    // was pattern.length()-1
    for (size_t i = 1; i < pattern.length(); i++)
    {
        // if our symbol is not equal to current border
        // go to prev border till border = 0
        while (border >0 && pattern[i] != pattern[border])
        {
            border = s[border - 1];
        }
        // if current symbol = pattern border
        // increment our border
        // else border = 0
        if(pattern[i] == pattern[border]){
            border++;
        } else{
            border = 0;
        }
        // assign current prefix to current border
        s[i] = border;
        
    }
    
    return  s;
}

vector<int> KnuthMorrisPatternMatching(string T, string P){

    string S = P + "$" + T;
    vector<int> prefixAll = computePrefix(S);

    
    vector<int>result;
    for (size_t i = P.length()+1; i < S.length(); i++)
    {
        if(prefixAll[i] == P.length())
            result.push_back(i-(2*P.length()));
    }
    return result;

}
int main(){

    string pattern = "abra";
    string text = "abracadabra";
    auto x = KnuthMorrisPatternMatching(text, pattern);
    return 0;
}