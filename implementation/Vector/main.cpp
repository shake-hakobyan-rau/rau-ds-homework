#include "Vector.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

void test_default_constructor() {
    Vector<int> v;

    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.empty());

    std::cout << "test_default_constructor passed\n";
}

void test_size_constructor() {
    Vector<int> v(3);

    assert(v.size() == 3);
    assert(v.capacity() == 3);
    assert(v[0] == 0);
    assert(v[1] == 0);
    assert(v[2] == 0);

    Vector<int> empty_vector(0);
    assert(empty_vector.empty());

    std::cout << "test_size_constructor passed\n";
}

void test_destructor() {
    {
        Vector<int> v;
        v.push_back(10);
        v.push_back(20);
        assert(v.size() == 2);
    } // Деструктор вызывается автоматически.

    std::cout << "test_destructor passed\n";
}

void test_copy_constructor() {
    Vector<int> original;
    original.push_back(10);
    original.push_back(20);

    Vector<int> copy(original);

    assert(copy.size() == 2);
    assert(copy[0] == 10);
    assert(copy[1] == 20);

    copy[0] = 99;
    assert(original[0] == 10);

    Vector<int> empty_copy(Vector<int>());
    assert(empty_copy.size() == 0);

    std::cout << "test_copy_constructor passed\n";
}

void test_assignment_operator() {
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);

    Vector<int> b;
    b.push_back(100);

    b = a;

    assert(b.size() == 2);
    assert(b[0] == 1);
    assert(b[1] == 2);

    b[0] = 50;
    assert(a[0] == 1);

    b = b; // Самоприсваивание
    assert(b[0] == 50);

    Vector<int> empty;
    b = empty;
    assert(b.empty());

    std::cout << "test_assignment_operator passed\n";
}

void test_push_back() {
    Vector<int> v;

    v.push_back(10);
    assert(v.size() == 1);
    assert(v[0] == 10);

    v.push_back(20);
    v.push_back(30);

    assert(v.size() == 3);
    assert(v[1] == 20);
    assert(v.back() == 30);
    assert(v.capacity() >= v.size());

    // Добавление элемента из самого вектора
    v.push_back(v[0]);
    assert(v[3] == 10);

    std::cout << "test_push_back passed\n";
}

void test_pop_back() {
    Vector<int> v;
    bool exception_caught = false;

    try {
        v.pop_back();
    } catch (const std::out_of_range&) {
        exception_caught = true;
    }

    assert(exception_caught);

    v.push_back(10);
    v.push_back(20);

    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 10);

    v.pop_back();
    assert(v.empty());

    std::cout << "test_pop_back passed\n";
}

void test_operator_bracket() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    assert(v[0] == 10);
    assert(v[1] == 20);

    v[0] = 99;
    assert(v[0] == 99);

    const Vector<int>& cv = v;
    assert(cv[0] == 99);

    std::cout << "test_operator_bracket passed\n";
}

void test_at() {
    Vector<int> v;
    bool exception_caught = false;

    try {
        v.at(0);
    } catch (const std::out_of_range&) {
        exception_caught = true;
    }

    assert(exception_caught);

    v.push_back(10);
    v.push_back(20);

    assert(v.at(0) == 10);
    assert(v.at(1) == 20);

    v.at(1) = 30;
    assert(v.at(1) == 30);

    exception_caught = false;

    try {
        v.at(2);
    } catch (const std::out_of_range&) {
        exception_caught = true;
    }

    assert(exception_caught);

    const Vector<int>& cv = v;
    assert(cv.at(0) == 10);

    std::cout << "test_at passed\n";
}

void test_front() {
    Vector<int> v;
    bool exception_caught = false;

    try {
        v.front();
    } catch (const std::out_of_range&) {
        exception_caught = true;
    }

    assert(exception_caught);

    v.push_back(10);
    v.push_back(20);

    assert(v.front() == 10);

    v.front() = 5;
    assert(v[0] == 5);

    const Vector<int>& cv = v;
    assert(cv.front() == 5);

    std::cout << "test_front passed\n";
}

void test_back() {
    Vector<int> v;
    bool exception_caught = false;

    try {
        v.back();
    } catch (const std::out_of_range&) {
        exception_caught = true;
    }

    assert(exception_caught);

    v.push_back(10);
    v.push_back(20);

    assert(v.back() == 20);

    v.back() = 99;
    assert(v[1] == 99);

    const Vector<int>& cv = v;
    assert(cv.back() == 99);

    std::cout << "test_back passed\n";
}

void test_size() {
    Vector<int> v;

    assert(v.size() == 0);

    v.push_back(10);
    assert(v.size() == 1);

    v.push_back(20);
    assert(v.size() == 2);

    v.pop_back();
    assert(v.size() == 1);

    std::cout << "test_size passed\n";
}

void test_capacity() {
    Vector<int> v;

    assert(v.capacity() == 0);

    v.push_back(10);
    assert(v.capacity() >= 1);

    v.push_back(20);
    assert(v.capacity() >= v.size());

    std::cout << "test_capacity passed\n";
}

void test_empty() {
    Vector<int> v;

    assert(v.empty());

    v.push_back(10);
    assert(!v.empty());

    v.pop_back();
    assert(v.empty());

    std::cout << "test_empty passed\n";
}

void test_reserve() {
    Vector<int> v;

    v.reserve(10);

    assert(v.capacity() >= 10);
    assert(v.size() == 0);

    v.push_back(10);
    v.push_back(20);

    const auto old_size = v.size();
    v.reserve(20);

    assert(v.capacity() >= 20);
    assert(v.size() == old_size);
    assert(v[0] == 10);
    assert(v[1] == 20);

    // Запрос меньшей ёмкости ничего не меняет.
    const auto old_capacity = v.capacity();
    v.reserve(1);

    assert(v.capacity() == old_capacity);

    std::cout << "test_reserve passed\n";
}

void test_clear() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    const auto old_capacity = v.capacity();

    v.clear();

    assert(v.empty());
    assert(v.size() == 0);
    assert(v.capacity() == old_capacity);

    v.push_back(30);
    assert(v.size() == 1);
    assert(v[0] == 30);

    std::cout << "test_clear passed\n";
}

void test_begin() {
    Vector<int> v;

    assert(v.begin() == v.end());

    v.push_back(10);
    v.push_back(20);

    assert(*v.begin() == 10);

    *v.begin() = 99;
    assert(v[0] == 99);

    const Vector<int>& cv = v;
    assert(*cv.begin() == 99);

    std::cout << "test_begin passed\n";
}

void test_end() {
    Vector<int> v;

    assert(v.begin() == v.end());

    v.push_back(10);
    v.push_back(20);

    assert(v.end() - v.begin() == 2);
    assert(*(v.end() - 1) == 20);

    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }

    assert(sum == 30);

    const Vector<int>& cv = v;
    assert(cv.end() - cv.begin() == 2);

    std::cout << "test_end passed\n";
}

int main() {
    std::cout << "Running Vector tests...\n\n";

    test_default_constructor();
    test_size_constructor();
    test_destructor();
    test_copy_constructor();
    test_assignment_operator();
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_at();
    test_front();
    test_back();
    test_size();
    test_capacity();
    test_empty();
    test_reserve();
    test_clear();
    test_begin();
    test_end();

    std::cout << "\nAll Vector tests passed!\n";

    return 0;
}
