#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    // In-order Traversal (Left, Root, Right)
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    // Pre-order Traversal (Root, Left, Right)
    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    // Post-order Traversal (Left, Right, Root)
    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    Tree tree;
    Node* root = nullptr;

    // Insert nodes
    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    cout << "In-order traversal: ";
    tree.inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrderTraversal(root);
    cout << endl;

    return 0;
}
