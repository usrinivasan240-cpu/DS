#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;
    Node(int value) : key(value), height(1), left(nullptr), right(nullptr) {}
};

int height(Node *node) { return node ? node->height : 0; }
int balanceFactor(Node *node) { return node ? height(node->left) - height(node->right) : 0; }

void updateHeight(Node *node)
{
    node->height = 1 + max(height(node->left), height(node->right));
}

Node *rotateRight(Node *root)
{
    Node *newRoot = root->left;
    Node *subtree = newRoot->right;
    newRoot->right = root;
    root->left = subtree;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node *rotateLeft(Node *root)
{
    Node *newRoot = root->right;
    Node *subtree = newRoot->left;
    newRoot->left = root;
    root->right = subtree;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node *insert(Node *root, int key)
{
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root;

    updateHeight(root);
    int bf = balanceFactor(root);

    if (bf > 1 && key < root->left->key) return rotateRight(root);
    if (bf < -1 && key > root->right->key) return rotateLeft(root);
    if (bf > 1)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
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
    Node *root = nullptr;
    int keys[] = {14, 17, 11, 7, 53, 4, 13};
    for (int key : keys) root = insert(root, key);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nNode : Balance factor" << endl;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->key << " : " << balanceFactor(current) << endl;
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return 0;
}