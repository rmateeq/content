#include<iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int value; // The value or key of the node
    TreeNode *left; // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Constructor to initialize the node with a value and null child pointers
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode *&root, int value) {
    // create a new node anyway
    TreeNode *newNode = new TreeNode(value);
    // insert it as root if root does not exist
    if (root == nullptr) {
        root = newNode;
        return;
    }
    // create a queue and push the root node on queue
    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        // pop a node from fron of queue
        TreeNode *current = queue.front();
        queue.pop();
        // if left of node is null, insert new node there and return
        if (current->left == nullptr) {
            current->left = newNode;
            return;
        }
        // if left is not null, put it on queue
        else {
            queue.push(current->left);
        }
        // if right of node is null, insert new node there and return
        if (current->right == nullptr) {
            current->right = newNode;
            return;
        } 
        // if right is not null, put it on queue
        else {
            queue.push(current->right);
        }
    }
}

// In-Order Traversal: Left, Root, Right
void inOrder(TreeNode *node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
}

// Pre-Order Traversal: Root, Left, Right
void preOrder(TreeNode *node) {
    if (node != nullptr) {
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Post-Order Traversal: Left, Right, Root
void postOrder(TreeNode *node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
}

void levelOrder(TreeNode* root) {
    if (root == nullptr) return;
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();
        std::cout << current->value << " ";
        if (current->left != nullptr) queue.push(current->left);
        if (current->right != nullptr) queue.push(current->right);
    }
}


int main() {
    TreeNode *root = nullptr; // Start with an empty binary tree

    // Insert nodes into the binary tree
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    // Perform different tree traversals
    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << endl;

    cout << "Level-Order Traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}