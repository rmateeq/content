#include <iostream>

enum Color {RED, BLACK};

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data): data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
    private:
        Node *root;

    protected:
        void rotateLeft(Node *&node) {
            Node *right_child = node->right;
            node->right = right_child->left;

            if (node->right != nullptr)
                node->right->parent = node;

            right_child->parent = node->parent;

            if (node->parent == nullptr)
                root = right_child;
            else if (node == node->parent->left)
                node->parent->left = right_child;
            else
                node->parent->right = right_child;

            right_child->left = node;
            node->parent = right_child;
        }

        void rotateRight(Node *&node) {
            Node *left_child = node->left;
            node->left = left_child->right;

            if (node->left != nullptr)
                node->left->parent = node;

            left_child->parent = node->parent;

            if (node->parent == nullptr)
                root = left_child;
            else if (node == node->parent->left)
                node->parent->left = left_child;
            else
                node->parent->right = left_child;

            left_child->right = node;
            node->parent = left_child;
        }

        void fixViolation(Node *&node) {
            Node *parent = nullptr;
            Node *grandparent = nullptr;

            while ((node != root) && (node->color != BLACK) && (node->parent->color == RED)) {
                parent = node->parent;
                grandparent = node->parent->parent;

                /* Case A:
                   Parent of node is left child of Grand-parent of node */
                if (parent == grandparent->left) {
                    Node *uncle = grandparent->right;

                    /* Case 1:
                       The uncle of node is also red
                       Only Recoloring required */
                    if (uncle != nullptr && uncle->color == RED) {
                        grandparent->color = RED;
                        parent->color = BLACK;
                        uncle->color = BLACK;
                        node = grandparent;
                    }
                    else {
                        /* Case 2:
                           node is right child of its parent
                           Left-rotation required */
                        if (node == parent->right) {
                            rotateLeft(parent);
                            node = parent;
                            parent = node->parent;
                        }

                        /* Case 3:
                           node is left child of its parent
                           Right-rotation required */
                        rotateRight(grandparent);
                        std::swap(parent->color, grandparent->color);
                        node = parent;
                    }
                }
                /* Case B:
                   Parent of node is right child of Grand-parent of node */
                else {
                    Node *uncle = grandparent->left;

                    /* Case 1:
                       The uncle of node is also red
                       Only Recoloring required */
                    if ((uncle != nullptr) && (uncle->color == RED)) {
                        grandparent->color = RED;
                        parent->color = BLACK;
                        uncle->color = BLACK;
                        node = grandparent;
                    }
                    else {
                        /* Case 2:
                           node is left child of its parent
                           Right-rotation required */
                        if (node == parent->left) {
                            rotateRight(parent);
                            node = parent;
                            parent = node->parent;
                        }

                        /* Case 3:
                           node is right child of its parent
                           Left-rotation required */
                        rotateLeft(grandparent);
                        std::swap(parent->color, grandparent->color);
                        node = parent;
                    }
                }
            }

            root->color = BLACK;
        }

    public:
        RBTree() : root(nullptr) {}

        void insert(const int &data) {
            Node *node = new Node(data);
            root = BSTInsert(root, node);
            fixViolation(node);
        }

        Node* BSTInsert(Node* root, Node* node) {
            if (root == nullptr)
                return node;

            if (node->data < root->data) {
                root->left = BSTInsert(root->left, node);
                root->left->parent = root;
            }
            else if (node->data > root->data) {
                root->right = BSTInsert(root->right, node);
                root->right->parent = root;
            }

            return root;
        }

        void inorder() {
            inorderHelper(root);
        }

        void inorderHelper(Node *root) {
            if (root == nullptr)
                return;
            inorderHelper(root->left);
            std::cout << root->data << " ";
            inorderHelper(root->right);
        }
};

int main() {
    RBTree tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);

    tree.inorder();  // Inorder traversal of created tree
    return 0;
}