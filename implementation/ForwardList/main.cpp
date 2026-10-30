#include "ForwardList.h"
#include <cassert>
#include <iostream>

// Реализуйте методы ForwardList<T>:
//   1. ForwardList()                   - конструктор
//   2. ~ForwardList()                  - деструктор
//   3. ForwardList(const &)            - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_front(const T&)            - добавить в начало
//   6. pop_front()                     - удалить с начала
//   7. front()                         - первый элемент
//   8. insert_after(Node*, const T&)   - вставить после узла
//   9. erase_after(Node*)              - удалить после узла
//  10. clear()                         - очистить
//  11. reverse()                       - развернуть
//  12. size()                          - размер
//  13. empty()                         - пусто ли
//  14. begin()                         - начало списка

void test_push_front() {
    ForwardList<int> list;
    
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);
    
    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);
    
    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_front(){
    ForwardList<int> list;

    list.push_front(5);
    list.pop_front();

    assert(list.size() == 0);
    assert(list.empty());

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.pop_front();

    assert(list.size() == 2);
    assert(list.front() == 20);

    std::cout << "test_pop_front passed" << std::endl;
}

void test_front(){
    ForwardList<int> list;

    list.push_front(7);
    assert(list.front() == 7);

    list.push_front(14);
    assert(list.front() == 14);

    std::cout << "test_front passed" << std::endl;
}

void test_insert_after(){
    ForwardList<int> list;

    list.push_front(10);

    auto node = list.begin();

    list.insert_after(node, 20);

    assert(list.size() == 2);

    list.insert_after(node, 15);

    assert(list.size() == 3);

    std::cout << "test_insert_after passed" << std::endl;
}


void test_erase_after(){
    ForwardList<int> list;

    list.push_front(30);
    list.push_front(20);
    list.push_front(10);

    auto node = list.begin();

    list.erase_after(node);

    assert(list.size() == 2);

    list.erase_after(node);

    assert(list.size() == 1);

    std::cout << "test_erase_after passed" << std::endl;
}


void test_clear(){
    ForwardList<int> list;

    list.push_front(4);
    list.push_front(8);
    list.push_front(12);

    assert(list.size() == 3);

    list.clear();

    assert(list.size() == 0);
    assert(list.empty());

    std::cout << "test_clear passed" << std::endl;
}


void test_reverse(){
    ForwardList<int> list;

    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    assert(list.front() == 1);

    list.reverse();

    assert(list.front() == 3);

    std::cout << "test_reverse passed" << std::endl;
}


void test_size(){
    ForwardList<int> list;

    assert(list.size() == 0);

    list.push_front(6);
    assert(list.size() == 1);

    list.push_front(12);
    assert(list.size() == 2);

    std::cout << "test_size passed" << std::endl;
}


void test_empty(){
    ForwardList<int> list;

    assert(list.empty());

    list.push_front(9);

    assert(!list.empty());

    list.pop_front();

    assert(list.empty());

    std::cout << "test_empty passed" << std::endl;
}


void test_begin(){
    ForwardList<int> list;

    list.push_front(11);

    auto node = list.begin();

    assert(node != nullptr);

    std::cout << "test_begin passed" << std::endl;
}


void test_copy_constructor(){
    ForwardList<int> list;

    list.push_front(10);
    list.push_front(20);

    ForwardList<int> copy(list);

    assert(copy.size() == 2);
    assert(copy.front() == 20);

    copy.pop_front();

    assert(copy.size() == 1);
    assert(list.size() == 2);

    std::cout << "test_copy_constructor passed" << std::endl;
}


void test_assignment_operator(){
    ForwardList<int> list1;

    list1.push_front(5);
    list1.push_front(15);

    ForwardList<int> list2;

    list2 = list1;

    assert(list2.size() == 2);
    assert(list2.front() == 15);

    list2.pop_front();

    assert(list2.size() == 1);
    assert(list1.size() == 2);

    std::cout << "test_assignment_operator passed" << std::endl;
}


int main() {
    std::cout << "Running ForwardList tests" << std::endl;
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size();
    test_empty();
    test_begin();
    test_copy_constructor();
    test_assignment_operator();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
