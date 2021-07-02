#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}



void process_queries(const vector<Query>& queries) {
    
    vector<string>v(10000000,"");
    // Keep list of all existing (i.e. not deleted yet) contacts.
    for (size_t i = 0; i < queries.size(); i++)
    {
        if(queries[i].type == "add"){
            v[queries[i].number]= queries[i].name;
        } else if(queries[i].type == "find"){
            if(v[queries[i].number] != ""){
                std::cout << v[queries[i].number] << "\n";
            }else{
                std::cout << "not found" << "\n";
            }
        }
        else if(queries[i].type == "del"){
                v[queries[i].number] = "";
        }
    }
    
}

int main() {
    process_queries(read_queries());
    return 0;
}
