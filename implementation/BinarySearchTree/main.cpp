#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>
#include <sstream>

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
    assert(bst.find(40));

    bst.remove(50);

    assert(bst.size() == 3);
    assert(!bst.find(50));

    std::cout << "test_remove passed" << std::endl;
}

void test_find() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    assert(bst.find(50));
    assert(bst.find(30));
    assert(bst.find(70));
    assert(!bst.find(100));

    std::cout << "test_find passed" << std::endl;
}

void test_inorder() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    bst.inorder();

    std::cout.rdbuf(old);

    assert(output.str() == "20 30 40 50 70 ");

    std::cout << "test_inorder passed" << std::endl;
}

void test_preorder() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    bst.preorder();

    std::cout.rdbuf(old);

    assert(output.str() == "50 30 20 40 70 ");

    std::cout << "test_preorder passed" << std::endl;
}

void test_postorder() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    bst.postorder();

    std::cout.rdbuf(old);

    assert(output.str() == "20 40 30 70 50 ");

    std::cout << "test_postorder passed" << std::endl;
}

void test_size() {
    BinarySearchTree<int> bst;

    assert(bst.size() == 0);

    bst.insert(50);
    assert(bst.size() == 1);

    bst.insert(30);
    bst.insert(70);
    assert(bst.size() == 3);

    bst.remove(30);
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

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    bst.clear();

    assert(bst.size() == 0);
    assert(bst.is_empty());
    assert(!bst.find(50));

    std::cout << "test_clear passed" << std::endl;
}

void test_is_empty() {
    BinarySearchTree<int> bst;

    assert(bst.is_empty());

    bst.insert(50);

    assert(!bst.is_empty());

    bst.remove(50);

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

    copy.remove(30);

    assert(!copy.find(30));
    assert(bst.find(30));
    assert(bst.size() == 3);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    BinarySearchTree<int> bst1;

    bst1.insert(50);
    bst1.insert(30);
    bst1.insert(70);

    BinarySearchTree<int> bst2;

    bst2 = bst1;

    assert(bst2.size() == 3);
    assert(bst2.find(50));
    assert(bst2.find(30));
    assert(bst2.find(70));

    bst2.remove(30);

    assert(!bst2.find(30));
    assert(bst1.find(30));
    assert(bst1.size() == 3);

    std::cout << "test_assignment_operator passed" << std::endl;
}

void test_destructor() {
    {
        BinarySearchTree<int> bst;

        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
    }

    std::cout << "test_destructor passed" << std::endl;
}

void test_constructor() {
    BinarySearchTree<int> bst;

    assert(bst.size() == 0);
    assert(bst.is_empty());
    assert(bst.height() == 0);

    std::cout << "test_constructor passed" << std::endl;
}

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;
    test_constructor();
    test_destructor();
    test_insert();
    test_remove();
    test_find();
    test_inorder();
    test_preorder();
    test_postorder();
    test_size();
    test_height();
    test_clear();
    test_is_empty();
    test_copy_constructor();
    test_assignment_operator();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
