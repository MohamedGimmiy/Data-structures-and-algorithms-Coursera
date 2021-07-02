#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * @brief find the length of the longest common sub sequence
 * given two sequences
 * 
 */
long LCS(long *ar1, long *ar2, int size1, int size2)
{

    long arraychar[size1 + 1][size2 + 1];

    for (int i = 0; i <= size1; i++)
    {
        for (int j = 0; j <= size2; j++)
        {

            if (i == 0 || j == 0)
                arraychar[i][j] = 0;
            else if (ar1[i-1] != ar2[j-1])
            {
                arraychar[i][j] = max(arraychar[i - 1][j], arraychar[i][j - 1]);
            }
            else
            {
                arraychar[i][j] = arraychar[i - 1][j - 1] + 1;
            }
        }
    }

    /*for (int i = 0; i < size1 + 1; i++)
    {
        for (int j = 0; j < size2 + 1; j++)
        {
            cout << "(" << i << "," << j << ")"
                 << " = " << arraychar[i][j] << "\n";
        }
    }*/

    return arraychar[size1][size2];
}

// TODO print the longest common sub sequenece string

string printLCS(int *arr[])
{
    return NULL;
}
int main()
{

    int size1, size2;
    long tmp;
    cin >> size1;
    long *ar1 = new long[size1];

    for (int i = 0; i < size1; i++)
    {
        cin >> tmp;
        ar1[i] = tmp;
    }

    cin >> size2;
    long *ar2 = new long[size2];

    for (int i = 0; i < size2; i++)
    {
        cin >> tmp;
        ar2[i] = tmp;
    }
    cout << LCS(ar1, ar2, size1, size2) << "\n";

    return 0;
}