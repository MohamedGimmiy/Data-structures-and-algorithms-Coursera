#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


//
const int APLHABETE_SIZE = 256;
vector<int> sortChars(string S){

    vector<int>order(S.length());
    vector<int>count(APLHABETE_SIZE,0);

    for (int i = 0; i < S.length(); i++)
    {
        count[S[i]]++;
    }

    for (int j = 1; j < APLHABETE_SIZE; j++)
    {
        count[j] = count[j] + count[j-1];
    }
    // THE greater index is for the least one of occurances
    for (int i = S.length()-1; i >= 0; i--)
    {
        char c = S[i];
        count[c] = count[c] - 1;
        // count of $ = 0
        order[count[c]] = i;
    }

    return order;
}

/**
 * @brief compute the classes of our suffixes orders
 * by depending on the different elements
 * 
 * @param s our string
 * @param order our sorted order of suffixes
 * @return vector<int> set of ordered classes
 */
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

/**
 * @brief we sort the first L=1 then we add 2*L to them and sort them
 * example a , b =>  aa , ab  we add them to the (left) of our string
 * so our order is always true
 * 
 * @param S our string
 * @param L double cyclic shifts
 * @param Class the class whic represent the number of occurances of strings
 * @return vector<int> the new sorted order of our suffixes
 */
vector<int> sortDoubled(string S, int L, vector<int>order, vector<int> Class){

    vector<int>count(S.length(),0);
    vector<int>newOrder(S.length());

    for (int i = 0; i < S.length(); i++)
    {
        count[Class[i]]++;
    }

    for (int j = 1; j < S.length(); j++)
    {
        count[j] = count[j] + count[j-1];
    }

    for (int i = S.length() - 1; i >= 0; i--)
    {
        // to go counter clockwise 2L (mod as we going through a circle)
        int start = (((order[i] - L) + S.length()) % S.length());
        int cl = Class[start];
        count[cl] = count[cl] - 1;
        newOrder[count[cl]] = start;
    }

    return newOrder;
}

/**
 * @brief updating classes after computing the new oder 
 * of our suffixes
 * 
 * @param L double cyclic shifts
 * @return vector<int> new classes
 */
vector<int> updateClasses(vector<int>newOrder, vector<int>Class, int L){
    //TODO
    int n = newOrder.size();
    vector<int>newClass(n);
    
    for (int i = 1; i < n; i++)
    {
        // computer positions of first half
        int cur = newOrder[i];
        int prev = newOrder[i - 1];
        // computer starting position of second half starts
        int mid = (cur + L);
        int midPrev = (prev + L) % n;
        // if there classes are different // assign new class
        if (Class[cur] != Class[prev] || Class[mid] != Class[midPrev])
        {
            newClass[cur] = newClass[prev] + 1;
        }
        else{
            newClass[cur] = newClass[prev];
        }
        
    }
        for (auto &&i : newClass)
    {
        cout << i << " ";
    }
    cout << "L: " << L << "\n";
    return newClass;
}

vector<int> BUildSUffixArray(string s){
    vector<int> order = sortChars(s);
    vector<int> Class = computeCharClasses(s, order);
    int L = 1;
    while (L <= s.length())
    {
        order = sortDoubled(s, L, order, Class);
        Class = updateClasses(order, Class, L);
        L *= 2;
    }
    return order;
}




// for non long strings as we stores suffixes
vector<long> SuffixArrayMapping(string S){
    
    vector<long>order(S.length()); // suffixes
    map<string, long> count;
    string sub;

    for(long i = S.length()-1; i >=0; i--){
        sub = S[i] + sub;
        count[sub] = i;
    }

    // storing all values of map in suffix array (map sorts strings ordinary)
    long j = 0;
    for (auto &&i : count)
    {
        order[j] = i.second;
        j++;
    }
    return order;
}


int main(){


    string text;
    cin >>text;

    auto v = BUildSUffixArray(text);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    
    return 0;
}