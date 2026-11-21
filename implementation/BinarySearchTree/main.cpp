#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>

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
    bst.insert(20);
    bst.insert(40);

    bst.remove(30);

    assert(bst.size() == 4);
    assert(!bst.find(30));
    assert(bst.find(20));
    assert(bst.find(40));

    std::cout << "test_remove passed" << std::endl;
}

void test_find() {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);

    assert(bst.find(10));
    assert(bst.find(20));
    assert(bst.find(5));
    assert(!bst.find(100));

    std::cout << "test_find passed" << std::endl;
}

void test_traversals() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    bst.inorder();
    bst.preorder();
    bst.postorder();

    std::cout << "test_traversals passed" << std::endl;
}

void test_size() {
    BinarySearchTree<int> bst;

    assert(bst.size() == 0);

    bst.insert(10);
    bst.insert(20);
    bst.insert(30);

    assert(bst.size() == 3);

    bst.remove(20);

    assert(bst.size() == 2);

    std::cout << "test_size passed" << std::endl;
}

void test_height() {
    BinarySearchTree<int> bst;

    assert(bst.height() == 0);

    bst.insert(50);
    assert(bst.height() == 1);

    bst.insert(30);
    bst.insert(70);
    assert(bst.height() == 2);

    bst.insert(20);
    assert(bst.height() == 3);

    std::cout << "test_height passed" << std::endl;
}

void test_clear() {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(30);

    bst.clear();

    assert(bst.size() == 0);
    assert(bst.is_empty());
    assert(bst.height() == 0);

    std::cout << "test_clear passed" << std::endl;
}

void test_is_empty() {
    BinarySearchTree<int> bst;

    assert(bst.is_empty());

    bst.insert(10);

    assert(!bst.is_empty());

    bst.clear();

    assert(bst.is_empty());

    std::cout << "test_is_empty passed" << std::endl;
}

void test_copy_constructor() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    BinarySearchTree<int> copy(bst);

    assert(copy.size() == 3);
    assert(copy.find(50));
    assert(copy.find(30));
    assert(copy.find(70));

    copy.insert(100);

    assert(!bst.find(100));

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment() {
    BinarySearchTree<int> bst1;

    bst1.insert(10);
    bst1.insert(20);
    bst1.insert(30);

    BinarySearchTree<int> bst2;

    bst2 = bst1;

    assert(bst2.size() == 3);
    assert(bst2.find(10));
    assert(bst2.find(20));
    assert(bst2.find(30));

    bst2.insert(40);

    assert(!bst1.find(40));

    std::cout << "test_assignment passed" << std::endl;
}

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;

    test_insert();
    test_remove();
    test_find();
    test_traversals();
    test_size();
    test_height();
    test_clear();
    test_is_empty();
    test_copy_constructor();
    test_assignment();

    std::cout << "All tests passed" << std::endl;

    return 0;
}
