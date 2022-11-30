#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> generateAllSuffixes(string text){

    vector<string>suffixes;


    for (int i = text.size()-1; i >= 0; i--)
    {   
        suffixes.push_back(text);
        char last = text[text.size()-1];
        text.erase(text.size()-1,1);
        text = last + text;
    }
    
    /*for (int i = 0; i < text.size(); i++)
    {
        cout << suffixes.at(i) << "\n";
    }*/
    return suffixes;
}

string getBWT(vector<string> suffixes){
    string BWT = "";
    for (size_t i = 0; i < suffixes.size(); i++)
    {   
        string s = suffixes.at(i);
        BWT += s.at(s.length()-1);
    }
    return BWT;
}
int main(){

    string text; // = "AGACATA$";
    cin >> text;
    vector<string> suffixes = generateAllSuffixes(text);
    sort(suffixes.begin(), suffixes.end());
    
    cout << getBWT(suffixes);
    


    return 0;
}