#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string word, reversed;
    cout << "Enter a word: ";
    cin >> word;

    stack<char> characters;
    for (char ch : word) characters.push(ch);

    while (!characters.empty())
    {
        reversed += characters.top();
        characters.pop();
    }

    cout << "Reversed word: " << reversed << endl;
    if (word == reversed) cout << "The word is a palindrome" << endl;
    else cout << "The word is not a palindrome" << endl;
    return 0;
}