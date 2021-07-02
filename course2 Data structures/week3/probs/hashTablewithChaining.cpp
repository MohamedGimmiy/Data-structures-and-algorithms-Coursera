#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/**
 * @brief Hashing of integers with chaining
 * 
 */

struct Query
{
    string type, s;
    size_t ind;
};
/**
 * @brief Hash value
 * 
 * @param x is the value to be hashed
 * @param m is the cardinality (size of hash table)
 * @return int 
 */
long long Hash(long long x, long long m)
{

    long long p = 10000019;
    //int m = 1000; // cardinality (table size)
    long long a = 31;
    long long b = 50;

    // Using a,b for hashing 
    //long long res = (((a * x + b) % p) % m);

    // problem instructions
    long long res = ((((x % p)+p)%p) % m);
    return res;
}
/**
 * @brief converting our string to a hashed integer
 * 
 * @param s 
 * @param m 
 * @return int 
 */
long long hashString(string s, long long m)
{
    static const size_t x = 263;
    static const size_t prime = 1000000007;
    unsigned long long hash = 0;
    for (long long i = static_cast<long long>(s.size()) - 1; i >= 0; --i)
        hash = (hash * x + s[i]) % prime;
    return hash % m;
}
/**
 * @brief Calculate loadFactor to rehash our hashing table
 * 
 * @param A 
 * @return float 
 */
float calculateLoadFactor(const vector<vector<pair<int, int>>> &A)
{

    // calculate Number of keys stored in hash table
    int KeysNum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].size() != 0)
        {
            KeysNum++;
        }
    }
    return (KeysNum / A.size());
}

/**
 * @brief resize our hash table each time we insert 
 * a new element in our hash table
 * 
 * @param A 
 */
void rehash(vector<vector<pair<int, int>>> &A)
{
    float loadFactor = calculateLoadFactor(A);

    if (loadFactor > 0.9)
    {
        cout << "ppp\n";
        vector<vector<pair<int, int>>> ANew(2 * A.size());
        // choose random hash function with cardinality ANew.size()
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                int newVal = Hash(A[i][j].first, ANew.size());
                ANew[newVal].insert(ANew[newVal].begin(), make_pair(newVal, A[i][j].second));
            }
        }
        // insert each object in the new hash table
        A = ANew;
    }
}

/**
 * @brief Hash pair is a chainig implementation of hash table
 * it retrns true if we found that hash value else false
 * @param x 
 * @param A 
 * @return true 
 * @return false 
 */
bool hasKey(int x, const vector<vector<pair<int, int>>> &A)
{
    vector<pair<int, int>> L = A[Hash(x, A.size())];
    for (auto &&i : L)
    {
        if (i.first == x)
        {
            return true;
        }
    }
    return false;
}
bool hasKey(string mystring, const vector<vector<string>> &B)
{
    //TODO (DONE) calculate the hash string (x)
    long long x = hashString(mystring, B.size());

    vector<string> L = B[Hash(x, B.size())];
    for (auto &&i : L)
    {
        if (i == mystring)
        {
            return true;
        }
    }
    return false;
}
/**
 * @brief getting the mapped value of x
 * from the hash table
 * 
 * @param x 
 * @param A 
 * @return int 
 */
int get(int x, const vector<vector<pair<int, int>>> &A)
{
    if (!hasKey(x, A))
    {
        return -1;
    }
    vector<pair<int, int>> L = A[Hash(x, A.size())];
    for (auto &&i : L)
    {
        if (i.first == x)
        {
            return i.second;
        }
    }

    return -1;
}

/**
 * @brief Set an object or add it to our hash table
 * 
 * @param x 
 * @param y 
 * @param A 
 */
void set(int x, int y, vector<vector<pair<int, int>>> &A)
{

    vector<pair<int, int>> &L = A[Hash(x, A.size())];
    for (auto &&i : L)
    {
        if (i.first == x)
        {
            i.second = y;
            return;
        }
    }
    L.insert(L.begin(), make_pair(x, y));
    rehash(A);
}

// TODO (DONE) create a string hashing table
void set(string MYstring, vector<vector<string>> &B)
{
    // Hashing of string to integer
    long long x = hashString(MYstring, B.size());
    vector<string> &L = B[Hash(x, B.size())];
    for (auto &&i : L)
    {
        if (i == MYstring)
        {
            return;
        }
    }
    L.insert(L.begin(), MYstring);
    //rehash(A);
}
/**
 * @brief Remove element from our hash table
 * 
 * @param x 
 * @param A 
 */
void Remove(int x, vector<vector<pair<int, int>>> &A)
{

    if (!hasKey(x, A))
    {
        return;
    }

    vector<pair<int, int>> &L = A[Hash(x, A.size())];

    for (auto it = L.begin(); it != L.end(); ++it)
    {
        if ((*it).first == x)
        {
            L.erase(it);
            return;
        }
    }
}

void Remove(string mystring, vector<vector<string>> &B)
{

    if (!hasKey(mystring, B))
    {
        return;
    }

    //TODO (DONE) calculate the integer of our string
    int x = hashString(mystring, B.size());

    vector<string> &L = B[Hash(x, B.size())];

    for (auto it = L.begin(); it != L.end(); ++it)
    {
        if ((*it) == mystring)
        {
            L.erase(it);
            return;
        }
    }
}

// TODO (DONE) check function
void check(int x, const vector<vector<string>> &B)
{

    if (B.size() == 0)
    {
        cout << "\n";
        return;
    }
    for (size_t i = 0; i < B[x].size(); i++)
    {
        cout << B[x][i] << " ";
    }
    cout << "\n";
}

Query readQuery(int q, vector<vector<string>> &B)
{
    Query query;
    cin >> query.type;
    if (query.type != "check")
    {
        cin >> query.s;
    }
    else
    {
        cin >> query.ind;
    }
    return query;
}
int main()
{
    /*-----------------converting an integer to a string ------------------*/
    
    /*int hashTableSize = 1000;

    // Hashing of integers
    vector<vector<pair<int, int>>> HashTable(hashTableSize);

    set(4, 5, HashTable);
    cout << get(4, HashTable) << "\n";
    set(4, 15, HashTable);
    cout << get(4, HashTable) << "\n";
    Remove(4, HashTable);
    cout << get(4, HashTable) << "\n";*/

    /*------------------ solution ---------------------*/
    // Hashing table of strings
    int m, q;
    cin >> m;
    Query query;
    vector<vector<string>> HashTableStrings(m);
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        query = readQuery(q, HashTableStrings);
        if (query.type == "check")
        {
            check(query.ind, HashTableStrings);
        }
        else if (query.type == "find")
        {
            if (hasKey(query.s, HashTableStrings))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
        else if (query.type == "del")
        {
            Remove(query.s, HashTableStrings);
        }
        else if (query.type == "add")
        {
            set(query.s, HashTableStrings);
        }
    }

    return 0;
}