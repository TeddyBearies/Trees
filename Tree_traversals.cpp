 #include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};
class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    // Function to insert a node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // In-order traversal
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    // Pre-order traversal
    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    // Post-order traversal
    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }

        bool search(Node* node, int value) {
            if (node->data == value) {
                return true;
            } else if (value < node->data) {
                return search(node->left, value);
            } else {
                return search(node->right, value);
            }
        }

        // Function to find the minimum value node
        Node* findMin(Node* node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        // Function to find the maximum value node
        Node* findMax(Node* node) {
            while (node->right != nullptr) {
                node = node->right;
            }
            return node;
        }
 
  
        Node* deleteNode(Node* root, int value) {
            if (root == nullptr) {
                return root;
            }

            if (value < root->data) {
                root->left = deleteNode(root->left, value);
            } else if (value > root->data) {
                root->right = deleteNode(root->right, value);
            } else {
                if (root->left == nullptr) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }

            return root;
        }

};

// Driver code
int main() {
    Tree tree;

    // Insert nodes
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preOrderTraversal(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrderTraversal(tree.root);
    cout << endl;

    // Search for a node
    int searchValue = 40;
    cout << "Searching for " << searchValue << ": ";
    if (tree.search(tree.root, searchValue)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }

    // Find minimum and maximum node
    Node* minNode = tree.findMin(tree.root);
    Node* maxNode = tree.findMax(tree.root);
    cout << "Minimum value in the tree: " << minNode->data << endl;
    cout << "Maximum value in the tree: " << maxNode->data << endl;

    // Delete a node
    tree.root = tree.deleteNode(tree.root, 40);
    cout << "After deleting 40, In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    return 0;
}


};
