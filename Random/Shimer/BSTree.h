template <typename T>
class BinarySearchTree {
public:

    BinarySearchTree(std::vector<string> &data) : root(nullptr) {
        for (string value : data) {
            insert(value);
        }
    }

    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroy(root);
    }

    void insert(const T& data) {
        root = insert(data, root);
    }

    void remove(const T& data) {
        root = remove(data, root);
    }

    bool search(const T& data) {
        return search(data, root);
    }

    void print() {
        inorderTraversal(root);
    }

private:
struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;


    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    Node* insert(const T& data, Node* node) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(data, node->left);
        } else if (data > node->data) {
            node->right = insert(data, node->right);
        }
        return node;
    }

    Node* remove(const T& data, Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = remove(data, node->left);
        } else if (data > node->data) {
            node->right = remove(data, node->right);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = remove(minRight->data, node->right);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool search(const T& data, Node* node) {
        if (node == nullptr) {
            return false;
        }
        if (data == node->data) {
            return true;
        } else if (data < node->data) {
            return search(data, node->left);
        } else {
            return search(data, node->right);
        }
    }

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
};
