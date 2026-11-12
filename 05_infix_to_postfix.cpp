// Q5 AIM: Convert the four specified infix expressions to postfix using a stack.
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string convertToPostfix(const string &infix)
{
    stack<char> operators;
    string postfix;

    for (char ch : infix)
    {
        if (isspace(static_cast<unsigned char>(ch))) continue;
        if (isalnum(static_cast<unsigned char>(ch)))
            postfix += ch;
        else if (ch == '(')
            operators.push(ch);
        else if (ch == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        }
        else
        {
            while (!operators.empty() && operators.top() != '(' &&
                   (precedence(operators.top()) > precedence(ch) ||
                   (precedence(operators.top()) == precedence(ch) && ch != '^')))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main()
{
    string expressions[] = {
        "A*(B+C)/D",
        "A+B*C-D",
        "(A-B)*(C+D)/E",
        "A^B^C"
    };

    for (const string &expression : expressions)
        cout << expression << " -> " << convertToPostfix(expression) << endl;
    return 0;
}
