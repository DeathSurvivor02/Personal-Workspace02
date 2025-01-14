#ifndef REDBLACKTREETEST_H
#define REDBLACKTREETEST_H

#include <iostream>
#include <queue>

template <typename T>
class RedBlackTree {
public:
    // Node struct to store each element in the tree
    struct Node {
        T data;
        Node* parent;
        Node* left;
        Node* right;
        bool isRed;

        // Constructor for Node
        Node(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr), isRed(true) {}
    };

    // Constructor for RedBlackTree
    RedBlackTree() : m_root(nullptr) {}

    // Destructor for RedBlackTree
    ~RedBlackTree() {
        destroy(m_root);
    }

    // Insert a new element into the tree
    void insert(T data) {
        Node* node = new Node(data);
        if (m_root == nullptr) {
            m_root = node;
            node->isRed = false;
        } else {
            insert(m_root, node);
        }
    }

    // Print the contents of the tree in level-order
    void print() {
        if (m_root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        queue<Node*> q;
        q.push(m_root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->data << (node->isRed ? "(R) " : "(B) ");
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        cout << endl;
    }

    private:
        Node* m_root;

        // Recursive helper function to insert a new node into the tree
        void insert(Node* root, Node* node) {
            if (node->data < root->data) {
                if (root->left == nullptr) {
                    root->left = node;
                    node->parent = root;
                    fixup(node);
                } else {
                    insert(root->left, node);
                }
            } else {
                if (root->right == nullptr) {
                    root->right = node;
                    node->parent = root;
                    fixup(node);
                } else {
                    insert(root->right, node);
                }
            }
        }

        // Helper function to fix any violations in the tree after inserting a new node
        void fixup(Node* node) {
            while (node->parent != nullptr && node->parent->isRed) {
                if (node->parent == node->parent->parent->left) {
                    Node* uncle = node->parent->parent->right;
                    if (uncle != nullptr && uncle->isRed) {
                        node->parent->isRed = false;
                        uncle->isRed = false;
                        node->parent->parent->isRed = true;
                        node = node->parent->parent;
                    } else {
                        if (node == node->parent->right) {
                            node = node->parent;
                            rotateLeft(node);
                        }
                        node->parent->isRed = false;
                        node->parent->parent->isRed = true;
                        rotateRight(node->parent->parent);
                    }
                } else {
                    Node* uncle = node->parent->parent->left;
                    if (uncle != nullptr && uncle->isRed) {
                        node->parent->isRed = false;
                        uncle->isRed = false;
                        node->parent->parent->isRed = true;
                        node = node->parent->parent;
                    } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rotateRight(node);
                    }
                    node->parent->isRed = false;
                    node->parent->parent->isRed = true;
                    rotateLeft(node->parent->parent);
                }
            }
        }
        m_root->isRed = false;
    }

    // Helper function to rotate a subtree to the left
    void rotateLeft(Node* node) {
        Node* pivot = node->right;
        node->right = pivot->left;
        if (pivot->left != nullptr) {
            pivot->left->parent = node;
        }
        pivot->parent = node->parent;
        if (node->parent == nullptr) {
            m_root = pivot;
        } else if (node == node->parent->left) {
            node->parent->left = pivot;
        } else {
            node->parent->right = pivot;
        }
        pivot->left = node;
        node->parent = pivot;
    }

    // Helper function to rotate a subtree to the right
    void rotateRight(Node* node) {
        Node* pivot = node->left;
        node->left = pivot->right;
        if (pivot->right != nullptr) {
            pivot->right->parent = node;
        }
        pivot->parent = node->parent;
        if (node->parent == nullptr) {
            m_root = pivot;
        } else if (node == node->parent->right) {
            node->parent->right = pivot;
        } else {
            node->parent->left = pivot;
        }
        pivot->right = node;
        node->parent = pivot;
    }

    // Recursive helper function to destroy the tree
    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};

#endif