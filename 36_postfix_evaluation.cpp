// Q36 AIM: Evaluate the specified postfix expression using a stack.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int integerPower(int base, int exponent)
{
    int result = 1;
    while (exponent-- > 0) result *= base;
    return result;
}

int main()
{
    string tokens[] = {"8", "2", "3", "^", "/", "2", "3", "*", "+", "5", "3", "*", "-"};
    stack<int> values;

    for (const string &token : tokens)
    {
        if (token.size() == 1 && string("+-*/^").find(token[0]) != string::npos)
        {
            int right = values.top(); values.pop();
            int left = values.top(); values.pop();

            switch (token[0])
            {
                case '+': values.push(left + right); break;
                case '-': values.push(left - right); break;
                case '*': values.push(left * right); break;
                case '/':
                    if (right == 0)
                    {
                        cout << "Division by zero" << endl;
                        return 1;
                    }
                    values.push(left / right);
                    break;
                case '^': values.push(integerPower(left, right)); break;
            }
        }
        else values.push(stoi(token));
    }

    cout << "Postfix result: " << values.top() << endl;
    return 0;
}