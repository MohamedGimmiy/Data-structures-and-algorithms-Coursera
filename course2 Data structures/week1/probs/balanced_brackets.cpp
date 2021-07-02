#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isBalanced(string str){
    stack<char>Stack;
    for (auto &&ch : str)
    {
        if(ch == '(' || ch == '['){
            Stack.push(ch);
        } else{
            if(Stack.empty())
                return false;

            char top = Stack.top();
            Stack.pop();
            if((top == '[' && ch != ']') || (top == '(' && ch != ')')){
                return false;
            }

        }
    }
    
    return Stack.empty();
}
int main(){


    if(isBalanced("[(]")){
        cout << "Yes";
    }
    cout << "No";





    return 0;
}