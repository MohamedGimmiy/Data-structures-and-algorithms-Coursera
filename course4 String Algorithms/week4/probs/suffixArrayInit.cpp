#include<iostream>
#include<vector>
#include<string>
using namespace std;

// to be revised
const int APLHABETE_SIZE = 26;
vector<int> SuffixArrayMapping(string S){

    vector<int>order(S.length());
    vector<int>count(APLHABETE_SIZE,0);

    for (size_t i = 0; i < S.length()-1; i++)
    {
        count[S[i]-'a']++;
    }

    for (size_t j = 1; j < APLHABETE_SIZE-1; j++)
    {
        count[j] = count[j] + count[j-1];
    }

    for (int i = S.length()-1; i > 0; i--)
    {
        char c = S[i];
        count[c - 'a'] = count[c - 'a'] - 1;
        order[count[c - 'a'] + 1] = i;
    }
    
    return order;
    
}

vector<int> computeCharClasses(string s, vector<int> order){

    vector<int>Class(s.length());
    Class[order[0]] = 0;

    for (int i = 1; i < s.length(); i++)
    {   // compare if char is different from the prev one 
        //so we add a new class to it
        if(s[order[i]] != s[order[i-1]]){
            Class[order[i]] = Class[order[i - 1]] + 1;
        }
        else {
            // if cahr is equal to prev one so we set to the same class
            Class[order[i]] = Class[order[i - 1]];
        }
    }
    return Class;
}


int main(){


    string text = "ababaa$";
    auto sr = SuffixArrayMapping(text);
    for (auto &&i : sr)
    {
        cout << i << " ";
    }
    cout << "\n";
    auto cl = computeCharClasses(text, sr);

    for (auto &&j : cl)
    {
        cout << j << " ";
    }
    
    return 0;
}