#include <iostream>
#include <cassert>

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
            _size++;
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert_recursive(node->left, value);
        } else if (value > node->data) {
            node->right = insert_recursive(node->right, value);
        }
        return node;
    }

    Node* remove_recursive(Node* node, const T& value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = remove_recursive(node->left, value);
        } else if (value > node->data) {
            node->right = remove_recursive(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                _size--;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                _size--;
                return temp;
            }
            Node* temp = node->right;
            while (temp->left != nullptr) temp = temp->left;
            node->data = temp->data;
            node->right = remove_recursive(node->right, temp->data);
        }
        return node;
    }

    bool find_recursive(const Node* node, const T& value) const {
        if (node == nullptr) return false;
        if (value == node->data) return true;
        if (value < node->data) return find_recursive(node->left, value);
        return find_recursive(node->right, value);
    }

    void clear_recursive(Node* node) {
        if (node == nullptr) return;
        clear_recursive(node->left);
        clear_recursive(node->right);
        delete node;
    }

    int height_recursive(const Node* node) const {
        if (node == nullptr) return 0;
        int leftH = height_recursive(node->left);
        int rightH = height_recursive(node->right);
        return 1 + (leftH > rightH ? leftH : rightH);
    }

    Node* copy_recursive(const Node* node) const {
        if (node == nullptr) return nullptr;
        Node* newNode = new Node(node->data);
        newNode->left = copy_recursive(node->left);
        newNode->right = copy_recursive(node->right);
        return newNode;
    }

    void inorder_recursive(const Node* node) const {
        if (node == nullptr) return;
        inorder_recursive(node->left);
        std::cout << node->data << " ";
        inorder_recursive(node->right);
    }

    void preorder_recursive(const Node* node) const {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preorder_recursive(node->left);
        preorder_recursive(node->right);
    }

    void postorder_recursive(const Node* node) const {
        if (node == nullptr) return;
        postorder_recursive(node->left);
        postorder_recursive(node->right);
        std::cout << node->data << " ";
    }

public:
    BinarySearchTree() : _root(nullptr), _size(0) {}

    ~BinarySearchTree() {
        clear();
    }

    BinarySearchTree(const BinarySearchTree& other) {
        _root = copy_recursive(other._root);
        _size = other._size;
    }

    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this != &other) {
            clear();
            _root = copy_recursive(other._root);
            _size = other._size;
        }
        return *this;
    }

    void insert(const T& value) {
        _root = insert_recursive(_root, value);
    }

    void remove(const T& value) {
        _root = remove_recursive(_root, value);
    }

    bool find(const T& value) const {
        return find_recursive(_root, value);
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

void test_insert() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    assert(bst.size() == 1);
    assert(bst.find(50));
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    assert(bst.size() == 5);
    assert(bst.find(30));
    assert(bst.find(70));

    std::cout << "test_insert passed" << std::endl;
}

void test_remove() {
    BinarySearchTree<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    bst.remove(30);
    assert(bst.size() == 2);
    assert(!bst.find(30));
    assert(bst.find(50));

    bst.remove(50);
    assert(bst.size() == 1);
    assert(!bst.find(50));
    assert(bst.find(70));

    std::cout << "test_remove passed" << std::endl;
}

void test_find() {
    BinarySearchTree<int> bst;

    assert(bst.find(10) == false);

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    assert(bst.find(10) == true);
    assert(bst.find(5) == true);
    assert(bst.find(15) == true);
    assert(bst.find(3) == true);
    assert(bst.find(7) == true);

    assert(bst.find(100) == false);
    assert(bst.find(0) == false);
    assert(bst.find(8) == false);

    std::cout << "test_find passed" << std::endl;
}

void test_copy_and_clear() {
    BinarySearchTree<int> bst1;
    bst1.insert(10);
    bst1.insert(5);

    BinarySearchTree<int> bst2 = bst1;
    assert(bst2.size() == 2);
    assert(bst2.find(10));

    bst2.remove(10);
    assert(bst1.size() == 2);
    assert(bst1.find(10));

    bst1.clear();
    assert(bst1.is_empty());
    assert(bst1.size() == 0);
    assert(bst1.height() == 0);

    std::cout << "test_copy_and_clear passed" << std::endl;
}

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;
    test_insert();
    test_remove();
    test_find();
    test_copy_and_clear();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
