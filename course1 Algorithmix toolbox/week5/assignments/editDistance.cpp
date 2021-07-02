#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int EditDist(string s1, string s2)
{

    int dp[s1.length() + 1][s2.length() + 1];
    
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {

            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[s1.length()][s2.length()];
}
int main()
{

    string s1;
    string s2;

    cin >> s1 >> s2;
    cout << EditDist(s1, s2);

    return 0;
}