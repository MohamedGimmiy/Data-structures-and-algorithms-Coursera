#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#include<map>

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

/**
 * @brief inverting BWT to original text
 * using sort rounds of mers (memory intensive consumption)
 * 
 * @param suffixes 
 * @param BWT 
 * @return string 
 */
string InvBWTInROunds( string BWT){

    int mersNum = BWT.length() - 1;
    string Bwt = BWT;
    string firstColumn = Bwt;
    sort(firstColumn.begin(), firstColumn.end());
    
    string originalText = "";
    vector<string>mers;
    

            for (int k = 0; k < Bwt.length(); k++)
            {   
                string merPiece;
                merPiece.push_back(Bwt.at(k));
                merPiece.push_back(firstColumn[k]);
                mers.push_back(merPiece);
            }
            sort(mers.begin(), mers.end());

    for (int i = 0; i < mersNum; i++)
    {
            // Generate a mer but adding char of BWT to each column and sort them 
            // To get the first letter of the original text
            for (int k = 0; k < Bwt.length(); k++)
            {   
                mers[k].insert(mers[k].begin(), Bwt[k]);
            }
            sort(mers.begin(), mers.end());
    }
            originalText = mers[0];            

    originalText.erase(0,1);
    return originalText;
}

/**
 * @brief inverting BWT using maps FirstLast prob
 * 
 * @param BWT 
 * @return string 
 */
string FirstLastProb(string BWT){

    //TODO
    map<string,string> first;

    map<char, int> counting;
    int counter1 = 1;
    int Lletter = BWT.length() - 1;
    string firstColumn = BWT;
    sort(firstColumn.begin(), firstColumn.end());
    //1. generating 2 maps of letters
    for(int i = 0; i<BWT.size();i++){
        
        if(i > 0 && firstColumn[i] != firstColumn[i-1]){
            counter1 = 1;
        }

        string f;
        f += firstColumn[i]; f +=  to_string(counter1);
        counter1++;

        string l;
        l += BWT[i]; l +=to_string(++counting[BWT[i]]);

        // Assigns maps
        first[f] = l;
    }

    
    //2. Constructing the original text
    string originalText;

    string start = first["$1"];
    while (true)
    {
        if(start == "$1"){
            break;
        }
        originalText += start[0];
        string s = first[start];
        start = s;
    }
    
    reverse(originalText.begin(), originalText.end());
    originalText+= "$";
    return originalText;
}

int main(){

    /*string text = "panamabananas$";

    vector<string> suffixes = generateAllSuffixes(text);
    sort(suffixes.begin(), suffixes.end());
    
    string BWT = getBWT(suffixes);
    cout << BWT << "\n";

    string originalText = InvBWTInROunds(BWT);
    cout << originalText;*/

    string BWT;
    cin >> BWT;
    cout << FirstLastProb(BWT);
    
    return 0;
}