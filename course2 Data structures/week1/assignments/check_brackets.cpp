#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket
{
    Bracket(char type, int position) : type(type),
                                       position(position)
    {
    }

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    getline(std::cin, text);

    std::stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket, write your code here
            Bracket b(next, position + 1);
            b.type = next;
            opening_brackets_stack.push(b);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty())
            {
                cout << position + 1 << "\n";
                return 0;
            }

            Bracket b = opening_brackets_stack.top();
            if (b.Matchc(next))
            {
                opening_brackets_stack.pop();
            }
            else
            {
                cout << position + 1;
                return 0;
            }
        }
    }
    if (!opening_brackets_stack.empty()){
        cout << opening_brackets_stack.top().position;
        opening_brackets_stack.pop();
    }
    else
    {
        cout << "Success";
    }
    // Printing answer, write your code here

    return 0;
}
