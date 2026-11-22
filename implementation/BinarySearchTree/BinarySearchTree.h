#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* _root;
    int _size;

    Node* insert_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert_recursive(node->left, value);
        }
        else if (node->data < value) {
            node->right = insert_recursive(node->right, value);
        }
        return node;
    }

    Node* remove_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = remove_recursive(node->left, value);
        }
        else if (node->data < value) {
            node->right = remove_recursive(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->data = temp->data;
            node->right = remove_recursive(node->right, temp->data);
        }
        return node;
    }

    Node* find_recursive(Node* node, const T& value) const {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            return find_recursive(node->left, value);
        }
        if (node->data < value) {
            return find_recursive(node->right, value);
        }
        return node;
    }

    void clear_recursive(Node* node) {
        if (node == nullptr) {
            return;
        }
        clear_recursive(node->left);
        clear_recursive(node->right);
        delete node;
    }

    int height_recursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        int left = height_recursive(node->left);
        int right = height_recursive(node->right);
        if (left > right) {
            return 1 + left;
        }
        return 1 + right;
    }

    Node* copy_recursive(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* newNode = new Node(node->data);
        newNode->left = copy_recursive(node->left);
        newNode->right = copy_recursive(node->right);
        return newNode;
    }

    void inorder_recursive(Node* node) const {
        if (node == nullptr) {
            return;
        }
        inorder_recursive(node->left);
        std::cout << node->data << " ";
        inorder_recursive(node->right);
    }

    void preorder_recursive(Node* node) const {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << " ";
        preorder_recursive(node->left);
        preorder_recursive(node->right);
    }

    void postorder_recursive(Node* node) const {
        if (node == nullptr) {
            return;
        }
        postorder_recursive(node->left);
        postorder_recursive(node->right);
        std::cout << node->data << " ";
    }

public:
    BinarySearchTree() : _root(nullptr), _size(0) {}

    ~BinarySearchTree() {
        clear();
    }

    BinarySearchTree(const BinarySearchTree& other)
        : _root(copy_recursive(other._root)), _size(other._size) {}

    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this == &other) {
            return *this;
        }
        Node* newRoot = copy_recursive(other._root);
        clear();
        _root = newRoot;
        _size = other._size;
        return *this;
    }

    void insert(const T& value) {
        if (find(value)) {
            return;
        }
        _root = insert_recursive(_root, value);
        _size++;
    }

    void remove(const T& value) {
        if (!find(value)) {
            return;
        }
        _root = remove_recursive(_root, value);
        _size--;
    }

    bool find(const T& value) const {
        return find_recursive(_root, value) != nullptr;
    }

    void inorder() const {
        inorder_recursive(_root);
        std::cout << std::endl;
    }

    void preorder() const {
        preorder_recursive(_root);
        std::cout << std::endl;
    }

    void postorder() const {
        postorder_recursive(_root);
        std::cout << std::endl;
    }

    int size() const {
        return _size;
    }

    int height() const {
        return height_recursive(_root);
    }

    void clear() {
        clear_recursive(_root);
        _root = nullptr;
        _size = 0;
    }

    bool is_empty() const {
        return _root == nullptr;
    }
};

#endif
