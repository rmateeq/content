#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
    private:
        TreeNode* root;

        TreeNode* insert(TreeNode* node, int value) {
            if (node == nullptr) {
                return new TreeNode(value);
            }
            if (value < node->value) {
                node->left = insert(node->left, value);
            } else if (value > node->value) {
                node->right = insert(node->right, value);
            }
            return node;
        }

        TreeNode* search(TreeNode* node, int value) {
            if (node == nullptr || node->value == value) {
                return node;
            }
            if (value < node->value) {
                return search(node->left, value);
            } else {
                return search(node->right, value);
            }
        }

        TreeNode* deleteNode(TreeNode* node, int value) {
            if (node == nullptr) return node;

            if (value < node->value) {
                node->left = deleteNode(node->left, value);
            } else if (value > node->value) {
                node->right = deleteNode(node->right, value);
            } else {
                if (node->left == nullptr) {
                    TreeNode* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr) {
                    TreeNode* temp = node->left;
                    delete node;
                    return temp;
                }

                TreeNode* temp = minValueNode(node->right);
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->value);
            }
            return node;
        }

        TreeNode* minValueNode(TreeNode* node) {
            TreeNode* current = node;
            while (current && current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

        void inOrder(TreeNode* node) {
            if (node != nullptr) {
                inOrder(node->left);
                std::cout << node->value << " ";
                inOrder(node->right);
            }
        }

    public:
        BST() : root(nullptr) {}

        void insert(int value) {
            root = insert(root, value);
        }

        void searchAndPrint(int value) {
            TreeNode* result = search(root, value);
            if (result == nullptr) {
                std::cout << "Value " << value << " not found in the BST." << std::endl;
            } else {
                std::cout << "Value " << value << " found in the BST." << std::endl;
            }
        }

        void deleteValue(int value) {
            root = deleteNode(root, value);
        }

        void displayInOrder() {
            inOrder(root);
            std::cout << std::endl;
        }
};

int main() {
    BST tree;
    tree.insert(15);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(12);
    tree.insert(17);
    tree.insert(25);

    tree.displayInOrder();  // Should display the numbers in sorted order

    tree.searchAndPrint(10);
    tree.deleteValue(10);
    tree.displayInOrder();  // 10 should be missing now

    return 0;
}
