#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief print positions of string matching
 * 
 * @param r 
 */
void printResults(vector<int> r)
{
    for (size_t i = 0; i < r.size(); i++)
    {
        /* code */
        cout << r[i] << " ";
    }
    cout << "\n";
}

/**
 * @brief calculating positions of pattern matching of a string
 * 
 * @param text 
 * @param pattern 
 * @param d 
 * @return vector<int> 
 */
vector<int> CalcStringMismatches(string text, string pattern, int d)
{
    int misMatchesNum = 0;
    bool valid = true;
    vector<int> positions;

    for (int i = 0; i <= (text.length() - pattern.length()); i++)
    {
        for (int j = 0; j != pattern.length(); j++)
        {   // There is a mismatch
            if (text[i+j] != pattern[j])
            {
                misMatchesNum++;
                if (misMatchesNum > d)
                {
                    valid = false;
                    break;
                }
            }
        }
        if (valid)
        {
            positions.push_back(i);
        }
        valid = true;
        misMatchesNum = 0;
    }

    printResults(positions);
    return positions;
}

int main()
{

    string text = "abbadac";
    string pattern = "bb";
    int d = 0;
    CalcStringMismatches(text, pattern, d);

    return 0;
}