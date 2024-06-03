#include <iostream>
#include <algorithm>
#include <vector>
// Node structure for AVL Tree
int count = 0;
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Utility function to get the height of a node
int getHeight(Node *node)
{
    return (node == nullptr) ? 0 : node->height;
}

// Utility function to get the balance factor of a node
int getBalance(Node *node)
{
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Function to perform right rotation
Node *rightRotate(Node *y)
{
    count++;
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to perform left rotation
Node *leftRotate(Node *x)
{
    count++;
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to insert a key into the AVL tree
Node *insert(Node *root, int key)
{
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else // Duplicate keys are not allowed
        return root;

    // Update height of this ancestor node
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(root);

    // If the node becomes unbalanced, there are four cases

    // Left Left Case
    if (balance > 1 && key < root->left->key)
    {
        count++;
        return rightRotate(root);
    }
    // Right Right Case
    if (balance < -1 && key > root->right->key)
    {
        count++;
        return leftRotate(root);
    }
    // Left Right Case
    if (balance > 1 && key > root->left->key)
    {
        count++;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        count++;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // std::cout << count << std::endl;
    // count = 0;
    //  No rotation needed, return the unchanged node pointer
    return root;
}

// Function to perform inorder traversal
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

// Example usage
int main()
{
    while (1)
    {
        Node *root = nullptr;
        int x;
        std::cin >> x;
        if (x == -1144)
        {
            break;
        }
        for (int i = 1; i <= x; i++)
        {
            root = insert(root, i);
        }
        // v[x] = count;
        std::cout << count << std::endl;
        count = 0;
    }
    // root = insert(root, 10);
    // root = insert(root, 20);
    // root = insert(root, 30);
    // root = insert(root, 40);
    // root = insert(root, 50);
    // root = insert(root, 25);

    // std::cout << "Inorder traversal of the AVL tree: ";
    // inorder(root);
    // std::cout << std::endl;

    return 0;
}
