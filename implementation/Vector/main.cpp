#include "Vector.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Vector<T>:
//
//   1. Vector()                        - конструктор по умолчанию
//   2. ~Vector()                       - деструктор
//   3. Vector(const Vector& other)     - конструктор копирования
//   4. operator=(const Vector& other)  - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. pop_back()                      - удалить с конца
//   7. operator[](int index)           - доступ по индексу
//   8. back()                          - последний элемент
//   9. insert(int pos, const T& val)   - вставить
//  10. erase(int pos)                  - удалить
//  11. swap(Vector& other)             - обменять содержимое
//  12. clear()                         - очистить
//  13. resize(int new_size)            - изменить размер
//  14. front()                         - первый элемент
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи


void test_push_back() {
    Vector<int> v;
    
    // Нормальный случай
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);
    
    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);
    
    std::cout << "test_push_back passed" << std::endl;
}

void test_pop_back(){
    Vector<int> v;

    v.push_back(12);
    v.pop_back();

    assert(v.size() == 0);

    v.push_back(18);
    v.push_back(27);
    v.push_back(36);

    v.pop_back();

    assert(v.size() == 2);
    assert(v.back() == 27);

    std::cout << "test_pop_back passed" << std::endl;
}

void test_operator_bracket(){
    Vector<int> v;

    v.push_back(4);
    v.push_back(8);

    assert(v[0] == 4);
    assert(v[1] == 8);

    v[1] = 16;

    assert(v[1] == 16);

    std::cout << "test_operator_bracket passed" << std::endl;
}

void test_back(){
    Vector<int> v;

    v.push_back(11);
    assert(v.back() == 11);

    v.push_back(22);
    assert(v.back() == 22);

    std::cout << "test_back passed" << std::endl;
}

void test_front(){
    Vector<int> v;

    v.push_back(9);
    assert(v.front() == 9);

    v.push_back(18);
    assert(v.front() == 9);

    std::cout << "test_front passed" << std::endl;
}

void test_insert(){
    Vector<int> v;

    v.insert(0, 10);

    assert(v.size() == 1);
    assert(v[0] == 10);

    v.insert(0, 5);

    assert(v.size() == 2);
    assert(v[0] == 5);
    assert(v[1] == 10);

    v.insert(1, 7);

    assert(v.size() == 3);
    assert(v[0] == 5);
    assert(v[1] == 7);
    assert(v[2] == 10);

    std::cout << "test_insert passed" << std::endl;
}

void test_erase(){
    Vector<int> v;

    v.push_back(8);
    v.erase(0);

    assert(v.size() == 0);

    v.push_back(12);
    v.push_back(24);
    v.push_back(36);

    v.erase(1);

    assert(v.size() == 2);
    assert(v[0] == 12);
    assert(v[1] == 36);

    std::cout << "test_erase passed" << std::endl;
}

void test_swap(){
    Vector<int> v1;
    Vector<int> v2;

    v1.push_back(3);
    v1.push_back(6);

    v2.push_back(15);

    v1.swap(v2);

    assert(v1.size() == 1);
    assert(v1[0] == 15);

    assert(v2.size() == 2);
    assert(v2[0] == 3);
    assert(v2[1] == 6);

    std::cout << "test_swap passed" << std::endl;
}

void test_clear(){
    Vector<int> v;

    v.push_back(13);
    v.push_back(26);

    assert(v.size() == 2);

    v.clear();

    assert(v.size() == 0);

    std::cout << "test_clear passed" << std::endl;
}

void test_resize(){
    Vector<int> v;

    v.resize(3);
    assert(v.size() == 3);

    v.resize(7);
    assert(v.size() == 7);

    v.resize(2);
    assert(v.size() == 2);

    v.resize(0);
    assert(v.size() == 0);

    std::cout << "test_resize passed" << std::endl;
}

void test_copy_constructor(){
    Vector<int> v;

    v.push_back(6);
    v.push_back(12);

    Vector<int> copy(v);

    assert(copy.size() == 2);
    assert(copy[0] == 6);
    assert(copy[1] == 12);

    copy[0] = 30;

    assert(v[0] == 6);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator(){
    Vector<int> v1;

    v1.push_back(4);
    v1.push_back(8);

    Vector<int> v2;

    v2 = v1;

    assert(v2.size() == 2);
    assert(v2[0] == 4);
    assert(v2[1] == 8);

    v2[0] = 20;

    assert(v1[0] == 4);

    std::cout << "test_assignment_operator passed" << std::endl;
}


int main() {
    std::cout << "Running Vector tests" << std::endl;
    
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_back();
    test_front();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
    test_resize();
    test_copy_constructor();
    test_assignment_operator();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}
