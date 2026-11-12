#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOpening(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}

bool matches(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main()
{
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    stack<char> brackets;
    bool balanced = true;

    for (char ch : expression)
    {
        if (isOpening(ch))
            brackets.push(ch);
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (brackets.empty() || !matches(brackets.top(), ch))
            {
                balanced = false;
                break;
            }
            brackets.pop();
        }
    }

    if (!brackets.empty()) balanced = false;
    cout << (balanced ? "Balanced brackets" : "Unbalanced brackets") << endl;
    return 0;
}