#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;
    Node(int value) : key(value), height(1), left(nullptr), right(nullptr) {}
};

int height(Node *node) { return node ? node->height : 0; }
int balance(Node *node) { return node ? height(node->left) - height(node->right) : 0; }

void update(Node *node)
{
    node->height = 1 + max(height(node->left), height(node->right));
}

Node *rotateRight(Node *y)
{
    Node *x = y->left, *t = x->right;
    x->right = y;
    y->left = t;
    update(y);
    update(x);
    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right, *t = y->left;
    y->left = x;
    x->right = t;
    update(x);
    update(y);
    return y;
}

Node *rebalance(Node *node)
{
    update(node);
    int bf = balance(node);
    if (bf > 1)
    {
        if (balance(node->left) < 0) node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1)
    {
        if (balance(node->right) > 0) node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

Node *insert(Node *root, int key)
{
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root;
    return rebalance(root);
}

Node *minimumNode(Node *root)
{
    while (root->left) root = root->left;
    return root;
}

Node *removeKey(Node *root, int key)
{
    if (!root) return nullptr;
    if (key < root->key) root->left = removeKey(root->left, key);
    else if (key > root->key) root->right = removeKey(root->right, key);
    else
    {
        if (!root->left || !root->right)
        {
            Node *child = root->left ? root->left : root->right;
            delete root;
            return child;
        }
        Node *successor = minimumNode(root->right);
        root->key = successor->key;
        root->right = removeKey(root->right, successor->key);
    }
    return rebalance(root);
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
    Node *root = nullptr;
    int choice, key;
    do
    {
        cout << "1.Insert 2.Delete 3.Display inorder 0.Exit: ";
        cin >> choice;
        if (choice == 1) cin >> key, root = insert(root, key);
        else if (choice == 2) cin >> key, root = removeKey(root, key);
        else if (choice == 3) inorder(root), cout << endl;
    } while (choice != 0);
    return 0;
}