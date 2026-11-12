#include <iostream>
#include <map>
#include <functional>
using namespace std;

using Polynomial = map<int, long long, greater<int>>;

Polynomial readPolynomial()
{
    Polynomial p;
    int terms, coefficient, exponent;
    cout << "Number of terms: ";
    cin >> terms;
    cout << "Enter coefficient and exponent for each term:" << endl;
    while (terms--)
    {
        cin >> coefficient >> exponent;
        p[exponent] += coefficient;
    }
    return p;
}

Polynomial add(const Polynomial &a, const Polynomial &b)
{
    Polynomial result = a;
    for (auto [exponent, coefficient] : b)
        result[exponent] += coefficient;
    return result;
}

Polynomial multiply(const Polynomial &a, const Polynomial &b)
{
    Polynomial result;
    for (auto [e1, c1] : a)
        for (auto [e2, c2] : b)
            result[e1 + e2] += c1 * c2;
    return result;
}

void display(const Polynomial &p)
{
    bool first = true;
    for (auto [exponent, coefficient] : p)
    {
        if (coefficient == 0) continue;
        if (!first && coefficient > 0) cout << " + ";
        if (coefficient < 0) cout << " - ";
        cout << (coefficient < 0 ? -coefficient : coefficient);
        if (exponent > 0) cout << "x^" << exponent;
        first = false;
    }
    if (first) cout << "0";
    cout << endl;
}

int main()
{
    cout << "First polynomial" << endl;
    Polynomial p = readPolynomial();
    cout << "Second polynomial" << endl;
    Polynomial q = readPolynomial();

    cout << "Sum: ";
    display(add(p, q));
    cout << "Product: ";
    display(multiply(p, q));
    return 0;
}