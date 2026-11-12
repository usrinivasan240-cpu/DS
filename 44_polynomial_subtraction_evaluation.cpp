// Q44 AIM: Subtract two polynomials and evaluate the result for a supplied x.
#include <iostream>
#include <map>
#include <functional>
#include <cmath>
using namespace std;

using Polynomial = map<int, double, greater<int>>;

Polynomial readPolynomial()
{
    Polynomial p;
    int terms, exponent;
    double coefficient;
    cout << "Number of terms: ";
    cin >> terms;
    cout << "Enter coefficient and exponent:" << endl;
    while (terms--)
    {
        cin >> coefficient >> exponent;
        p[exponent] += coefficient;
    }
    return p;
}

int main()
{
    cout << "Enter polynomial P:" << endl;
    Polynomial p = readPolynomial();
    cout << "Enter polynomial Q:" << endl;
    Polynomial q = readPolynomial();

    for (auto [exponent, coefficient] : q)
        p[exponent] -= coefficient;

    cout << "P - Q = ";
    bool first = true;
    for (auto [exponent, coefficient] : p)
    {
        if (coefficient == 0) continue;
        if (!first && coefficient > 0) cout << " + ";
        if (coefficient < 0) cout << " - ";
        cout << abs(coefficient);
        if (exponent > 0) cout << "x^" << exponent;
        first = false;
    }
    if (first) cout << "0";

    double x, result = 0;
    cout << "\nEnter x to evaluate P-Q: ";
    cin >> x;
    for (auto [exponent, coefficient] : p)
        result += coefficient * pow(x, exponent);
    cout << "Value at x = " << result << endl;
    return 0;
}