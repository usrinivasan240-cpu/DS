#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int key)
{
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

void inorder(Node *root)
{
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main()
{
    int values[] = {45, 15, 79, 90, 10, 55, 12, 20, 50};
    Node *root = nullptr;
    for (int value : values) root = insert(root, value);

    cout << "Inorder: ";
    inorder(root);

    Node *minimum = root, *maximum = root;
    while (minimum->left) minimum = minimum->left;
    while (maximum->right) maximum = maximum->right;
    cout << "\nMinimum: " << minimum->key;
    cout << "\nMaximum: " << maximum->key << endl;

    int key;
    cout << "Enter key to search: ";
    cin >> key;
    Node *current = root;
    while (current && current->key != key)
        current = key < current->key ? current->left : current->right;
    cout << (current ? "Key found" : "Key not found") << endl;
    return 0;
}