// Q46 AIM: Find BST height and leaf count, then display its mirror.
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int value)
{
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

int height(Node *root)
{
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int countLeaves(Node *root)
{
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void mirror(Node *root)
{
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

void inorder(Node *root)
{
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    int n, value;
    cout << "Number of keys: ";
    cin >> n;
    cout << "Enter keys: ";
    while (n--)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Height (in nodes): " << height(root) << endl;
    cout << "Leaf nodes: " << countLeaves(root) << endl;
    cout << "Original inorder: ";
    inorder(root);

    mirror(root);
    cout << "\nMirror inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}