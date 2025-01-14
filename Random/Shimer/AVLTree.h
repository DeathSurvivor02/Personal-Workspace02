#ifndef AVLTREE_
#define AVLTREE_

#include <string>
#include <queue>

template <typename T>
class AVLTree {
public:
    // Constructor
    AVLTree() : root(nullptr) {

    }

    // Destructor
    ~AVLTree() {
        destroy(root);
    }

    // Insert a new element into the tree
    void insert(const T& data) {
        root = insert(data, root);
    }

private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;
        
        Node(const T& data) : data(data), left(nullptr), right(nullptr), height(0) {}
    };
    
    Node* root;
    
    int height(Node* node) const {
        if (node == nullptr) {
            return -1;
        } else {
            return node->height;
        }
    }
    
     // Helper function to perform a left rotation   
    Node* rotateLeft(Node* node) {
        Node* pivot = node->right;
        node->right = pivot->left;
        pivot->left = node;
        node->height = 1 + std::max(height(node->left), height(node->right));
        pivot->height = 1 + std::max(height(pivot->left), height(pivot->right));
        return pivot;
    }
    // Helper function to perform a right rotation
    Node* rotateRight(Node* node) {
        Node* pivot = node->left;
        node->left = pivot->right;
        pivot->right = node;
        node->height = 1 + std::max(height(node->left), height(node->right));
        pivot->height = 1 + std::max(height(pivot->left), height(pivot->right));
        return pivot;
    }
    
    int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}
    
  Node* insert(const T& data, Node* node) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(data, node->left);
        } else if (data > node->data) {
            node->right = insert(data, node->right);
        } else {
            // data already exists in the tree
            return node;
        }

    
        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && data < node->left->data) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && data > node->right->data) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};
#endif