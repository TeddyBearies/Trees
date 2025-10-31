#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height; 

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

   
    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

  
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

       
        x->right = y;
        y->left = T2;

       
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x; 
    }

   
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

       
        y->left = x;
        x->right = T2;

       
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    
    Node* insert(Node* node, int value) {
        // normal BST insert
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node; 

        
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        
        int balance = getBalance(node);

       
        
        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

      
        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

       
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

       
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

   
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }


    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;

      
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == nullptr)
            return root;

        
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

      

       
        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

       
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

    
        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

      
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }
};


int main() {
    AVLTree tree;

  
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 25);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 5);

    cout << "Inorder traversal (sorted): ";
    tree.inOrder(tree.root);
    cout << endl;

    
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "After deleting 20, inorder traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    return 0;
}
