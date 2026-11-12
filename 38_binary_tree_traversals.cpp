#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inorder(Node *root)
{
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // Enter root value, then left and right child values for each queued node.
    // Use -1 to represent a missing child.
    int value;
    cout << "Enter root value (-1 for empty tree): ";
    cin >> value;
    if (value == -1) return 0;

    Node *root = new Node(value);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        int leftValue, rightValue;
        cout << "Enter left and right child of " << current->data << ": ";
        cin >> leftValue >> rightValue;

        if (leftValue != -1)
        {
            current->left = new Node(leftValue);
            q.push(current->left);
        }
        if (rightValue != -1)
        {
            current->right = new Node(rightValue);
            q.push(current->right);
        }
    }

    cout << "Inorder: "; inorder(root);
    cout << "\nPreorder: "; preorder(root);
    cout << "\nPostorder: "; postorder(root);

    cout << "\nLevel order: ";
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front(); q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
    return 0;
}